/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 04:15:39 by afadel            #+#    #+#             */
/*   Updated: 2023/09/01 00:55:02 by afadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	safe_len;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (size <= dst_len || !size)
		return (src_len + dst_len);
	safe_len = size - dst_len - 1;
	if (src_len < safe_len)
	{
		ft_memcpy(dst + dst_len, src, src_len);
		dst[src_len + dst_len] = '\0';
	}
	else
	{
		ft_memcpy(dst + dst_len, src, safe_len);
		dst[size - 1] = '\0';
	}
	return (src_len + dst_len);
}
