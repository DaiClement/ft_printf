/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:58:59 by cdai              #+#    #+#             */
/*   Updated: 2019/11/26 09:27:29 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_i_positive(t_flag_data *data, unsigned int d, int *result)
{
	int		i;

	i = 0;
	if (!d && data->dot && !data->precision)
	{
		if (!data->minus)
			*result = *result + ft_putspace(data->width);
		return ;
	}
	if (!data->minus)
		*result = *result + ft_putspace(data->width - ft_count_pow(d, 10));
	i = 0;
	while (i++ < (int)(data->precision - ft_count_pow(d, 10)))
	{
		ft_putchar_fd('0', 1);
		*result = *result + 1;
	}
	*result = *result + ft_putnbr_printf(d, 1);
	if (data->minus)
		*result = *result + ft_putspace(data->width - ft_count_pow(d, 10));
}

void	ft_i_negative(t_flag_data *data, unsigned int d, int *result)
{
	int		i;

	i = 0;
	if (!d && data->dot && !data->precision && !data->minus)
	{
		*result = *result + ft_putspace(data->width);
		return ;
	}
	if (!data->minus)
		*result = *result + ft_putspace(data->width - ft_count_pow(d, 10) - 1);
	ft_putchar_fd('-', 1);
	*result = *result + 1;
	i = 0;
	while (i++ < (int)(data->precision - ft_count_pow(d, 10)))
	{
		ft_putchar_fd('0', 1);
		*result = *result + 1;
	}
	*result = *result + ft_putnbr_printf(d, 1);
	if (data->minus)
		*result = *result + ft_putspace(data->width - ft_count_pow(d, 10) - 1);
}

int		ft_putspace(int n)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_putchar_fd(' ', 1);
	return (i);
}

void	ft_u(t_flag_data *data, va_list *ap, int *result)
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
		*result = *result + ft_putspace(data->width - ft_count_pow(d, 10));
	i = 0;
	while (i++ < (int)(data->precision - ft_count_pow(d, 10)))
	{
		ft_putchar_fd('0', 1);
		*result = *result + 1;
	}
	*result = *result + ft_putnbr_printf(d, 1);
	if (data->minus)
		*result = *result + ft_putspace(data->width - ft_count_pow(d, 10));
}
