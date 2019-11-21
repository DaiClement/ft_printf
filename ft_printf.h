/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:33:44 by cdai              #+#    #+#             */
/*   Updated: 2019/11/21 14:54:28 by cdai             ###   ########.fr       */
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
	int	precision;
}					t_flag_data;

//typedef strut		s_
int	ft_printf(const char *fmt, ...);

#endif
