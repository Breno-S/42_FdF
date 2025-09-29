/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:44:38 by brensant          #+#    #+#             */
/*   Updated: 2025/09/28 21:49:12 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "mlx.h"

#define SC_W 1600
#define SC_H 900

/*
 * MEMBER    |  UNDERLYING TYPE  | CONTENTS
 * mlx_ptr   |       t_xvar      | Display + metadata
 * win_ptr   |     t_win_list    | Window + metadata
 * img_ptr   |       t_img       | Image + metadata
 * ----------+-------------------+----------------------------------------------
 * img_addr  |       char *      | Pointer to Image data (array of pixels)
 * bit_depth |        int        | Image bits per pixel
 * line_len  |        int        | Image bytes per line
 * endian    |        int        | System byte order (0 -> LE, !0 -> BE)
 */
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bit_depth;
	int		line_len;
	int		endian;
}	t_mlx;

void	finish_mlx(t_mlx *mlx, int exit_status)
{
	if (mlx->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->win_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
	}
	exit(exit_status);
}

static void	init_image(t_mlx *mlx, int width, int height)
{
	if (mlx)
	{
		mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, width, height);
		mlx->img_addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bit_depth,
				&mlx->line_len, &mlx->endian);
	}
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		finish_mlx(mlx, EXIT_FAILURE);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, SC_W, SC_H, "Fil de Fer");
	if (!mlx->win_ptr)
		finish_mlx(mlx, EXIT_FAILURE);
	init_image(mlx, SC_W, SC_H);
	if (!mlx->img_ptr)
		finish_mlx(mlx, EXIT_FAILURE);
}

void	img_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*addr;
	int		i;

	if (x > SC_W || y > SC_H)
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

int	render(t_mlx *mlx)
{
	if (mlx->win_ptr)
	{
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	return (0);
}

int	handle_keypress(int keysym, t_mlx *mlx)
{
	printf("KeyPress: %#x\n", keysym);
	if (keysym == 0xff1b)
		finish_mlx(mlx, EXIT_SUCCESS);
	return (0);
}

int	handle_keyrelease(int keysym, t_mlx *mlx)
{
	printf("KeyRelease: %#x\n", keysym);
	return (0 && mlx);
}

int	main(void)
{
	t_mlx	mlx;

	init_mlx(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, render, &mlx);
	mlx_hook(mlx.win_ptr, 2, (1L << 0), handle_keypress, &mlx);
	mlx_hook(mlx.win_ptr, 3, (1L << 1), handle_keyrelease, &mlx);
	mlx_loop(mlx.mlx_ptr);
	finish_mlx(&mlx, EXIT_SUCCESS);
	return (0);
}
