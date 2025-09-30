/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:19:31 by brensant          #+#    #+#             */
/*   Updated: 2025/07/21 17:38:12 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	str_len;
	size_t	trim_length;

	if (!set || !s1)
		return ((char *)s1);
	trim_length = 0;
	while (is_in_set(*s1, set))
		s1++;
	str_len = ft_strlen(s1);
	trim_length = 0;
	while (is_in_set(s1[str_len - 1 - trim_length], set))
		trim_length++;
	return (ft_substr(s1, 0, str_len - trim_length));
}
