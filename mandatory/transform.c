/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:40:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/10 14:04:01 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "header.h"
#include "transform.h"

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

t_vector3	vector3_iso(t_vector3 v)
{
	t_vector3	p;

	p.x = roundf((v.x - v.y) * COS_30);
	p.y = roundf((v.x + v.y) * SIN_30 - v.z);
	return (p);
}
