/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:15:29 by brensant          #+#    #+#             */
/*   Updated: 2025/07/28 15:16:03 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*next;

	if (!lst || !del)
		return ;
	head = *lst;
	while (head)
	{
		next = head->next;
		ft_lstdelone(head, del);
		head = next;
	}
	*lst = NULL;
}
