/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 15:39:10 by brensant          #+#    #+#             */
/*   Updated: 2025/10/11 21:16:28 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "common.h"
#include "env_utils.h"

static void	draw_line_low(t_env *env, t_point2 p0, t_point2 p1)
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
		env_pixel_put(env, p0.x, p0.y, 0xFFFFFF);
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

static void	draw_line_high(t_env *env, t_point2 p0, t_point2 p1)
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
		env_pixel_put(env, p0.x, p0.y, 0xFFFFFF);
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
void	draw_line(t_env *env, t_vector3 v0, t_vector3 v1)
{
	t_point2	p0;
	t_point2	p1;

	p0.x = (int)roundf(v0.x);
	p0.y = (int)roundf(v0.y);
	p1.x = (int)roundf(v1.x);
	p1.y = (int)roundf(v1.y);
	if (fabs(v1.y - v0.y) < fabs(v1.x - v0.x))
	{
		if (p0.x > p1.x)
			draw_line_low(env, p1, p0);
		else
			draw_line_low(env, p0, p1);
	}
	else
	{
		if (p0.y > p1.y)
			draw_line_high(env, p1, p0);
		else
			draw_line_high(env, p0, p1);
	}
}
