/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:20:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/09 17:31:00 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "draw_bonus.h"
#include "header_bonus.h"
#include "mlx_utils_bonus.h"
#include "transform_bonus.h"

static void	transform_draw(t_mlx *mlx, t_point3 p0, t_point3 p1)
{
	p0.z *= mlx->map.z_scale;
	p0 = point3_scale(p0, mlx->map.scale);
	p0 = point3_rotate(p0, mlx->map.angle_rad);
	if (mlx->map.view == ISO)
		p0 = point3_iso(p0);
	else
		p0 = point3_ortho(p0, mlx->map.view);
	p0 = point3_translate(p0, mlx->map.offset);
	p1.z *= mlx->map.z_scale;
	p1 = point3_scale(p1, mlx->map.scale);
	p1 = point3_rotate(p1, mlx->map.angle_rad);
	if (mlx->map.view == ISO)
		p1 = point3_iso(p1);
	else
		p1 = point3_ortho(p1, mlx->map.view);
	p1 = point3_translate(p1, mlx->map.offset);
	draw_line(mlx, p0, p1);
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
