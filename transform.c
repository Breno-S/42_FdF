/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:40:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/06 16:38:22 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "header.h"

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

t_point3	point3_rotate(t_point3 point, float theta)
{
	int x_temp;

	x_temp = point.x;
	point.x = roundf(point.x * cosf(theta) - point.y * sinf(theta));
	point.y = roundf(x_temp * sinf(theta) + point.y * cosf(theta));
	return (point);
}

t_point3	point3_iso(t_point3 point)
{
	t_point3	p;

	p.x = roundf((point.x - point.y) * cosf(M_PI / 6.0F));
	p.y = roundf((point.x + point.y) * sinf(M_PI / 6.0F) - point.z);
	return (p);
}
