/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:44:38 by brensant          #+#    #+#             */
/*   Updated: 2025/10/10 08:59:56 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"
#include "mlx.h"

#include "draw.h"
#include "header.h"
#include "mlx_utils.h"

static int	render(t_mlx *mlx)
{
	if (mlx->win_ptr)
	{
		draw_map(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	}
	return (0);
}

static int	close_window(t_mlx *mlx)
{
	finish_mlx(mlx, EXIT_SUCCESS);
	return (0);
}

static int	handle_keypress(int keysym, t_mlx *mlx)
{
	if (keysym == 0xff1b)
		finish_mlx(mlx, EXIT_SUCCESS);
	return (0);
}

static int	handle_mousepress(int keysym, int x, int y, void *data)
{
	t_mlx	*mlx;

	(void)x;
	(void)y;
	mlx = (t_mlx *)data;
	if (!mlx)
		return (0);
	if (keysym == 0x4)
	{
		mlx->map.scale *= 1.1;
		img_clear_window(mlx);
	}
	else if (keysym == 0x5)
	{
		mlx->map.scale /= 1.1;
		img_clear_window(mlx);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc == 2)
	{
		parse_map(argv[1], &mlx.map);
		init_mlx(&mlx);
		mlx_loop_hook(mlx.mlx_ptr, render, &mlx);
		mlx_hook(mlx.win_ptr, 2, (1L << 0), handle_keypress, &mlx);
		mlx_hook(mlx.win_ptr, 4, (1L << 2), handle_mousepress, &mlx);
		mlx_hook(mlx.win_ptr, 17, 0, close_window, &mlx);
		draw_map(&mlx);
		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
		mlx_loop(mlx.mlx_ptr);
		finish_mlx(&mlx, EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd("Usage: ./fdf <file.fdf>\n", 1);
		return (1);
	}
	return (0);
}
