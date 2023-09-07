/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 01:35:34 by afadel            #+#    #+#             */
/*   Updated: 2023/08/31 02:02:37 by afadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_rev_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*_src;
	unsigned char	*_dest;

	_src = ((unsigned char *)src) + n - 1;
	_dest = ((unsigned char *)dest) + n - 1;
	while (n > 0)
	{
		*_dest = *_src;
		_src--;
		_dest--;
		n--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src == dest)
		return (dest);
	if (src > dest)
		return (ft_memcpy(dest, src, n));
	else
		return (ft_rev_memcpy(dest, src, n));
}
