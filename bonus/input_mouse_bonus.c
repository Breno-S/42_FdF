/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_mouse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 19:48:43 by brensant          #+#    #+#             */
/*   Updated: 2025/10/13 15:58:01 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_bonus.h"
#include "env_utils_bonus.h"

int	handle_mousepress(int keysym, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (keysym == 0x4)
	{
		env->map->scale *= 1.1;
		if (env->map->scale > SC_H)
		{
			env->map->scale = (float)SC_H;
			return (0);
		}
		env_draw_and_render(env);
	}
	else if (keysym == 0x5)
	{
		env->map->scale /= 1.1F;
		if (env->map->scale < 1.0F)
		{
			env->map->scale = 1.0F;
			return (0);
		}
		env_draw_and_render(env);
	}
	return (0);
}
