/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:58:59 by cdai              #+#    #+#             */
/*   Updated: 2019/11/22 17:29:55 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	ft_i(t_flag_data *data, va_list *ap)
{
	int	i;
	int d;
	char *str_nbr;

	i = 0;
	d = 0;
	d = va_arg(*ap, int);
	str_nbr = ft_itoa(d);
	if (!data->minus)
		while (i++ < (int)(data->width - ft_strlen(str_nbr)))
			ft_putchar_fd(' ', 1);
	if (!d && data->dot && !data->precision)
	{
		ft_putchar_fd(' ', 1);
		return ;
	}
	if (d < 0)
		ft_putchar_fd(*str_nbr, 1);
	i = 0;
		while (i++ < (int)(data->precision - ft_strlen(str_nbr)))
			ft_putchar_fd('0', 1);
	if (d < 0)	
		ft_putstr_fd(str_nbr + 1, 1);
	else
		ft_putstr_fd(str_nbr, 1);
	if (data->minus)
		while (i++ < (int)(data->width - ft_strlen(str_nbr)))
			ft_putchar_fd(' ', 1);
	
}

void	ft_c(t_flag_data *data, va_list *ap)
{
	char	c;
	int i;

	i = 0;
	if (!data->minus)
		while (i++ < (data->width - 1))
			ft_putchar_fd(' ', 1);
	c = va_arg(*ap, int);
	ft_putchar_fd(c, 1);
	if (data->minus)
		while (i++ < (data->width - 1))
			ft_putchar_fd(' ', 1);
}

void	ft_s(t_flag_data *data, va_list *ap)
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
		while (i++ < data->width - (int)ft_strlen(s))
			ft_putchar_fd(' ', 1);
	if (data->width < data->precision && !data->width)
		data->width = data->precision;
	while (*(s + j) && j < data->width)
		ft_putchar_fd(*(s + j++), 1);
	if (data->minus && (data->width > data->precision || data->width != data->precision))
		while (j++ < (data->width))
			ft_putchar_fd(' ', 1);
}

int ft_check_conversion(const char *fmt)
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

void ft_print(t_flag_data *data, const char *fmt, va_list *ap)
{
	if (*fmt == '%')
		ft_putchar_fd('%', 1);
	else if (*fmt == 'c')
		ft_c(data, ap);
	else if (*fmt == 's')
		ft_s(data, ap);
	else if (*fmt == 'd' || *fmt == 'i')
		ft_i(data, ap);
/*	else if (*fmt == 'u')
		ft_u(data, ap);
	else if (*fmt == 'p')
		ft_p(data, ap);
	else if (*fmt == 'x')
		ft_x(data, ap);
	else if (*fmt == 'X')
		ft_X(data, ap);
*/}
