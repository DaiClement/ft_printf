/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 12:28:54 by cdai              #+#    #+#             */
/*   Updated: 2019/12/02 10:40:08 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putspace_after_s(t_flag_data *data, char *s)
{
	int len;

	len = (int)ft_strlen(s);
	if (data->width < 0)
	{
		data->minus = 1;
		data->width = -data->width;
	}
	if (data->minus)
	{
		if (data->precision >= len || !data->dot)
			return (ft_putlchar(data->width - len, ' '));
		else
			return (ft_putlchar(data->width - data->precision, ' '));
	}
	return (0);
}

static int	ft_put_string(t_flag_data *data, char *s)
{
	int	j;
	int len;

	j = 0;
	len = (int)ft_strlen(s);
	if (!data->precision && !data->dot)
	{
		while (*(s + j) && (j < len))
		{
			ft_putchar_fd(*(s + j), 1);
			j++;
		}
	}
	else
	{
		while (*(s + j) && (j < data->precision))
		{
			ft_putchar_fd(*(s + j), 1);
			j++;
		}
	}
	return (j);
}

static int	ft_putspace_before_s(t_flag_data *data, char *s)
{
	int len;

	len = (int)ft_strlen(s);
	if (data->minus)
		return (0);
	else
	{
		if (!data->width && !data->precision && !data->dot)
		{
			data->width = len;
			data->precision = len;
		}
		else if (!data->precision && !data->dot)
			data->precision = len;
	}
	if (data->width > len && data->precision >= len)
		return (ft_putlchar(data->width - len, ' '));
	else
		return (ft_putlchar(data->width - data->precision, ' '));
	return (0);
}

static void	ft_null_pointer_s(t_flag_data *data, int *result)
{
	char	*s;

	s = "(null)";
	*result = *result + ft_putspace_before_s(data, s);
	*result = *result + ft_put_string(data, s);
	*result = *result + ft_putspace_after_s(data, s);
}

void		ft_printf_string(t_flag_data *data, va_list *ap, int *result)
{
	char	*s;

	s = va_arg(*ap, char*);
	if (!s)
		return (ft_null_pointer_s(data, result));
	*result = *result + ft_putspace_before_s(data, s);
	*result = *result + ft_put_string(data, s);
	*result = *result + ft_putspace_after_s(data, s);
}
