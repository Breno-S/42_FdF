/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:40:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/13 13:06:13 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "common_bonus.h"
#include "transform_bonus.h"

t_vector3	vector3_zero(void)
{
	t_vector3	v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	return (v);
}

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
