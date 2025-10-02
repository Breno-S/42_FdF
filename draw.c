/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:20:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/02 16:04:56 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "header.h"
#include "mlx_utils.h"

/*
 * Draws a line from `p0` to `p1`.
 */
void	draw_line(t_mlx *mlx, t_point3 p0, t_point3 p1)
{
	t_vector2	delta;
	t_vector2	step;
	float		big_step;
	int			i;

	delta.x = p1.x - p0.x;
	delta.y = p1.y - p0.y;
	big_step = fmax(fabs(delta.x), fabs(delta.y));
	if (big_step != 0)
	{
		step.x = delta.x / big_step;
		step.y = delta.y / big_step;
		i = 0;
		while (i < big_step + 1)
		{
			img_pixel_put(mlx, round(p0.x + i * step.x),
				round(p0.y + i * step.y), 0xFFFFFF);
			i++;
		}
	}
}

/*
 * Draws the map by connecting adjacent points with lines.
 */
void	draw_map(t_mlx *mlx)
{
	t_map	m;
	int		i;
	int		j;

	m = mlx->map;
	i = -1;
	while (++i < m.dimensions.y - 1)
	{
		j = -1;
		while (++j < m.dimensions.x - 1)
		{
			draw_line(mlx, m.points[i * m.dimensions.x + j],
				m.points[i * m.dimensions.x + (j + 1)]);
			draw_line(mlx, m.points[i * m.dimensions.x + j],
				m.points[(i + 1) * m.dimensions.x + j]);
		}
		draw_line(mlx, m.points[i * m.dimensions.x + j],
			m.points[(i + 1) * m.dimensions.x + j]);
	}
	j = -1;
	while (++j < m.dimensions.x - 1)
		draw_line(mlx, m.points[i * m.dimensions.x + j],
			m.points[i * m.dimensions.x + (j + 1)]);
}
