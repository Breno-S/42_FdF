/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 13:40:56 by brensant          #+#    #+#             */
/*   Updated: 2025/10/02 14:19:47 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "header.h"

void	draw_map(t_mlx *mlx)
{
	t_map	m;
	int		i;
	int		j;

	m = mlx->map;
	for (i = 0; i < m.dimensions.y - 1; i++)
	{
		for (j = 0; j < m.dimensions.x - 1; j++)
		{
			// RIGHT
			draw_line(
				mlx,
				m.points[i * m.dimensions.x + j],
				m.points[i * m.dimensions.x + (j + 1)]
			);
			// DOWN
			draw_line(
				mlx,
				m.points[i * m.dimensions.x + j],
				m.points[(i + 1) * m.dimensions.x + j]
			);
		}
		// DOWN
		draw_line(
			mlx,
			m.points[i * m.dimensions.x + j],
			m.points[(i + 1) * m.dimensions.x + j]
		);
	}
	for (j = 0; j < m.dimensions.x - 1; j++)
	{
		// RIGHT
		draw_line(
			mlx,
			m.points[i * m.dimensions.x + j],
			m.points[i * m.dimensions.x + (j + 1)]
		);
	}
}
