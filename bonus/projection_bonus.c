/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 01:25:34 by brensant          #+#    #+#             */
/*   Updated: 2025/10/13 22:55:30 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "common_bonus.h"

t_vector3	vector3_project(t_vector3 v, enum e_view view)
{
	t_vector3	p;

	if (view == ISO)
	{
		p.x = roundf((v.x - v.y) * COS_30);
		p.y = roundf((v.x + v.y) * SIN_30 - v.z);
	}
	else if (view == FRONTAL)
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
		return (v);
	return (p);
}
