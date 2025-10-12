/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:20:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/11 21:18:19 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "common.h"
#include "draw.h"
#include "env_utils.h"

static void	transform_draw(t_env *env, t_vector3 v0, t_vector3 v1)
{
	float	temp_x;

	v0.x *= env->map.scale;
	v0.y *= env->map.scale;
	v0.z *= env->map.scale;
	temp_x = v0.x;
	v0.x = roundf((v0.x - v0.y) * COS_30);
	v0.y = roundf((temp_x + v0.y) * SIN_30 - v0.z);
	v0.x += SC_W / 2;
	v0.y += SC_H / 2;
	v1.x *= env->map.scale;
	v1.y *= env->map.scale;
	v1.z *= env->map.scale;
	temp_x = v1.x;
	v1.x = roundf((v1.x - v1.y) * COS_30);
	v1.y = roundf((temp_x + v1.y) * SIN_30 - v1.z);
	v1.x += SC_W / 2;
	v1.y += SC_H / 2;
	if (!((v0.x < 0 && v1.x < 0) || (v0.x > SC_W && v1.x > SC_W)
			|| (v0.y < 0 && v1.y < 0) || (v0.y > SC_H && v1.y > SC_H)))
		draw_line(env, v0, v1);
}

/*
 * Draws the map by connecting adjacent vertices with lines.
 */
void	draw_map(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->map.dimensions.y - 1)
	{
		j = -1;
		while (++j < env->map.dimensions.x - 1)
		{
			transform_draw(env, env->map.points[i][j],
				env->map.points[i][j + 1]);
			transform_draw(env, env->map.points[i][j],
				env->map.points[i + 1][j]);
		}
		transform_draw(env, env->map.points[i][j], env->map.points[i + 1][j]);
	}
	j = -1;
	while (++j < env->map.dimensions.x - 1)
		transform_draw(env, env->map.points[i][j], env->map.points[i][j + 1]);
}
