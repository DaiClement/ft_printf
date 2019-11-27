/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex_lower.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 10:37:23 by cdai              #+#    #+#             */
/*   Updated: 2019/11/26 10:37:47 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_hex_lower(unsigned int n, int fd)
{
	int			i;
	const char	map_hex[] = "0123456789abcdef";

	i = 0;
	if (n < 16)
	{
		ft_putchar_fd(map_hex[n], fd);
		return (1);
	}
	else
	{
		i += ft_putnbr_hex_lower(n / 16, fd);
		i += ft_putnbr_hex_lower(n % 16, fd);
	}
	return (i);
}
