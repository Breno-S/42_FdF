/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 12:24:43 by brensant          #+#    #+#             */
/*   Updated: 2025/07/29 15:27:53 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicate;
	size_t	len;

	len = ft_strlen(s);
	duplicate = malloc(len + 1);
	if (!duplicate)
		return (NULL);
	while (*s)
	{
		*duplicate = *s;
		s++;
		duplicate++;
	}
	*duplicate = '\0';
	return (duplicate - len);
}
