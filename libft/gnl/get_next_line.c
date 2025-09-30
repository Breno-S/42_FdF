/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:00:39 by brensant          #+#    #+#             */
/*   Updated: 2025/08/17 13:44:31 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_node(t_str_list *node);
void	free_list(t_str_list **str_list);
int		has_new_line(t_str_list *str_list);
int		get_line_len(t_str_list *str_list);
void	normalize_node(t_str_list *str_list);

static void	add_str_node(t_str_list **str_list, char *str)
{
	t_str_list		*head;
	t_str_list		*new_node;

	if (!str || !str_list)
		return ;
	new_node = malloc(sizeof(t_str_list));
	if (!new_node)
		return ;
	new_node->str = str;
	new_node->next = NULL;
	if (!*str_list)
		*str_list = new_node;
	else
	{
		head = *str_list;
		while (head->next)
			head = head->next;
		head->next = new_node;
	}
}

static void	fill_list(t_str_list **str_list, int fd)
{
	int		bytes_read;
	char	*buffer;

	if (fd < 0 || !str_list)
		return ;
	while (!has_new_line(*str_list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (!buffer)
			return ;
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			if (bytes_read == -1)
				free_list(str_list);
			return ;
		}
		buffer[bytes_read] = '\0';
		add_str_node(str_list, buffer);
		if (bytes_read != BUFFER_SIZE)
			break ;
	}
}

static char	*extract_line(t_str_list *str_list)
{
	char			*line;
	unsigned int	line_len;
	unsigned int	i;
	unsigned int	j;

	if (!str_list)
		return (NULL);
	line_len = get_line_len(str_list);
	if (line_len == 0)
		return (NULL);
	line = malloc(line_len + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (str_list)
	{
		j = 0;
		while (j < BUFFER_SIZE && str_list->str[j] && i < line_len)
			line[i++] = str_list->str[j++];
		line[i] = '\0';
		str_list = str_list->next;
	}
	return (line);
}

static void	reset_list(t_str_list **str_list)
{
	t_str_list	*head;
	t_str_list	*next;
	t_str_list	*last_node;

	if (!str_list || !*str_list)
		return ;
	head = *str_list;
	while (head->next)
		head = head->next;
	last_node = head;
	head = *str_list;
	while (head != last_node)
	{
		next = head->next;
		free_node(head);
		head = next;
	}
	normalize_node(last_node);
	if (last_node->str[0] == '\0')
	{
		free_node(last_node);
		last_node = NULL;
	}
	*str_list = last_node;
}

char	*get_next_line(int fd)
{
	static t_str_list	*str_list;
	char				*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	fill_list(&str_list, fd);
	if (!str_list)
		return (NULL);
	line = extract_line(str_list);
	reset_list(&str_list);
	return (line);
}
