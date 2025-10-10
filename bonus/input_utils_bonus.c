/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:08:50 by brensant          #+#    #+#             */
/*   Updated: 2025/10/11 11:54:41 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "header_bonus.h"
#include "mlx_utils_bonus.h"

static int	handle_movement(int keysym, t_mlx *mlx)
{
	if (keysym == 0x61)
		mlx->map.offset.x -= 1 * mlx->map.scale;
	else if (keysym == 0x64)
		mlx->map.offset.x += 1 * mlx->map.scale;
	else if (keysym == 0x77)
		mlx->map.offset.y -= 1 * mlx->map.scale;
	else if (keysym == 0x73)
		mlx->map.offset.y += 1 * mlx->map.scale;
	else
		return (0);
	draw_and_render(mlx);
	return (1);
}

static int	handle_rotation(int keysym, t_mlx *mlx)
{
	if (keysym == 65429)
		mlx->map.angle_rad.z += M_PI / 180.0F;
	else if (keysym == 65434)
		mlx->map.angle_rad.z -= M_PI / 180.0F;
	else if (keysym == 65431)
		mlx->map.angle_rad.x += M_PI / 180.0F;
	else if (keysym == 65433)
		mlx->map.angle_rad.x -= M_PI / 180.0F;
	else if (keysym == 65430)
		mlx->map.angle_rad.y += M_PI / 180.0F;
	else if (keysym == 65432)
		mlx->map.angle_rad.y -= M_PI / 180.0F;
	else
		return (0);
	draw_and_render(mlx);
	return (1);
}

static int	handle_change_projection(int keysym, t_mlx *mlx)
{
	t_vector3	zero;

	zero.x = 0;
	zero.y = 0;
	zero.z = 0;
	if (keysym == 0x70)
	{
		mlx->map.view = (mlx->map.view + 1) % 4;
		mlx->map.angle_rad = zero;
		mlx->map.offset = zero;
		draw_and_render(mlx);
		return (1);
	}
	return (0);
}

int	handle_keypress(int keysym, t_mlx *mlx)
{
	if (keysym == 0xff1b)
		finish_mlx(mlx, EXIT_SUCCESS);
	if (keysym == 0x2d)
	{
		mlx->map.z_scale -= 0.01F;
		draw_and_render(mlx);
		return (0);
	}
	if (keysym == 0x3d)
	{
		mlx->map.z_scale += 0.01F;
		draw_and_render(mlx);
		return (0);
	}
	if (handle_movement(keysym, mlx))
		return (0);
	if (handle_rotation(keysym, mlx))
		return (0);
	if (handle_change_projection(keysym, mlx))
		return (0);
	return (0);
}

int	handle_mousepress(int keysym, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	if (keysym == 0x4)
	{
		mlx->map.scale *= 1.1;
		if (mlx->map.scale > SC_H)
		{
			mlx->map.scale = (float)SC_H;
			return (0);
		}
		draw_and_render(mlx);
	}
	else if (keysym == 0x5)
	{
		mlx->map.scale /= 1.1F;
		if (mlx->map.scale < 1.0F)
		{
			mlx->map.scale = 1.0F;
			return (0);
		}
		draw_and_render(mlx);
	}
	return (0);
}
