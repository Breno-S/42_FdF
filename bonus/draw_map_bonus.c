/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:20:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/14 17:32:36 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "common_bonus.h"
#include "draw_bonus.h"
#include "env_utils_bonus.h"
#include "projection_bonus.h"
#include "transform_bonus.h"

static void	transform_draw(t_env *env, t_vertex v0, t_vertex v1)
{
	v0.pos.z *= env->map->z_scale;
	v0.pos = vector3_scale(v0.pos, env->map->scale);
	v0.pos = vector3_rotate(v0.pos, env->map->angle_rad);
	v0.pos = vector3_project(v0.pos, env->map->view);
	v0.pos.x += SC_W / 2;
	v0.pos.y += SC_H / 2;
	v0.pos = vector3_translate(v0.pos, env->map->offset);
	v1.pos.z *= env->map->z_scale;
	v1.pos = vector3_scale(v1.pos, env->map->scale);
	v1.pos = vector3_rotate(v1.pos, env->map->angle_rad);
	v1.pos = vector3_project(v1.pos, env->map->view);
	v1.pos.x += SC_W / 2;
	v1.pos.y += SC_H / 2;
	v1.pos = vector3_translate(v1.pos, env->map->offset);
	if (!((v0.pos.x < 0 && v1.pos.x < 0) || (v0.pos.x > SC_W && v1.pos.x > SC_W)
			|| (v0.pos.y < 0 && v1.pos.y < 0)
			|| (v0.pos.y > SC_H && v1.pos.y > SC_H)))
		draw_line(env, v0, v1);
}

/*
 * Draws the map by connecting adjacent points with lines.
 */
void	draw_map(t_env *env)
{
	int	i;
	int	j;

	i = -1;
	while (++i < env->map->rows - 1)
	{
		j = -1;
		while (++j < env->map->columns - 1)
		{
			transform_draw(env, env->map->vertices[i][j],
				env->map->vertices[i][j + 1]);
			transform_draw(env, env->map->vertices[i][j],
				env->map->vertices[i + 1][j]);
		}
		transform_draw(env, env->map->vertices[i][j],
			env->map->vertices[i + 1][j]);
	}
	j = -1;
	while (++j < env->map->columns - 1)
		transform_draw(env, env->map->vertices[i][j],
			env->map->vertices[i][j + 1]);
}
