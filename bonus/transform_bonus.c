/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:40:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/09 17:00:52 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "header_bonus.h"
#include "transform_bonus.h"

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
	point.z *= scalar;
	return (point);
}

t_point3	point3_rotate(t_point3 point, t_vector3 angle_rad)
{
	t_point3	result;
	int			temp;

	result = point;
	if (angle_rad.x != 0.0F)
	{
		temp = result.y;
		result.y = result.y * cosf(angle_rad.x) - result.z * sinf(angle_rad.x);
		result.z = temp * sinf(angle_rad.x) + result.z * cosf(angle_rad.x);
	}
	if (angle_rad.y != 0.0F)
	{
		temp = result.x;
		result.x = result.x * cosf(angle_rad.y) + result.z * sinf(angle_rad.y);
		result.z = -temp * sinf(angle_rad.y) + result.z * cosf(angle_rad.y);
	}
	if (angle_rad.z != 0.0F)
	{
		temp = result.x;
		result.x = result.x * cosf(angle_rad.z) - result.y * sinf(angle_rad.z);
		result.y = temp * sinf(angle_rad.z) + result.y * cosf(angle_rad.z);
	}
	return (result);
}

t_point3	point3_iso(t_point3 point)
{
	t_point3	p;

	p.x = roundf((point.x - point.y) * cosf(M_PI / 6.0F));
	p.y = roundf((point.x + point.y) * sinf(M_PI / 6.0F) - point.z);
	return (p);
}

t_point3	point3_ortho(t_point3 point, enum e_view view)
{
	t_point3	p;

	if (view == FRONTAL)
	{
		p.x = point.x;
		p.y = point.y;
	}
	else if (view == LATERAL)
	{
		p.x = point.z;
		p.y = point.y;
	}
	else if (view == TOP_DOWN)
	{
		p.x = point.x;
		p.y = -point.z;
	}
	else
		p = point;
	return (p);
}
