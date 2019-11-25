/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdai <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 16:17:09 by cdai              #+#    #+#             */
/*   Updated: 2019/11/25 17:01:42 by cdai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_count_pow10(long n, long *count)
{
	if (n < 0)
	{
		n = -n;
		*count = *count + 1;
	}
	while (n >= 10)
	{
		n = n / 10;
		*count = *count + 1;
	}
}

static void	ft_sub_itoa_recursive(long n, char *result, long count)
{
	if (n < 0)
	{
		n = -n;
		result[0] = '-';
	}
	if (n < 10)
		result[count - 1] = n + 48;
	else
	{
		ft_sub_itoa_recursive(n / 10, result, count - 1);
		ft_sub_itoa_recursive(n % 10, result, count);
	}
}

static char	*ft_return_long_min(void)
{
	char		*result;
	const char	long_min[] = "-9223372036854775808";
	long			i;

	i = 0;
	if (!(result = malloc(sizeof(*result) * 21)))
		return (0);
	while (long_min[i])
	{
		result[i] = long_min[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char		*ft_itoa_long(long n)
{
	char		*result;
	long		count;

	count = 1;
	result = 0;
	if (n == LONG_MAX)
	{
		result = ft_return_long_min();
		return (result);
	}
	ft_count_pow10(n, &count);
	if (!(result = malloc(sizeof(*result) * (count + 1))))
		return (0);
	ft_sub_itoa_recursive(n, result, count);
	result[count] = 0;
	return (result);
}
