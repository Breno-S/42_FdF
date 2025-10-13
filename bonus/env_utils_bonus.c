/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:16:42 by brensant          #+#    #+#             */
/*   Updated: 2025/10/13 16:29:57 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"
#include "mlx.h"

#include "common_bonus.h"
#include "draw_bonus.h"
#include "fdf_utils_bonus.h"

/*
 * Draws the Image based on the `map` member variable and sends it
 * to the Window, updating the frame being displayed.
 */
void	env_draw_and_render(t_env *env)
{
	if (env->img_ptr && env->img_addr)
	{
		ft_bzero(env->img_addr, SC_W * SC_H * env->bit_depth / 8);
		mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	}
	draw_map(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

/*
 * Colors the (x, y) pixel in the Image associated with
 * `mlx` in the given color.
 */
void	env_pixel_put(t_env *env, int x, int y, int color)
{
	char	*addr;
	int		i;

	if (x > SC_W || y > SC_H || x < 0 || y < 0)
		return ;
	addr = env->img_addr + (y * env->line_len + x * env->bit_depth / 8);
	i = env->bit_depth - 8;
	while (i >= 0)
	{
		if (env->endian != 0)
			*addr = (color >> i) & 0xFF;
		else
			*addr = (color >> (env->bit_depth - 8 - i)) & 0xFF;
		addr++;
		i -= 8;
	}
}

/*
 * Safely destroys the Display, Image and Window needed for the program.
 * Also frees up all the the allocated map points.
 */
void	env_finish(t_env *env, int exit_status)
{
	if (env->map && env->map->points)
		free_points_matrix(env->map->points);
	if (env->img_ptr)
		mlx_destroy_image(env->mlx_ptr, env->img_ptr);
	if (env->win_ptr)
		mlx_destroy_window(env->mlx_ptr, env->win_ptr);
	if (env->mlx_ptr)
	{
		mlx_destroy_display(env->mlx_ptr);
		free(env->mlx_ptr);
	}
	exit(exit_status);
}

/*
 * Creates the Display, Window and Image needed for the program
 * and assigns `map` to the map variable inside `env`.
 *
 * Exits the program in case of errors.
 */
void	env_init(t_env *env, t_map *map)
{
	if (!env || !map)
		env_finish(env, EXIT_FAILURE);
	env->mlx_ptr = mlx_init();
	if (!env->mlx_ptr)
		env_finish(env, EXIT_FAILURE);
	env->win_ptr = mlx_new_window(env->mlx_ptr, SC_W, SC_H, "Fil de Fer");
	if (!env->win_ptr)
		env_finish(env, EXIT_FAILURE);
	env->img_ptr = mlx_new_image(env->mlx_ptr, SC_W, SC_H);
	if (!env->img_ptr)
		env_finish(env, EXIT_FAILURE);
	env->img_addr = mlx_get_data_addr(env->img_ptr, &env->bit_depth,
			&env->line_len, &env->endian);
	if (!env->img_addr)
		env_finish(env, EXIT_FAILURE);
	env->map = map;
}
