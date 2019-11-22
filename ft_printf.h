/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:33:44 by cdai              #+#    #+#             */
/*   Updated: 2019/11/22 09:30:08 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_flag_data
{
	int	minus;
	int	zero_flag;
	int	width;
	int	dot;
	int	precision;
}					t_flag_data;

//typedef strut		s_
//int ft_precision(t_flag_data *data, const char *fmt, va_list *ap);

void    ft_c(t_flag_data *data, va_list *ap);
void    ft_s(t_flag_data *data, va_list *ap);
int ft_check_conversion(const char *fmt);
void ft_print(t_flag_data *data, const char *fmt, va_list *ap);
int	ft_printf(const char *fmt, ...);

#endif
