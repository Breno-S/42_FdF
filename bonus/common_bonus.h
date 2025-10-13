/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 16:07:10 by brensant          #+#    #+#             */
/*   Updated: 2025/10/13 15:56:44 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_BONUS_H
# define COMMON_BONUS_H

# define SC_W 1280
# define SC_H 720

# define COS_30 0.86602540378
# define SIN_30 0.5

typedef struct s_point2
{
	int	x;
	int	y;
}	t_point2;

typedef struct s_vector3
{
	float	x;
	float	y;
	float	z;
}	t_vector3;

enum e_view
{
	ISO,
	FRONTAL,
	LATERAL,
	TOP_DOWN
};

typedef struct s_map
{
	t_vector3	**points;
	t_vector3	offset;
	t_vector3	angle_rad;
	t_point2	dimensions;
	float		scale;
	float		z_scale;
	enum e_view	view;
}	t_map;

/*
 * | MEMBER     | UNDERLYING TYPE          | CONTENTS                     |
 * | ---------- | ------------------------ | ---------------------------- |
 * | mlx_ptr    | `void *` -> `t_xvar`     | Display + metadata           |
 * | win_ptr    | `void *` -> `t_win_list` | Window + metadata            |
 * | img_ptr    | `void *` -> `t_img`      | Image + metadata             |
 * | img_addr   | `char *`      | Pointer to Image data (array of pixels) |
 * | bit_depth  | `int`         | Image bits per pixel                    |
 * | line_len   | `int`         | Image bytes per line                    |
 * | endian     | `int`         | System byte order (0 -> LE, !0 -> BE)   |
 * | map        | `t_map *`     | Pointer to FdF map                      |
 */
typedef struct s_env
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bit_depth;
	int		line_len;
	int		endian;
	t_map	*map;
}	t_env;

#endif
