/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:55:23 by brensant          #+#    #+#             */
/*   Updated: 2025/10/14 01:42:07 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "libft.h"

#include "common_bonus.h"
#include "fdf_utils_bonus.h"
#include "transform_bonus.h"

static int	extract_color(char *z_color)
{
	char	**z_color_split;
	int		color;
	int		i;

	color = 0xFFFFFF;
	if (!z_color)
		return (0);
	z_color_split = ft_split(z_color, ',');
	if (!z_color_split)
		return (0);
	if (z_color_split[1] && z_color_split[1][0] == '0'
		&& ft_tolower(z_color_split[1][1]) == 'x')
	{
		i = 0;
		while (z_color_split[1][2 + i])
		{
			z_color_split[1][2 + i] = ft_tolower(z_color_split[1][2 + i]);
			i++;
		}
		color = ft_atoi_base(&z_color_split[1][2], "0123456789abcdef");
	}
	ft_free_split(z_color_split);
	return (color);
}

static void	get_map_dimensions(const char *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	**line_split;
	int		num_words;

	fd = open_file_r(filename);
	map->rows = 0;
	map->columns = -1;
	line = get_next_line(fd);
	while (line)
	{
		line_split = ft_split(line, ' ');
		num_words = count_split(line_split);
		if (num_words > map->columns)
			map->columns = num_words;
		ft_free_split(line_split);
		free(line);
		line = get_next_line(fd);
		map->rows++;
	}
	close(fd);
}

static void	extract_values(char **line_split, int row, t_map *map)
{
	int	cols;

	cols = 0;
	while (cols < map->columns)
	{
		map->vertices[row][cols].pos.x = cols - (map->columns / 2);
		map->vertices[row][cols].pos.y = row - (map->rows / 2);
		if (*line_split)
		{
			map->vertices[row][cols].pos.z = ft_atoi(*line_split);
			map->vertices[row][cols].color.value = extract_color(*line_split);
			line_split++;
		}
		else
			map->vertices[row][cols].color.value = 0xFFFFFF;
		cols++;
	}
}

static void	get_map_points(const char *filename, t_map *map)
{
	int			fd;
	char		*line;
	char		**line_split;
	int			row;

	fd = open_file_r(filename);
	row = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_split = ft_split(line, ' ');
		extract_values(line_split, row, map);
		ft_free_split(line_split);
		free(line);
		line = get_next_line(fd);
		row++;
	}
	close(fd);
}

/*
 * Reads the .fdf file and saves the data into the `map` variable.
 * Exits the program in case of errors.
 *
 * For optimization reasons, it automatically centers (translates) the
 * map vertices around the origin (0, 0).
 */
t_map	parse_map(const char *filename)
{
	t_map	map;

	get_map_dimensions(filename, &map);
	if (map.columns + map.rows < 3)
	{
		ft_putendl_fd("Error: Invalid map", 1);
		exit(EXIT_FAILURE);
	}
	ft_putendl_fd("Parsing map from file...", 1);
	map.vertices = allocate_points_matrix(map.rows, map.columns);
	if (!map.vertices)
		exit(EXIT_FAILURE);
	get_map_points(filename, &map);
	map.offset = vector3_zero();
	map.angle_rad = vector3_zero();
	map.scale = 10.0F;
	map.z_scale = 1.0F;
	map.view = ISO;
	return (map);
}
