/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:58:59 by cdai              #+#    #+#             */
/*   Updated: 2019/11/25 16:56:52 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_i(t_flag_data *data, va_list *ap, int *result)
{
	long	d;
	char	*str_nbr;

	d = 0;
	d = va_arg(*ap, int);
	if (d >= 0)
		ft_i_positive(data, d, result);
	else
	{
		if (d == -2147483648)
			str_nbr = "2147483648";
		else
			str_nbr = ft_itoa((int)(-d));
		ft_i_negative(data, str_nbr, result);
	}
}

void		ft_c(t_flag_data *data, va_list *ap, int *result)
{
	char	c;
	int		i;

	i = 0;
	if (!data->minus)
		*result = *result + ft_putspace(data->width - 1);
	c = va_arg(*ap, int);
	ft_putchar_fd(c, 1);
	*result = *result + 1;
	if (data->minus)
		*result = *result + ft_putspace(data->width - 1);
}

void		ft_s(t_flag_data *data, va_list *ap, int *result)
{
	char	*s;
	int		i;
	int		j;

	i = 0;
	j = 0;
	s = va_arg(*ap, char*);
	if ((data->width == 0 && !data->dot) ||
			(data->width < (int)ft_strlen(s) && !data->dot))
		data->width = ft_strlen(s);
	if (data->precision == 0 && !data->dot)
		data->precision = ft_strlen(s);
	if (!data->minus)
		*result = *result + ft_putspace(data->width - (int)ft_strlen(s));
	if (data->width < data->precision && !data->width)
		data->width = data->precision;
	while (*(s + j) && j < data->width)
	{
		ft_putchar_fd(*(s + j++), 1);
		*result = *result + 1;
	}
	if (data->minus && (data->width > data->precision ||
				data->width != data->precision))
		*result = *result + ft_putspace(data->width - (int)ft_strlen(s));
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
	/*	
	else if (*fmt == 'p')
		ft_p(data, ap);
	else if (*fmt == 'x')
		ft_x(data, ap);
	else if (*fmt == 'X')
		ft_X(data, ap);
	 */
}
