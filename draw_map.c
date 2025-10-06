/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:20:31 by brensant          #+#    #+#             */
/*   Updated: 2025/10/06 16:58:15 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "draw.h"
#include "header.h"
#include "mlx_utils.h"
#include "transform.h"

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
			draw_line(mlx, mlx->map.points[i][j], mlx->map.points[i][j + 1]);
			draw_line(mlx, mlx->map.points[i][j], mlx->map.points[i + 1][j]);
		}
		draw_line(mlx, mlx->map.points[i][j], mlx->map.points[i + 1][j]);
	}
	j = -1;
	while (++j < mlx->map.dimensions.x - 1)
		draw_line(mlx, mlx->map.points[i][j], mlx->map.points[i][j + 1]);
}
