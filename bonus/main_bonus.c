/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:44:38 by brensant          #+#    #+#             */
/*   Updated: 2025/10/11 11:51:46 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "mlx.h"
#include "libft.h"

#include "draw_bonus.h"
#include "header_bonus.h"
#include "input_utils_bonus.h"
#include "mlx_utils_bonus.h"

void	draw_and_render(t_mlx *mlx)
{
	img_clear_window(mlx);
	draw_map(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

static int	close_window(t_mlx *mlx)
{
	finish_mlx(mlx, EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_mlx	mlx;

	if (argc == 2)
	{
		parse_map(argv[1], &mlx.map);
		init_mlx(&mlx);
		mlx_hook(mlx.win_ptr, 2, (1L << 0), handle_keypress, &mlx);
		mlx_hook(mlx.win_ptr, 4, (1L << 2), handle_mousepress, &mlx);
		mlx_hook(mlx.win_ptr, 17, 0, close_window, &mlx);
		draw_and_render(&mlx);
		mlx_loop(mlx.mlx_ptr);
		finish_mlx(&mlx, EXIT_SUCCESS);
	}
	return (0);
}
