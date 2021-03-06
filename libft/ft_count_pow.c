/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_pow.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 08:49:01 by cdai              #+#    #+#             */
/*   Updated: 2019/12/02 12:00:37 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_pow(unsigned long int n, unsigned int pow)
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
