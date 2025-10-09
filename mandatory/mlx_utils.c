/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:16:42 by brensant          #+#    #+#             */
/*   Updated: 2025/10/09 18:39:57 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "mlx.h"

#include "fdf_utils.h"
#include "header.h"
#include "libft.h"

/*
 * Sets every Image pixel to black and sends it to the Window.
 */
void	img_clear_window(t_mlx *mlx)
{
	if (mlx->img_ptr && mlx->img_addr)
	{
		ft_bzero(mlx->img_addr, SC_W * SC_H * mlx->bit_depth / 8);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
}

/*
 * Colors the (x, y) pixel in the Image associated with
 * `mlx` in the given color.
 */
void	img_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*addr;
	int		i;

	if (x > SC_W || y > SC_H || x < 0 || y < 0)
		return ;
	addr = mlx->img_addr + (y * mlx->line_len + x * mlx->bit_depth / 8);
	i = mlx->bit_depth - 8;
	while (i >= 0)
	{
		if (mlx->endian != 0)
			*addr = (color >> i) & 0xFF;
		else
			*addr = (color >> (mlx->bit_depth - 8 - i)) & 0xFF;
		addr++;
		i -= 8;
	}
}

/*
 * Safely destroys the Display, Image and Window needed for the program.
 * Also frees up all the the allocated map points.
 */
void	finish_mlx(t_mlx *mlx, int exit_status)
{
	if (mlx->map.points)
		free_point_matrix(mlx->map.points);
	if (mlx->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	exit(exit_status);
}

/*
 * Creates the Display, Window and Image needed for the program.
 * Also initializes the map state properties.
 *
 * Exits the program in case of errors.
 */
void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		finish_mlx(mlx, EXIT_FAILURE);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, SC_W, SC_H, "Fil de Fer");
	if (!mlx->win_ptr)
		finish_mlx(mlx, EXIT_FAILURE);
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, SC_W, SC_H);
	if (!mlx->img_ptr)
		finish_mlx(mlx, EXIT_FAILURE);
	mlx->img_addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bit_depth,
			&mlx->line_len, &mlx->endian);
	if (!mlx->img_addr)
		finish_mlx(mlx, EXIT_FAILURE);
	mlx->map.scale = 10;
}
