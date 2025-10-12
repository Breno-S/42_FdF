/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:16:53 by brensant          #+#    #+#             */
/*   Updated: 2025/10/12 02:26:21 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_BONUS_H
# define ENV_UTILS_BONUS_H

# include "common_bonus.h"

void	env_clear_window(t_env *env);
void	env_pixel_put(t_env *env, int x, int y, int color);
void	env_finish(t_env *env, int exit_status);
void	env_init(t_env *env);
void	draw_and_render(t_env *env);

#endif
