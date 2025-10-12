/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:16:53 by brensant          #+#    #+#             */
/*   Updated: 2025/10/11 21:17:10 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_UTILS_H
# define ENV_UTILS_H

# include "common.h"

void	env_clear_window(t_env *env);
void	env_pixel_put(t_env *env, int x, int y, int color);
void	env_finish(t_env *env, int exit_status);
void	env_init(t_env *env);

#endif
