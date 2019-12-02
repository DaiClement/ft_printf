/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:58:59 by cdai              #+#    #+#             */
/*   Updated: 2019/12/02 15:03:10 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putlchar(int n, char c)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_putchar_fd(c, 1);
	return (i);
}

static void	ft_double_percent(t_flag_data *data, int *result)
{
	if (data->width < 0)
	{
		data->minus = 1;
		data->width = -data->width;
	}
	if (!data->minus)
		*result = *result + ft_putlchar(data->width - 1, ' ');
	ft_putchar_fd('%', 1);
	*result = *result + 1;
	if (data->minus)
		*result = *result + ft_putlchar(data->width - 1, ' ');
}

int			ft_check_conversion(const char *fmt)
{
	const char	*conversion_tab = "cspdiuxX%";

	while (*conversion_tab)
	{
		if (*conversion_tab == *fmt)
			return (1);
		conversion_tab++;
	}
	return (0);
}

void		ft_print(t_flag_data *data, const char *fmt, va_list *ap,
	int *result)
{
	if (*fmt == '%')
		ft_double_percent(data, result);
	else if (*fmt == 'c')
		ft_printf_char(data, ap, result);
	else if (*fmt == 's')
		ft_printf_string(data, ap, result);
	else if (*fmt == 'd' || *fmt == 'i')
		ft_printf_int(data, ap, result);
	else if (*fmt == 'u')
		ft_printf_unsigned(data, ap, result);
	else if (*fmt == 'x')
		ft_printf_hexa_lower(data, ap, result);
	else if (*fmt == 'X')
		ft_printf_hexa_upper(data, ap, result);
	else if (*fmt == 'p')
		ft_printf_pointer(data, ap, result);
}
