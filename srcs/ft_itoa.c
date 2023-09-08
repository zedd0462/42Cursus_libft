/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 09:14:45 by afadel            #+#    #+#             */
/*   Updated: 2023/09/08 06:12:12 by afadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(int n)
{
	size_t	len;

	len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	if (!len)
		return (1);
	return (len);
}

static int	ft_pow(int base, int exp)
{
	int	result;

	result = 1;
	while (exp)
	{
		result *= base;
		exp--;
	}
	return (result);
}

static int	ft_abs(int value)
{
	if (value < 0)
		return (-value);
	return (value);
}

char	*ft_itoa(int n)
{
	size_t	len;
	size_t	i;
	char	*str;
	int		tmp;

	len = ft_len(n);
	i = 0;
	str = (char *)malloc(len + 1 + ((n < 0) * 1));
	if (n < 0 && len > 0)
		str[i++] = '-';
	while (len)
	{
		tmp = ft_pow(10, len - 1);
		str[i++] = ft_abs(n / tmp) + '0';
		n -= (n / tmp) * (tmp);
		len--;
	}
	str[i] = '\0';
	return (str);
}
