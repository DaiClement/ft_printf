/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_pow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:49:01 by cdai              #+#    #+#             */
/*   Updated: 2019/11/27 10:57:33 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_pow(unsigned int n, unsigned int pow)
{
	int	i;

	i = 0;
	if (n < pow)
		return (1);
	else
	{
		i += ft_count_pow(n / pow, pow);
		i += ft_count_pow(n % pow, pow);
	}
	return (i);
}
