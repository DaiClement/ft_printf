/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:33:44 by cdai              #+#    #+#             */
/*   Updated: 2019/11/26 12:28:18 by cdai             ###   ########.fr       */
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

void				ft_p(t_flag_data *data, va_list *ap, int *result);
void				ft_x_upper(t_flag_data *data, va_list *ap, int *result);
void				ft_x_lower(t_flag_data *data, va_list *ap, int *result);
int					ft_putspace(int n);
void				ft_u(t_flag_data *data, va_list *ap, int *result);
void				ft_i_negative(t_flag_data *data, unsigned int d,
	int *result);
void				ft_i_positive(t_flag_data *data, unsigned int d,
	int *result);
void				ft_i(t_flag_data *data, va_list *ap, int *result);
void				ft_c(t_flag_data *data, va_list *ap, int *result);
void				ft_s(t_flag_data *data, va_list *ap, int *result);
int					ft_check_conversion(const char *fmt);
void				ft_print(t_flag_data *data, const char *fmt, va_list *ap,
	int *result);
int					ft_printf(const char *fmt, ...);

#endif
