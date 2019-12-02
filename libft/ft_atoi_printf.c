/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:45:12 by cdai              #+#    #+#             */
/*   Updated: 2019/12/02 15:07:18 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_printf(const char *str, int *i)
{
	int	result;

	result = 0;
	while (ft_isdigit(str[*i]))
	{
		result = result * 10 + str[*i] - 48;
		(*i)++;
	}
	(*i)--;
	return (result);
}
