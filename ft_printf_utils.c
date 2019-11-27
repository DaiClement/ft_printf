/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:58:59 by cdai              #+#    #+#             */
/*   Updated: 2019/11/27 12:40:38 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_c(t_flag_data *data, va_list *ap, int *result)
{
	char	c;
	int		i;

	i = 0;
	if (!data->minus)
		*result = *result + ft_putspace(data->width - 1);
	c = va_arg(*ap, int);
	ft_putchar_fd(c, 1);
	*result = *result + 1;
	if (data->width < 0)
	{
		data->minus = 1;
		data->width = -data->width;
	}
	if (data->minus)
		*result = *result + ft_putspace(data->width - 1);
}

int		ft_check_conversion(const char *fmt)
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

void	ft_print(t_flag_data *data, const char *fmt, va_list *ap, int *result)
{
	if (*fmt == '%')
	{
		ft_putchar_fd('%', 1);
		*result = *result + 1;
	}
	else if (*fmt == 'c')
		ft_c(data, ap, result);
	else if (*fmt == 's')
		ft_s(data, ap, result);
	else if (*fmt == 'd' || *fmt == 'i')
		ft_i(data, ap, result);
	else if (*fmt == 'u')
		ft_u(data, ap, result);
	else if (*fmt == 'x')
		ft_x_lower(data, ap, result);
	else if (*fmt == 'X')
		ft_x_upper(data, ap, result);
	else if (*fmt == 'p')
		ft_p(data, ap, result);
}
