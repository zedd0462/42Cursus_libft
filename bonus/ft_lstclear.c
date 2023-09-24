/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 16:56:51 by afadel            #+#    #+#             */
/*   Updated: 2023/09/24 17:44:30 by afadel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*iterator;
	t_list	*remover;

	iterator = *lst;
	if (!iterator)
		return ;
	while (iterator->next)
	{
		remover = iterator;
		iterator = iterator->next;
		ft_lstdelone(remover, del);
	}
	ft_lstdelone(iterator, del);
	*lst = NULL;
}
