/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 09:21:16 by cdai              #+#    #+#             */
/*   Updated: 2019/12/02 09:32:40 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putlnbr_base(unsigned long int n, int fd, const char *base)
{
	int					i;
	const unsigned int	len_base = ft_strlen(base);

	i = 0;
	if (n < len_base)
	{
		ft_putchar_fd(base[n], fd);
		return (1);
	}
	else
	{
		i += ft_putlnbr_base(n / len_base, fd, base);
		i += ft_putlnbr_base(n % len_base, fd, base);
	}
	return (i);
}
