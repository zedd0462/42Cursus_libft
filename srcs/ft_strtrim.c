/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 06:28:03 by afadel            #+#    #+#             */
/*   Updated: 2023/09/03 07:14:55 by afadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_len_trimmed(char const *s1, char const *set)
{
	size_t	len;

	len = 0;
	while (*s1)
	{
		if (!ft_in_set(*s1, set))
			len++;
		s1++;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	i;

	i = 0;
	trimmed = (char *)malloc(ft_len_trimmed(s1, set) + 1);
	if (trimmed == NULL)
		return (NULL);
	while (*s1)
	{
		if (!ft_in_set(*s1, set))
			trimmed[i++] = *s1;
		s1++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
