/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:20:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/10 16:48:05 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "draw_bonus.h"
#include "header_bonus.h"
#include "mlx_utils_bonus.h"
#include "transform_bonus.h"

static t_vector3	center_on_screen(t_vector3 v)
{
	t_vector3	offset;

	offset.x = SC_W / 2;
	offset.y = SC_H / 2;
	offset.z = 0;
	return (vector3_translate(v, offset));
}

static void	transform_draw(t_mlx *mlx, t_vector3 v0, t_vector3 v1)
{
	v0.z *= mlx->map.z_scale;
	v0 = vector3_scale(v0, mlx->map.scale);
	v0 = vector3_rotate(v0, mlx->map.angle_rad);
	if (mlx->map.view == ISO)
		v0 = vector3_iso(v0);
	else
		v0 = vector3_ortho(v0, mlx->map.view);
	v0 = center_on_screen(v0);
	v0 = vector3_translate(v0, mlx->map.offset);
	v1.z *= mlx->map.z_scale;
	v1 = vector3_scale(v1, mlx->map.scale);
	v1 = vector3_rotate(v1, mlx->map.angle_rad);
	if (mlx->map.view == ISO)
		v1 = vector3_iso(v1);
	else
		v1 = vector3_ortho(v1, mlx->map.view);
	v1 = center_on_screen(v1);
	v1 = vector3_translate(v1, mlx->map.offset);
	draw_line(mlx, v0, v1);
}

/*
 * Draws the map by connecting adjacent points with lines.
 */
void	draw_map(t_mlx *mlx)
{
	int		i;
	int		j;

	i = -1;
	while (++i < mlx->map.dimensions.y - 1)
	{
		j = -1;
		while (++j < mlx->map.dimensions.x - 1)
		{
			transform_draw(mlx, mlx->map.points[i][j],
				mlx->map.points[i][j + 1]);
			transform_draw(mlx, mlx->map.points[i][j],
				mlx->map.points[i + 1][j]);
		}
		transform_draw(mlx, mlx->map.points[i][j], mlx->map.points[i + 1][j]);
	}
	j = -1;
	while (++j < mlx->map.dimensions.x - 1)
		transform_draw(mlx, mlx->map.points[i][j], mlx->map.points[i][j + 1]);
}
