/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:44:38 by brensant          #+#    #+#             */
/*   Updated: 2025/09/25 18:04:09 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"

typedef struct s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
}	t_mlx;

int	handle_no_event(void *mlx)
{
	return (0);
}

int	handle_input(int keysym, t_mlx *mlx)
{
	if (keysym == 0xff1b)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	return (0);
}

int	main(void)
{
	t_mlx mlx;

	mlx.mlx_ptr = mlx_init();
	if (!mlx.mlx_ptr)
		return (1);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 720, 720, "Fil de Fer");
	if (!mlx.win_ptr)
	{
		free(mlx.mlx_ptr);
		return (1);
	}
	mlx_loop_hook(mlx.mlx_ptr, &handle_no_event, &mlx);
	mlx_key_hook(mlx.win_ptr, &handle_input, &mlx);
	mlx_loop(mlx.mlx_ptr);
	mlx_destroy_display(mlx.mlx_ptr);
	free(mlx.mlx_ptr);
	return (0);
}
