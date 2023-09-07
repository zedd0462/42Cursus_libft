/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 19:43:36 by afadel            #+#    #+#             */
/*   Updated: 2023/08/27 20:04:54 by afadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*char_ptr;

	char_ptr = NULL;
	while (*s)
	{
		if (*s == c)
		{
			char_ptr = (char *)s;
			return (char_ptr);
		}
		s++;
	}
	return (char_ptr);
}
