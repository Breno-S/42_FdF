/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:44:38 by brensant          #+#    #+#             */
/*   Updated: 2025/09/26 21:05:03 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"

#define SC_W 720
#define SC_H 720

/*
 * MEMBER    |  UNDERLYING TYPE  |  CONTENTS
 * mlx_ptr		 t_xvar				Display + info
 * win_ptr		 t_win_list			Window + info
 * img_ptr		 t_img				Image + info
 * img_addr							pointer to the actual image data
 * bit_depth						image's bits per pixel
 * line_len							image's bytes per line
 * endian							how the bytes are organized
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

int	handle_no_event(void *nothing)
{
	return (0 && nothing);
}

int	handle_input(int keysym, t_mlx *mlx)
{
	if (keysym == 0xff1b)
		finish_mlx(mlx, EXIT_SUCCESS);
	return (0);
}

int	main(void)
{
	t_mlx	mlx;

	init_mlx(&mlx);
	mlx_loop_hook(mlx.mlx_ptr, handle_no_event, &mlx);
	mlx_key_hook(mlx.win_ptr, handle_input, &mlx);
	mlx_loop(mlx.mlx_ptr);
	finish_mlx(&mlx, EXIT_SUCCESS);
	return (0);
}
