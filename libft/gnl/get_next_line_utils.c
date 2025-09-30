/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:02:38 by brensant          #+#    #+#             */
/*   Updated: 2025/08/17 13:44:36 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_node(t_str_list *node)
{
	if (node)
	{
		free(node->str);
		free(node);
	}
}

void	free_list(t_str_list **str_list)
{
	t_str_list	*head;
	t_str_list	*next;

	if (!str_list)
		return ;
	head = *str_list;
	while (head)
	{
		next = head->next;
		free_node(head);
		head = next;
	}
	*str_list = NULL;
}

int	has_new_line(t_str_list *str_list)
{
	int			i;

	while (str_list)
	{
		i = 0;
		while (i < BUFFER_SIZE && str_list->str[i])
		{
			if (str_list->str[i] == '\n')
				return (1);
			i++;
		}
		str_list = str_list->next;
	}
	return (0);
}

int	get_line_len(t_str_list *str_list)
{
	int	line_len;
	int	i;

	line_len = 0;
	while (str_list)
	{
		i = 0;
		while (i < BUFFER_SIZE && str_list->str[i])
		{
			if (str_list->str[i++] == '\n')
				return (line_len + 1);
			line_len++;
		}
		str_list = str_list->next;
	}
	return (line_len);
}

void	normalize_node(t_str_list *node)
{
	char	*remaining;
	int		i;
	int		j;

	if (!node || !node->str)
		return ;
	i = 0;
	while (node->str[i])
		if (node->str[i++] == '\n')
			break ;
	j = 0;
	while (node->str[i + j])
		j++;
	remaining = malloc(j + 1);
	if (!remaining)
		return ;
	j = 0;
	while (node->str[i])
		remaining[j++] = node->str[i++];
	remaining[j] = '\0';
	free(node->str);
	node->str = remaining;
}
