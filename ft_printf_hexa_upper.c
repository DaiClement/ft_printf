/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_upper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:01:08 by cdai              #+#    #+#             */
/*   Updated: 2019/12/03 14:34:06 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putspace_after_x_upper(t_flag_data *data, unsigned long int d)
{
	int len;

	len = ft_count_pow(d, 16);
	if (data->precision == data->width && data->width < 0)
		data->precision = 0;
	if (data->width < 0)
	{
		data->minus = 1;
		data->width = -data->width;
	}
	if (data->minus)
	{
		if (data->precision && data->precision > len)
			return (ft_putlchar(data->width - data->precision, ' '));
		else
			return (ft_putlchar(data->width - len, ' '));
	}
	return (0);
}

static int	ft_putzero_x_upper(t_flag_data *data, unsigned long int d)
{
	int len;

	len = ft_count_pow(d, 16);
	if (data->precision > len)
		return (ft_putlchar(data->precision - len, '0'));
	if (data->zero_flag && (!data->dot || data->precision > len))
		return (ft_putlchar(data->width - len, '0'));
	return (0);
}

static int	ft_putspace_before_x_upper(t_flag_data *data, unsigned long int d)
{
	int len;

	len = ft_count_pow(d, 16);
	if (data->minus)
		return (0);
	if (data->precision < 0)
	{
		data->dot = 0;
		data->precision = ft_count_pow(d, 16);
	}
	if (data->dot)
	{
		if (data->precision > len)
			return (ft_putlchar(data->width - data->precision, ' '));
		else
			return (ft_putlchar(data->width - len, ' '));
	}
	else if (!data->zero_flag)
		return (ft_putlchar(data->width - len, ' '));
	return (0);
}

void		ft_printf_hexa_upper(t_flag_data *data, va_list *ap, int *result)
{
	int					i;
	unsigned long int	d;

	d = va_arg(*ap, unsigned int);
	if (!d && data->dot && !data->precision)
	{
		if (data->width < 0)
			data->width = -data->width;
		*result = *result + ft_putlchar(data->width, ' ');
		return ;
	}
	*result = *result + ft_putspace_before_x_upper(data, d);
	*result = *result + ft_putzero_x_upper(data, d);
	*result = *result + ft_putlnbr_base(d, 1, "0123456789ABCDEF");
	*result = *result + ft_putspace_after_x_upper(data, d);
}
