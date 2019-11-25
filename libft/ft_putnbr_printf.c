/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:46:16 by cdai              #+#    #+#             */
/*   Updated: 2019/11/25 18:14:46 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_printf(unsigned int n, int fd)
{
	int		i;

	i = 0;
	if (n < 10)
	{
		ft_putchar_fd(n + 48, fd);
		return (1);
	}
	else
	{
		i += ft_putnbr_printf(n / 10, fd);
		i += ft_putnbr_printf(n % 10, fd);
	}
	return (i);
}
