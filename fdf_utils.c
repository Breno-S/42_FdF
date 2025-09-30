/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:23:34 by brensant          #+#    #+#             */
/*   Updated: 2025/09/30 16:17:43 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_w_count(const char *s, char delimiter)
{
	int	w_count;

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

int	get_w_len(const char *s, char delimiter)
{
	int	w_len;

	w_len = 0;
	while (s[w_len] && s[w_len] != delimiter)
		w_len++;
	return (w_len);
}
