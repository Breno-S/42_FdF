/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 13:57:17 by brensant          #+#    #+#             */
/*   Updated: 2025/07/24 18:02:02 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(int c)
{
	return ((c >= 9 && c <= 13) || (c == ' '));
}

int	ft_atoi(const char *nptr)
{
	int	num;
	int	digit;
	int	sign;

	sign = 1;
	num = 0;
	while (is_space(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -sign;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		digit = (*nptr - '0');
		num = num * 10 + digit;
		nptr++;
	}
	return (sign * num);
}
