/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:44:38 by brensant          #+#    #+#             */
/*   Updated: 2025/10/11 21:32:42 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>

#include "libft.h"
#include "mlx.h"

#include "draw.h"
#include "common.h"
#include "env_utils.h"
#include "fdf_utils.h"

static int	close_window(t_env *env)
{
	env_finish(env, EXIT_SUCCESS);
	return (0);
}

static int	draw_and_render(t_env *env)
{
	env_clear_window(env);
	draw_map(env);
	mlx_put_image_to_window(env->mlx_ptr, env->win_ptr, env->img_ptr, 0, 0);
	return (0);
}

static int	handle_keypress(int keysym, t_env *env)
{
	if (keysym == 0xff1b)
		env_finish(env, EXIT_SUCCESS);
	return (0);
}

static int	handle_mousepress(int keysym, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (keysym == 0x4)
	{
		env->map.scale *= 1.1;
		if (env->map.scale > SC_H)
		{
			env->map.scale = (float)SC_H;
			return (0);
		}
		return (draw_and_render(env));
	}
	else if (keysym == 0x5)
	{
		env->map.scale /= 1.1F;
		if (env->map.scale < 1.0F)
		{
			env->map.scale = 1.0F;
			return (0);
		}
		return (draw_and_render(env));
	}
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
		mlx_expose_hook(env.win_ptr, draw_and_render, &env);
		mlx_hook(env.win_ptr, 17, 0, close_window, &env);
		draw_and_render(&env);
		mlx_loop(env.mlx_ptr);
		env_finish(&env, EXIT_SUCCESS);
	}
	else
	{
		ft_putendl_fd("Usage: ./fdf <file.fdf>", 1);
		return (EXIT_SUCCESS);
	}
	return (EXIT_SUCCESS);
}
