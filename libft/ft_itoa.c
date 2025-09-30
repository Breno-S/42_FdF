/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 13:56:54 by brensant          #+#    #+#             */
/*   Updated: 2025/07/22 15:18:01 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_num_width(int n)
{
	int			width;
	long int	nbr;

	nbr = n;
	if (nbr < 0)
		nbr *= -1;
	width = 1;
	while (nbr / 10)
	{
		nbr /= 10;
		width++;
	}
	return (width);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	char		*str;
	int			is_negative;
	int			width;

	nbr = n;
	is_negative = (nbr < 0);
	width = get_num_width(n);
	str = ft_calloc(width + is_negative + 1, sizeof(*str));
	if (!str)
		return (NULL);
	if (is_negative)
		nbr *= -1;
	while (width + is_negative > 0)
	{
		str[width + is_negative - 1] = (nbr % 10) + '0';
		nbr /= 10;
		width--;
	}
	if (is_negative)
		str[0] = '-';
	return (str);
}
