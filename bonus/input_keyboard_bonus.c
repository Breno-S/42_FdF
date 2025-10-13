/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_keyboard_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:08:50 by brensant          #+#    #+#             */
/*   Updated: 2025/10/13 15:04:59 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "common_bonus.h"
#include "env_utils_bonus.h"
#include "fdf_utils_bonus.h"
#include "transform_bonus.h"

static int	handle_movement(int keysym, t_env *env)
{
	if (keysym == 0x61)
		env->map->offset.x -= 1 * env->map->scale;
	else if (keysym == 0x64)
		env->map->offset.x += 1 * env->map->scale;
	else if (keysym == 0x77)
		env->map->offset.y -= 1 * env->map->scale;
	else if (keysym == 0x73)
		env->map->offset.y += 1 * env->map->scale;
	else
		return (0);
	env_draw_and_render(env);
	return (1);
}

static int	handle_rotation(int keysym, t_env *env)
{
	if (keysym == 0x65)
		env->map->angle_rad.z += M_PI / 180.0F;
	else if (keysym == 0x71)
		env->map->angle_rad.z -= M_PI / 180.0F;
	else if (keysym == 65432)
		env->map->angle_rad.y += M_PI / 180.0F;
	else if (keysym == 65430)
		env->map->angle_rad.y -= M_PI / 180.0F;
	else if (keysym == 65431)
		env->map->angle_rad.x += M_PI / 180.0F;
	else if (keysym == 65433)
		env->map->angle_rad.x -= M_PI / 180.0F;
	else
		return (0);
	env_draw_and_render(env);
	return (1);
}

static int	handle_change_projection(int keysym, t_env *env)
{
	if (keysym == 0x70)
	{
		env->map->view = (env->map->view + 1) % 4;
		env->map->angle_rad = vector3_zero();
		env->map->offset = vector3_zero();
		env_draw_and_render(env);
		return (1);
	}
	return (0);
}

static int	handle_z_scaling(int keysym, t_env *env)
{
	if (keysym == 0x2d)
		env->map->z_scale -= 0.05F;
	else if (keysym == 0x3d)
		env->map->z_scale += 0.05F;
	else if (keysym == 0x30)
		env->map->z_scale = 1.0F;
	else
		return (0);
	env_draw_and_render(env);
	return (1);
}

int	handle_keypress(int keysym, t_env *env)
{
	if (keysym == 0xff1b)
		env_finish(env, EXIT_SUCCESS);
	if (keysym == 65437)
	{
		env->map->angle_rad = vector3_zero();
		env->map->offset = vector3_zero();
		env_draw_and_render(env);
		return (1);
	}
	if (handle_z_scaling(keysym, env))
		return (0);
	if (handle_movement(keysym, env))
		return (0);
	if (handle_rotation(keysym, env))
		return (0);
	handle_change_projection(keysym, env);
	return (0);
}
