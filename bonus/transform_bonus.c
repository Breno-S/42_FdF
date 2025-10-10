/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:40:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/10 16:51:48 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "header_bonus.h"
#include "transform_bonus.h"

t_vector3	vector3_translate(t_vector3 v, t_vector3 offset)
{
	v.x += offset.x;
	v.y += offset.y;
	v.z += offset.z;
	return (v);
}

t_vector3	vector3_scale(t_vector3 v, float scalar)
{
	v.x *= scalar;
	v.y *= scalar;
	v.z *= scalar;
	return (v);
}

t_vector3	vector3_rotate(t_vector3 v, t_vector3 angle_rad)
{
	t_vector3	result;
	float		temp;

	result = v;
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

t_vector3	vector3_iso(t_vector3 v)
{
	t_vector3	p;

	p.x = roundf((v.x - v.y) * COS_30);
	p.y = roundf((v.x + v.y) * SIN_30 - v.z);
	return (p);
}

t_vector3	vector3_ortho(t_vector3 v, enum e_view view)
{
	t_vector3	p;

	if (view == FRONTAL)
	{
		p.x = v.x;
		p.y = v.y;
	}
	else if (view == LATERAL)
	{
		p.x = v.z;
		p.y = v.y;
	}
	else if (view == TOP_DOWN)
	{
		p.x = v.x;
		p.y = -v.z;
	}
	else
		p = v;
	return (p);
}
