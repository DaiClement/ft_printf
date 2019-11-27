/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:40:58 by cdai              #+#    #+#             */
/*   Updated: 2019/11/27 10:14:45 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_x_lower(t_flag_data *data, va_list *ap, int *result)
{
	int				i;
	unsigned int	d;

	d = va_arg(*ap, unsigned int);
	i = 0;
	if (!d && data->dot && !data->precision)
	{
		if (!data->minus)
			*result = *result + ft_putspace(data->width);
		return ;
	}
	if (!data->minus)
		*result = *result + ft_putspace(data->width - ft_count_pow(d, 16));
	i = 0;
	while (i++ < (int)(data->precision - ft_count_pow(d, 16)))
	{
		ft_putchar_fd('0', 1);
		*result = *result + 1;
	}
	*result = *result + ft_putnbr_hex_lower(d, 1);
	if (data->minus)
		*result = *result + ft_putspace(data->width - ft_count_pow(d, 16));
}

void	ft_x_upper(t_flag_data *data, va_list *ap, int *result)
{
	int				i;
	unsigned int	d;

	d = va_arg(*ap, unsigned int);
	i = 0;
	if (!d && data->dot && !data->precision)
	{
		if (!data->minus)
			*result = *result + ft_putspace(data->width);
		return ;
	}
	if (!data->minus)
		*result = *result + ft_putspace(data->width - ft_count_pow(d, 16));
	i = 0;
	while (i++ < (int)(data->precision - ft_count_pow(d, 16)))
	{
		ft_putchar_fd('0', 1);
		*result = *result + 1;
	}
	*result = *result + ft_putnbr_hex_upper(d, 1);
	if (data->minus)
		*result = *result + ft_putspace(data->width - ft_count_pow(d, 16));
}

void	ft_p(t_flag_data *data, va_list *ap, int *result)
{
	int					i;
	unsigned long int	d;

	d = va_arg(*ap, unsigned long int);
	i = 0;
	if (!d && data->dot && !data->precision)
	{
		ft_putstr_fd("0x", 1);
		*result = *result + 2;
		if (!data->minus)
			*result = *result + ft_putspace(data->width);
		return ;
	}
	if (!data->minus)
		*result = *result + ft_putspace(data->width - ft_count_pow(d, 16) - 2);
	i = 0;
	ft_putstr_fd("0x", 1);
	*result = *result + 2;
	while (i++ < (int)(data->precision - ft_count_pow(d, 16) - 2))
	{
		ft_putchar_fd('0', 1);
		*result = *result + 1;
	}
	*result = *result + ft_putnbr_hex_long(d, 1);
	if (data->minus)
		*result = *result + ft_putspace(data->width - ft_count_pow(d, 16));
}
