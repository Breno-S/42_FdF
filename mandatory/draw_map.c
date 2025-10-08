/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:20:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/07 14:06:49 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "draw.h"
#include "header.h"
#include "mlx_utils.h"
#include "transform.h"

static void	transform_draw(t_mlx *mlx, t_point3 p0, t_point3 p1)
{
	p0 = point3_scale(p0, mlx->map.scale);
	p0 = point3_rotate(p0, mlx->map.angle_rad);
	p0 = point3_iso(p0);
	p0 = point3_translate(p0, mlx->map.offset);
	p1 = point3_scale(p1, mlx->map.scale);
	p1 = point3_rotate(p1, mlx->map.angle_rad);
	p1 = point3_iso(p1);
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
