/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:20:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/09 20:55:36 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "draw.h"
#include "header.h"
#include "mlx_utils.h"
#include "transform.h"
#include "draw_map_utils.h"

static t_point3	center_on_origin(t_point3 p, t_map *map)
{
	t_point3	offset;

	offset.x = -(map->dimensions.x / 2);
	offset.y = -(map->dimensions.y / 2) - get_z_middle(map);
	offset.z = -get_z_middle(map);
	return (point3_translate(p, offset));
}

static t_point3	center_on_screen(t_point3 p)
{
	t_point3	offset;

	offset.x = SC_W / 2;
	offset.y = SC_H / 2;
	offset.z = 0;
	return (point3_translate(p, offset));
}

static void	transform_draw(t_mlx *mlx, t_point3 p0, t_point3 p1)
{
	p0 = center_on_origin(p0, &mlx->map);
	p0 = point3_scale(p0, mlx->map.scale);
	p0 = point3_iso(p0);
	p0 = center_on_screen(p0);
	p1 = center_on_origin(p1, &mlx->map);
	p1 = point3_scale(p1, mlx->map.scale);
	p1 = point3_iso(p1);
	p1 = center_on_screen(p1);
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
