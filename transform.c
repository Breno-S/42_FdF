/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:40:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/06 20:08:49 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "header.h"
#include "transform.h"

t_point3	point3_translate(t_point3 point, t_point3 offset)
{
	point.x += offset.x;
	point.y += offset.y;
	point.z += offset.z;
	return (point);
}

t_point3	point3_scale(t_point3 point, int scalar)
{
	point.x *= scalar;
	point.y *= scalar;
	point.z *= scalar / 10;
	return (point);
}

t_point3	point3_rotate(t_point3 point, float theta, enum e_axis axis)
{
	if (axis == X_AXIS)
	{

	}
	else if (axis == Y_AXIS)
	{

	}
	else if (axis == Z_AXIS)
	{

	}
	return (point);
}

t_point3	point3_iso(t_point3 point)
{
	t_point3	p;

	p.x = roundf((point.x - point.y) * cosf(M_PI / 6.0F));
	p.y = roundf((point.x + point.y) * sinf(M_PI / 6.0F) - point.z);
	return (p);
}
