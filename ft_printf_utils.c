/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:58:59 by cdai              #+#    #+#             */
/*   Updated: 2019/11/22 14:59:00 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

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
	//printf("valeur de ft_strlen(s): %d\n",(int)ft_strlen(s));
	//printf("valeur de data->width: %d\n",data->width);
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
/*	else if (*fmt == 'p')
		ft_p(data, ap);
	else if (*fmt == 'd' || *fmt == 'i')
		ft_i(data, ap);
	else if (*fmt == 'u')
		ft_u(data, ap);
	else if (*fmt == 'x')
		ft_x(data, ap);
	else if (*fmt == 'X')
		ft_X(data, ap);
*/}
