/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:39:10 by brensant          #+#    #+#             */
/*   Updated: 2025/10/14 01:18:59 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "common_bonus.h"
#include "env_utils_bonus.h"

static int	get_line_color(t_vertex v0, t_vertex v1)
{
	t_color	c0;
	t_color	c1;

	c0 = v0.color;
	c1 = v1.color;
	return ((int)(sqrt((pow(c0.rgba[0], 2) + pow(c1.rgba[0], 2)) / 2))
		+ ((int)(sqrt((pow(c0.rgba[1], 2) + pow(c1.rgba[1], 2)) / 2)) << 8)
		+ ((int)(sqrt((pow(c0.rgba[2], 2) + pow(c1.rgba[2], 2)) / 2)) << 16)
		+ ((int)(sqrt((pow(c0.rgba[3], 2) + pow(c1.rgba[3], 2)) / 2)) << 24));
}

static void	draw_line_low(t_env *mlx, t_point2 p0, t_point2 p1, int color)
{
	t_point2	delta;
	int			diff;
	int			step_y;

	delta.x = p1.x - p0.x;
	delta.y = p1.y - p0.y;
	step_y = 1;
	if (delta.y < 0)
	{
		step_y = -1;
		delta.y = -delta.y;
	}
	diff = 2 * delta.y - delta.x;
	while (p0.x < p1.x)
	{
		env_pixel_put(mlx, p0.x, p0.y, color);
		if (diff > 0)
		{
			p0.y += step_y;
			diff += (2 * (delta.y - delta.x));
		}
		else
			diff += 2 * delta.y;
		p0.x++;
	}
}

static void	draw_line_high(t_env *mlx, t_point2 p0, t_point2 p1, int color)
{
	t_point2	delta;
	int			diff;
	int			step_x;

	delta.x = p1.x - p0.x;
	delta.y = p1.y - p0.y;
	step_x = 1;
	if (delta.x < 0)
	{
		step_x = -1;
		delta.x = -delta.x;
	}
	diff = 2 * delta.x - delta.y;
	while (p0.y < p1.y)
	{
		env_pixel_put(mlx, p0.x, p0.y, color);
		if (diff > 0)
		{
			p0.x += step_x;
			diff += (2 * (delta.x - delta.y));
		}
		else
			diff += 2 * delta.x;
		p0.y++;
	}
}

/*
 * Draws a line from `p0` to `p1` using Bresenham's line algorithm.
 */
void	draw_line(t_env *mlx, t_vertex v0, t_vertex v1)
{
	t_point2	p0;
	t_point2	p1;
	int			color;

	p0.x = (int)roundf(v0.pos.x);
	p0.y = (int)roundf(v0.pos.y);
	p1.x = (int)roundf(v1.pos.x);
	p1.y = (int)roundf(v1.pos.y);
	color = get_line_color(v0, v1);
	if (fabs(v1.pos.y - v0.pos.y) < fabs(v1.pos.x - v0.pos.x))
	{
		if (p0.x > p1.x)
			draw_line_low(mlx, p1, p0, color);
		else
			draw_line_low(mlx, p0, p1, color);
	}
	else
	{
		if (p0.y > p1.y)
			draw_line_high(mlx, p1, p0, color);
		else
			draw_line_high(mlx, p0, p1, color);
	}
}
