/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:07:10 by brensant          #+#    #+#             */
/*   Updated: 2025/10/09 18:34:06 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# define SC_W 1600
# define SC_H 900

typedef struct s_point2
{
	int	x;
	int	y;
}	t_point2;

typedef struct s_point3
{
	int	x;
	int	y;
	int	z;
}	t_point3;

typedef struct s_vector2
{
	float	x;
	float	y;
}	t_vector2;

typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

typedef struct s_map
{
	t_point3	**points;
	t_point2	dimensions;
	int			scale;
}	t_map;

/*
 * |  MEMBER   | UNDERLYING TYPE | CONTENTS                                |
 * | --------- | --------------- | --------------------------------------- |
 * | mlx_ptr   | `t_xvar`        | Display + metadata                      |
 * | win_ptr   | `t_win_list`    | Window + metadata                       |
 * | img_ptr   | `t_img`         | Image + metadata                        |
 * | img_addr  | `char *`        | Pointer to Image data (array of pixels) |
 * | bit_depth | `int`           | Image bits per pixel                    |
 * | line_len  | `int`           | Image bytes per line                    |
 * | endian    | `int`           | System byte order (0 -> LE, !0 -> BE)   |
 * | map       | `t_map`         | FdF map to render                       |
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
	t_map	map;
}	t_mlx;

void		parse_map(const char *filename, t_map *map);

#endif
