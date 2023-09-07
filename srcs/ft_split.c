/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 21:54:53 by afadel            #+#    #+#             */
/*   Updated: 2023/09/07 03:48:49 by afadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_str(char const *s, char c)
{
	size_t	count;

	count = 0;
	if (*s != c && *s)
		count++;
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
			count++;
		s++;
	}
	return (count);
}

static size_t	ft_len_str(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s && *s != c)
	{
		count++;
		s++;
	}
	return (count);
}

static void	ft_fill_array(char **array, char const *s, char c)
{
	size_t	i;
	size_t	str_size;

	i = 0;
	if (*s != c && *s)
	{
		str_size = ft_len_str(s, c) + 1;
		array[i] = (char *)malloc(str_size);
		ft_strlcpy(array[i], s, str_size);
		i++;
	}
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
		{
			str_size = ft_len_str(s + 1, c) + 1;
			array[i] = (char *)malloc(str_size);
			ft_strlcpy(array[i], s + 1, str_size);
			i++;
		}
		s++;
	}
	array[i] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	size;

	size = ft_count_str(s, c) + 1;
	array = (char **)malloc(sizeof(char *) * size);
	ft_fill_array(array, s, c);
	return (array);
}
