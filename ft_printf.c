/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:27:46 by cdai              #+#    #+#             */
/*   Updated: 2019/11/21 14:58:01 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int			ft_width(t_flag_data *data, const char *fmt, va_list *ap)
{
	int		i;
	char	c;

	i = 0;
	c = *(fmt + i);
	while (c == '*' || (c >= '0' &&  c <= '9'))
	{
		c = *(fmt + i);
		if (c == '*')
			data->width = va_arg(*ap, int);
		else
			data->width = ft_atoi_printf(fmt, &i);
		i++;
	}	
	return (i);
}

static int			ft_minus_zero(t_flag_data *data, const char *fmt)
{
	int i;

	i = 0;
	while (*(fmt) == '-' || *(fmt) == '0')
	{
		if (*(fmt + i) == '-')
			data->minus = 1;
		else
			data->zero_flag = 1;
		i++;
	}
	return (i);
}

static t_flag_data	*ft_init_data(void)
{
	t_flag_data	*data;

	if (!(data = malloc(sizeof(*data))))
		return (NULL);
	data->minus = 0;
	data->zero_flag = 0;
	data->width = 0;
	data->precision = 0;
	return (data);
}

static int			ft_print_arg(const char *fmt, va_list *ap)
{
	t_flag_data	*data;
	int			i;
	
	i = 1;
	if (!(data = ft_init_data()))
		return (-1);
	if (*(fmt + i) == '-' || *(fmt + i) == '0')
		i = i + ft_minus_zero(data, fmt + i);
	if (*(fmt + i) == '*' || (*(fmt + i) >= '0' &&  *(fmt + i) <= '9'))
		i = i + ft_width(data, fmt + i, ap);
//	if (*(fmt + i) == '.')
//		ft_
	free(data);
	return (i);
}

int					ft_printf(const char *fmt, ...)
{
	va_list	ap;
/*
	int		d;
	char	c;
	char	*s;
*/
	int		i;
	int		temp;

	i = 0;	
	va_start(ap, fmt);
	while (*(fmt+i))
	{
		if (*(fmt + i) == '%')
		{
			if ((temp = ft_print_arg(fmt + i, &ap)) < 0)
			{
				va_end(ap);
				return (-1);
			}			
			i = i + temp;
		}
		else
			ft_putchar_fd(*(fmt + i), 1);

// le i++; est en bas.

/*
		switch(*(fmt+i))
		{
			case 's':
				s = va_arg(ap, char *);
				printf("string %s\n", s);
				break;
			case 'd':
				d = va_arg(ap, int);
				printf("int %d\n", d);
				break;
			case'c':
				//Note:char is promoted to int.
				c = va_arg(ap, int);
				printf("char %c\n", c);
				break;
			default:
				printf("default %c\n", *(fmt+i));
				break;
		}
*/	
		i++;
	}	
	va_end(ap);
	return (0);
}
