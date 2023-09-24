/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:48:03 by afadel            #+#    #+#             */
/*   Updated: 2023/09/24 01:46:30 by afadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*iterator;

	iterator = *lst;
	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (iterator->next)
		iterator = iterator->next;
	iterator->next = new;
}
