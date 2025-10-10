/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:20:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/10 14:04:23 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "draw.h"
#include "header.h"
#include "mlx_utils.h"
#include "transform.h"

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
	v0 = vector3_scale(v0, mlx->map.scale);
	v0 = vector3_iso(v0);
	v0 = center_on_screen(v0);
	v1 = vector3_scale(v1, mlx->map.scale);
	v1 = vector3_iso(v1);
	v1 = center_on_screen(v1);
	if ((v0.x >= 0 && v0.x <= SC_W) || (v1.x >= 0 && v1.x <= SC_H))
		draw_line(mlx, v0, v1);
}

/*
 * Draws the map by connecting adjacent vertices with lines.
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
