/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:20:44 by brensant          #+#    #+#             */
/*   Updated: 2025/10/11 21:18:42 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "common.h"

void	draw_line(t_env *env, t_vector3 p0, t_vector3 p1);
void	draw_map(t_env *env);

#endif
