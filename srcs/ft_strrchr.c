/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 20:26:05 by afadel            #+#    #+#             */
/*   Updated: 2023/08/27 20:30:41 by afadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*char_ptr;

	char_ptr = NULL;
	while (*s)
	{
		if (*s == c)
		{
			char_ptr = (char *)s;
		}
		s++;
	}
	return (char_ptr);
}
