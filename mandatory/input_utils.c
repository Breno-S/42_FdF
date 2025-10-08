/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 13:08:50 by brensant          #+#    #+#             */
/*   Updated: 2025/10/07 14:28:43 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "header.h"
#include "mlx_utils.h"

static int	handle_exit(int keysym, t_mlx *mlx)
{
	if (keysym == 0xff1b)
		finish_mlx(mlx, EXIT_SUCCESS);
	return (0);
}

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
	img_clear_window(mlx);
	return (1);
}

static int	handle_rotation(int keysym, t_mlx *mlx)
{
	if (keysym == 0x71)
		mlx->map.angle_rad.z += M_PI / 180.0F;
	else if (keysym == 0x65)
		mlx->map.angle_rad.z -= M_PI / 180.0F;
	else if (keysym == 0xff51)
		mlx->map.angle_rad.y += M_PI / 180.0F;
	else if (keysym == 0xff53)
		mlx->map.angle_rad.y -= M_PI / 180.0F;
	else if (keysym == 0xff52)
		mlx->map.angle_rad.x += M_PI / 180.0F;
	else if (keysym == 0xff54)
		mlx->map.angle_rad.x -= M_PI / 180.0F;
	else
		return (0);
	img_clear_window(mlx);
	return (1);
}

static int	handle_scaling(int keysym, t_mlx *mlx)
{
	if (keysym == 0x66)
		mlx->map.scale += 1;
	else if (keysym == 0x67)
		mlx->map.scale -= 1;
	else
		return (0);
	img_clear_window(mlx);
	return (1);
}

int	handle_keypress(int keysym, t_mlx *mlx)
{
	printf("KeyPress: %#x\n", keysym);
	handle_exit(keysym, mlx);
	if (handle_movement(keysym, mlx))
		return (0);
	if (handle_rotation(keysym, mlx))
		return (0);
	if (handle_scaling(keysym, mlx))
		return (0);
	return (0);
}
