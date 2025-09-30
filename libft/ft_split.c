/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:51:54 by brensant          #+#    #+#             */
/*   Updated: 2025/07/28 16:48:27 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_w_count(const char *s, char delimiter)
{
	size_t	w_count;

	w_count = 0;
	while (*s)
	{
		while (*s == delimiter)
			s++;
		if (!*s)
			break ;
		while (*s != delimiter && *s)
			s++;
		w_count++;
	}
	return (w_count);
}

static int	get_w_len(const char *s, char delimiter)
{
	size_t	w_len;

	w_len = 0;
	while (s[w_len] && s[w_len] != delimiter)
		w_len++;
	return (w_len);
}

static void	free_split(char	**str_array)
{
	size_t	i;

	i = 0;
	while (str_array[i])
	{
		free(str_array[i]);
		str_array[i] = NULL;
		i++;
	}
	free(str_array);
	str_array = NULL;
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	w_len;
	size_t	i;

	if (!s)
		return (NULL);
	array = ft_calloc(get_w_count(s, c) + 1, sizeof(*array));
	if (!array)
		return (NULL);
	i = 0;
	while (*s)
	{
		if (*s == c)
			s++;
		else
		{
			w_len = get_w_len(s, c);
			array[i] = ft_calloc(w_len + 1, sizeof(**array));
			if (!array[i])
				return (free_split(array), NULL);
			ft_strlcpy(array[i++], s, w_len + 1);
			s += w_len;
		}
	}
	return (array);
}
