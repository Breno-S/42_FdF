/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:44:38 by brensant          #+#    #+#             */
/*   Updated: 2025/10/11 23:01:35 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "mlx.h"
#include "libft.h"

#include "draw_bonus.h"
#include "common_bonus.h"
#include "input_utils_bonus.h"
#include "env_utils_bonus.h"

void	draw_and_render(t_env *env)
{
	env_clear_window(env);
	draw_map(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
}

static int	close_window(t_env *mlx)
{
	env_finish(mlx, EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_env	env;

	if (argc == 2)
	{
		parse_map(argv[1], &env.map);
		env_init(&env);
		mlx_hook(env.win_ptr, 2, (1L << 0), handle_keypress, &env);
		mlx_hook(env.win_ptr, 4, (1L << 2), handle_mousepress, &env);
		mlx_hook(env.win_ptr, 17, 0, close_window, &env);
		draw_and_render(&env);
		mlx_loop(env.mlx_ptr);
		env_finish(&env, EXIT_SUCCESS);
	}
	return (0);
}
