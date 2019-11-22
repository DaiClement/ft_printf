/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:27:46 by cdai              #+#    #+#             */
/*   Updated: 2019/11/22 12:41:00 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static int			ft_width_precision(t_flag_data *data, const char *fmt, va_list *ap)
{
	int		i;
	char	c;
	int		temp;

	i = 0;
	temp = 0;
	c = *(fmt + i);
	while (c && (c == '*' || ft_isdigit(c)))
	{
	//	printf("in while\n");
		if (c == '*')
			temp = va_arg(*ap, int);
		else
			temp = ft_atoi_printf(fmt, &i);
		i++;
		c = *(fmt + i);
	//printf("valeur de c in ft_width_precision: %i\n", c);
	}
	if (data->dot)
		data->precision = temp;
	else
		data->width = temp;
	i--;
	//printf("\n\nminus : %i\n", data->minus);
	//printf("temp : %i\n", temp);
	//printf("width : %i\n", data->width);
	//printf("precision : %i\n", data->precision);
	//printf("dot : %i\n\n\n", data->dot);
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

static t_flag_data	*ft_init_data(void)
{
	t_flag_data	*data;

	if (!(data = malloc(sizeof(*data))))
		return (NULL);
	data->minus = 0;
	data->zero_flag = 0;
	data->width = 0;
	data->dot = 0;
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
	while (!ft_check_conversion(fmt + i) && *(fmt + i))
	{
		if (*(fmt + i) == '-' || *(fmt + i) == '0')
			i = i + ft_minus_zero(data, fmt + i);
		else if (*(fmt + i) == '*' || ft_isdigit(*(fmt + i)))
			i = i + ft_width_precision(data, fmt + i, ap);
		else if ((*(fmt + i)) == '.')
			data->dot = 1;
		i++;
	}
	//printf("\n\nminus : %i\n", data->minus);
	//printf("width : %i\n", data->width);
	//printf("dot : %i\n\n\n", data->dot);
	ft_print(data, fmt + i, ap);
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
