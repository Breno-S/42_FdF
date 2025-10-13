/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:20:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/13 15:57:11 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "common_bonus.h"
#include "draw_bonus.h"
#include "env_utils_bonus.h"
#include "projection_bonus.h"
#include "transform_bonus.h"

static t_vector3	center_on_screen(t_vector3 v)
{
	t_vector3	offset;

	offset.x = SC_W / 2;
	offset.y = SC_H / 2;
	offset.z = 0;
	return (vector3_translate(v, offset));
}

static void	transform_draw(t_env *env, t_vector3 v0, t_vector3 v1)
{
	v0.z *= env->map->z_scale;
	v0 = vector3_scale(v0, env->map->scale);
	v0 = vector3_rotate(v0, env->map->angle_rad);
	if (env->map->view == ISO)
		v0 = vector3_iso(v0);
	else
		v0 = vector3_ortho(v0, env->map->view);
	v0 = center_on_screen(v0);
	v0 = vector3_translate(v0, env->map->offset);
	v1.z *= env->map->z_scale;
	v1 = vector3_scale(v1, env->map->scale);
	v1 = vector3_rotate(v1, env->map->angle_rad);
	if (env->map->view == ISO)
		v1 = vector3_iso(v1);
	else
		v1 = vector3_ortho(v1, env->map->view);
	v1 = center_on_screen(v1);
	v1 = vector3_translate(v1, env->map->offset);
	if (!((v0.x < 0 && v1.x < 0) || (v0.x > SC_W && v1.x > SC_W)
			|| (v0.y < 0 && v1.y < 0) || (v0.y > SC_H && v1.y > SC_H)))
		draw_line(env, v0, v1);
}

/*
 * Draws the map by connecting adjacent points with lines.
 */
void	draw_map(t_env *env)
{
	int		i;
	int		j;

	i = -1;
	while (++i < env->map->dimensions.y - 1)
	{
		j = -1;
		while (++j < env->map->dimensions.x - 1)
		{
			transform_draw(env, env->map->points[i][j],
				env->map->points[i][j + 1]);
			transform_draw(env, env->map->points[i][j],
				env->map->points[i + 1][j]);
		}
		transform_draw(env, env->map->points[i][j], env->map->points[i + 1][j]);
	}
	j = -1;
	while (++j < env->map->dimensions.x - 1)
		transform_draw(env, env->map->points[i][j], env->map->points[i][j + 1]);
}
