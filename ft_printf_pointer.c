/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 11:06:36 by cdai              #+#    #+#             */
/*   Updated: 2019/12/02 12:17:33 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putspace_after_p(t_flag_data *data, unsigned long int d)
{
	int len;

	len = 2;
	len += ft_count_pow(d, 16);
	if (data->width < 0)
	{
		data->minus = 1;
		data->width = -data->width;
	}
	if (data->minus == 1)
		return (ft_putlchar(data->width - len, ' '));
	return (0);
}

static int	ft_putspace_before_p(t_flag_data *data, unsigned long int d)
{
	int len;

	len = 2;
	len += ft_count_pow(d, 16);
	if (data->minus)
		return (0);
	if (!data->zero_flag || data->dot)
	{
		if (data->precision > len)
			return (ft_putlchar(data->width - data->precision, ' '));
		else
			return (ft_putlchar(data->width - len, ' '));
	}
	return (0);
}

void		ft_printf_pointer(t_flag_data *data, va_list *ap, int *result)
{
	int					i;
	unsigned long int	d;

	d = va_arg(*ap, unsigned long int);
	if (!d && data->dot && !data->precision)
	{
		if (data->width < 0)
			data->width = -data->width;
		ft_putstr_fd("0x", 1);
		*result = *result + 2;
		*result = *result + ft_putlchar(data->width, ' ');
		return ;
	}
	*result = *result + ft_putspace_before_p(data, d);
	ft_putstr_fd("0x", 1);
	*result = *result + 2;
	*result = *result + ft_putlnbr_base(d, 1, "0123456789abcdef");
	*result = *result + ft_putspace_after_p(data, d);
}
