/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:10:36 by brensant          #+#    #+#             */
/*   Updated: 2025/09/29 17:42:58 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "mlx.h"
#include "header.h"

void	draw_line(t_mlx *mlx, t_point p0, t_point p1)
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
