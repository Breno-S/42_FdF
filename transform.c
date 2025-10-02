/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:40:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/02 16:45:31 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_point3	point3_scale(t_point3 v, int scalar)
{
	v.x = v.x * scalar;
	v.y = v.y * scalar;
	v.z = v.z * scalar;
	return (v);
}
