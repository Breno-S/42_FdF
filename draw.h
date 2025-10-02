/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:20:44 by brensant          #+#    #+#             */
/*   Updated: 2025/10/02 15:23:41 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "header.h"

void	draw_line(t_mlx *mlx, t_point3 p0, t_point3 p1);
void	draw_map(t_mlx *mlx);

#endif
