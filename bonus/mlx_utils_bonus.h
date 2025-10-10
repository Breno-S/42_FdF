/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 15:16:53 by brensant          #+#    #+#             */
/*   Updated: 2025/10/10 16:34:11 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_BONUS_H
# define MLX_UTILS_BONUS_H

# include "header_bonus.h"

void	img_clear_window(t_mlx *mlx);
void	img_pixel_put(t_mlx *mlx, int x, int y, int color);
void	finish_mlx(t_mlx *mlx, int exit_status);
void	init_mlx(t_mlx *mlx);
void	draw_and_render(t_mlx *mlx);

#endif
