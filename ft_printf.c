/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:27:46 by cdai              #+#    #+#             */
/*   Updated: 2019/12/03 14:44:01 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			ft_width_precision(t_flag_data *data, const char *fmt,
	va_list *ap)
{
	int		i;
	char	c;
	int		temp;

	i = 0;
	temp = 0;
	c = *(fmt + i);
	while (c && (c == '*' || ft_isdigit(c)))
	{
		if (c == '*')
			temp = va_arg(*ap, int);
		else
			temp = ft_atoi_printf(fmt, &i);
		i++;
		c = *(fmt + i);
	}
	if (data->dot)
		data->precision = temp;
	else
		data->width = temp;
	i--;
	return (i);
}

static int			ft_minus_zero(t_flag_data *data, const char *fmt)
{
	int i;

	i = 0;
	while (*(fmt + i) == '-' || *(fmt + i) == '0')
	{
		if (*(fmt + i) == '-')
			data->minus = 1;
		else
			data->zero_flag = 1;
		i++;
	}
	i--;
	return (i);
}

static void			ft_init_data(t_flag_data *data)
{
	data->minus = 0;
	data->zero_flag = 0;
	data->width = 0;
	data->dot = 0;
	data->precision = 0;
}

static int			ft_print_arg(const char *fmt, va_list *ap, int *result)
{
	t_flag_data	data;
	int			i;

	i = 1;
	ft_init_data(&data);
	while (!ft_check_conversion(fmt + i) && *(fmt + i))
	{
		if (*(fmt + i) == '-' || (*(fmt + i) == '0' && !data.dot))
			i = i + ft_minus_zero(&data, fmt + i);
		else if (*(fmt + i) == '*' || ft_isdigit(*(fmt + i)))
			i = i + ft_width_precision(&data, fmt + i, ap);
		else if ((*(fmt + i)) == '.')
			data.dot = 1;
		i++;
	}
	ft_print(&data, fmt + i, ap, result);
	return (i);
}

int					ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		result;

	i = 0;
	result = 0;
	va_start(ap, fmt);
	while (*(fmt + i))
	{
		if (*(fmt + i) == '%')
			i = i + ft_print_arg(fmt + i, &ap, &result);
		else
		{
			result++;
			ft_putchar_fd(*(fmt + i), 1);
		}
		i++;
	}
	va_end(ap);
	return (result);
}
