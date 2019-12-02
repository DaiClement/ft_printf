/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:33:44 by cdai              #+#    #+#             */
/*   Updated: 2019/12/02 15:01:58 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_flag_data
{
	int	minus;
	int	zero_flag;
	int	width;
	int	dot;
	int	precision;
}				t_flag_data;

void			ft_printf_pointer(t_flag_data *data, va_list *ap, int *result);
void			ft_printf_hexa_upper(t_flag_data *data, va_list *ap,
	int *result);
void			ft_printf_hexa_lower(t_flag_data *data, va_list *ap,
	int *result);
void			ft_printf_unsigned(t_flag_data *data, va_list *ap, int *result);
void			ft_i_negative(t_flag_data *data, unsigned int d, int *result);
void			ft_printf_int(t_flag_data *data, va_list *ap, int *result);
void			ft_printf_string(t_flag_data *data, va_list *ap, int *result);
int				ft_putlchar(int n, char c);
void			ft_printf_char(t_flag_data *data, va_list *ap, int *result);
int				ft_check_conversion(const char *fmt);
void			ft_print(t_flag_data *data, const char *fmt, va_list *ap,
	int *result);
int				ft_printf(const char *fmt, ...);

#endif
