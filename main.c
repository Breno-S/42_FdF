/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:44:38 by brensant          #+#    #+#             */
/*   Updated: 2025/10/02 15:43:20 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "mlx.h"

#include "header.h"
#include "mlx_utils.h"
#include "draw.h"

int	render(t_mlx *mlx)
{
	if (mlx->win_ptr)
	{
		draw_map(mlx);
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

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc == 2)
		parse_map(argv[1], &mlx.map);
	init_mlx(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, render, &mlx);
	mlx_hook(mlx.win_ptr, 2, (1L << 0), handle_keypress, &mlx);
	mlx_hook(mlx.win_ptr, 3, (1L << 1), handle_keyrelease, &mlx);
	mlx_loop(mlx.mlx_ptr);
	finish_mlx(&mlx, EXIT_SUCCESS);
	return (0);
}
