/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:44:38 by brensant          #+#    #+#             */
/*   Updated: 2025/10/14 17:24:38 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "libft.h"
#include "mlx.h"

#include "common_bonus.h"
#include "env_utils_bonus.h"
#include "fdf_utils_bonus.h"
#include "input_bonus.h"

static int	close_window(t_env *env)
{
	env_finish(env, EXIT_SUCCESS);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_env	env;
	t_map	map;

	if (argc == 2)
	{
		map = parse_map(argv[1]);
		env_init(&env, &map);
		mlx_hook(env.win_ptr, 2, (1L << 0), handle_keypress, &env);
		mlx_hook(env.win_ptr, 4, (1L << 2), handle_mousepress, &env);
		mlx_hook(env.win_ptr, 17, 0, close_window, &env);
		env_draw_and_render(&env);
		mlx_loop(env.mlx_ptr);
		env_finish(&env, EXIT_SUCCESS);
	}
	return (0);
}
