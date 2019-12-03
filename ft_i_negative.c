/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_negative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 10:46:05 by cdai              #+#    #+#             */
/*   Updated: 2019/12/03 15:01:45 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putspace_after_int_n(t_flag_data *data, unsigned int d)
{
	int len;

	len = ft_count_pow(d, 10);
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
			return (ft_putlchar(data->width - data->precision - 1, ' '));
		else
			return (ft_putlchar(data->width - len - 1, ' '));
	}
	return (0);
}

static int	ft_putzero_int_n(t_flag_data *data, unsigned int d)
{
	int len;

	len = ft_count_pow(d, 10);
	if (data->precision > len)    if (data->precision > len)
		return (ft_putlchar(data->precision - len, '0'));
	if (data->zero_flag && (!data->dot || data->precision > len))
		return (ft_putlchar(data->width - len - 1, '0'));
	return (0);
}

static int	ft_putspace_before_int_n(t_flag_data *data, unsigned int d)
{
	int len;

	len = ft_count_pow(d, 10);
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
			return (ft_putlchar(data->width - data->precision - 1, ' '));
		else
			return (ft_putlchar(data->width - len - 1, ' '));
	}
	else if (!data->zero_flag)
		return (ft_putlchar(data->width - len - 1, ' '));
	return (0);
}

void		ft_i_negative(t_flag_data *data, unsigned int d, int *result)
{
	if (!d && data->dot && !data->precision)
	{
		if (data->width < 0)
			data->width = -data->width;
		*result = *result + ft_putlchar(data->width, ' ');
		return ;
	}
	*result = *result + ft_putspace_before_int_n(data, d);
	ft_putchar_fd('-', 1);
	*result = *result + 1;
	*result = *result + ft_putzero_int_n(data, d);
	*result = *result + ft_putlnbr(d, 1);
	*result = *result + ft_putspace_after_int_n(data, d);
}
