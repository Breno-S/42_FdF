/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:07:10 by brensant          #+#    #+#             */
/*   Updated: 2025/09/29 17:45:10 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define SC_W 1600
# define SC_H 900

/*
 * MEMBER    |  UNDERLYING TYPE  | CONTENTS
 * mlx_ptr   |       t_xvar      | Display + metadata
 * win_ptr   |     t_win_list    | Window + metadata
 * img_ptr   |       t_img       | Image + metadata
 * ----------+-------------------+----------------------------------------------
 * img_addr  |       char *      | Pointer to Image data (array of pixels)
 * bit_depth |        int        | Image bits per pixel
 * line_len  |        int        | Image bytes per line
 * endian    |        int        | System byte order (0 -> LE, !0 -> BE)
 */
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bit_depth;
	int		line_len;
	int		endian;
}	t_mlx;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

void	img_pixel_put(t_mlx *mlx, int x, int y, int color);
void	draw_line(t_mlx *mlx, t_point p0, t_point p1);

#endif
