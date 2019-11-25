/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 15:58:59 by cdai              #+#    #+#             */
/*   Updated: 2019/11/25 17:39:55 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_i_positive(t_flag_data *data, long d, int *result)
{
	int		i;
	char	*str_nbr;

	i = 0;
	str_nbr = ft_itoa((int)d);
	if (!d && data->dot && !data->precision)
	{
		if (!data->minus)
			*result = *result + ft_putspace(data->width);
		return ;
	}
	if (!data->minus)
		*result = *result + ft_putspace(data->width - ft_strlen(str_nbr));
	i = 0;
	while (i++ < (int)(data->precision - ft_strlen(str_nbr)))
	{
		ft_putchar_fd('0', 1);
		*result = *result + 1;
	}
	ft_putstr_fd(str_nbr, 1);
	*result = *result + ft_strlen(str_nbr);
	if (data->minus)
		*result = *result + ft_putspace(data->width - ft_strlen(str_nbr));
	free(str_nbr);
}

void	ft_i_negative(t_flag_data *data, char *str_nbr, int *result)
{
	int		i;

	i = 0;
	if (!*str_nbr && data->dot && !data->precision && !data->minus)
	{
		*result = *result + ft_putspace(data->width);
		return ;
	}
	if (!data->minus)
		*result = *result + ft_putspace(data->width - ft_strlen(str_nbr) - 1);
	ft_putchar_fd('-', 1);
	*result = *result + 1;
	i = 0;
	while (i++ < (int)(data->precision - ft_strlen(str_nbr)))
	{
		ft_putchar_fd('0', 1);
		*result = *result + 1;
	}
	ft_putstr_fd(str_nbr, 1);
	*result = *result + ft_strlen(str_nbr);
	if (data->minus)
		*result = *result + ft_putspace(data->width - ft_strlen(str_nbr) - 1);
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
	char			*str_nbr;
	unsigned int	d;

	d = va_arg(*ap, unsigned int);
	i = 0;
	str_nbr = ft_itoa_long((long)d);
	if (!d && data->dot && !data->precision)
	{
		if (!data->minus)
			*result = *result + ft_putspace(data->width);
		return ;
	}
	if (!data->minus)
		*result = *result + ft_putspace(data->width - ft_strlen(str_nbr));
	i = 0;
	while (i++ < (int)(data->precision - ft_strlen(str_nbr)))
	{
		ft_putchar_fd('0', 1);
		*result = *result + 1;
	}
	ft_putstr_fd(str_nbr, 1);
	*result = *result + ft_strlen(str_nbr);
	if (data->minus)
		*result = *result + ft_putspace(data->width - ft_strlen(str_nbr));
	free(str_nbr);
}
