/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 11:46:40 by cdai              #+#    #+#             */
/*   Updated: 2019/12/02 10:34:30 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_char(t_flag_data *data, va_list *ap, int *result)
{
	char	c;

	if (!data->minus)
		*result = *result + ft_putlchar(data->width - 1, ' ');
	c = va_arg(*ap, int);
	ft_putchar_fd(c, 1);
	*result = *result + 1;
	if (data->width < 0)
	{
		data->minus = 1;
		data->width = -data->width;
	}
	if (data->minus)
		*result = *result + ft_putlchar(data->width - 1, ' ');
}
