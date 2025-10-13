/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:55:23 by brensant          #+#    #+#             */
/*   Updated: 2025/10/13 16:20:35 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "libft.h"

#include "common_bonus.h"
#include "fdf_utils_bonus.h"
#include "transform_bonus.h"

static void	get_map_dimensions(const char *filename, t_map *map)
{
	int		fd;
	char	*line;
	char	**line_split;
	int		num_words;

	fd = open_file_r(filename);
	map->dimensions.x = -1;
	map->dimensions.y = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_split = ft_split(line, ' ');
		num_words = count_split(line_split);
		if (num_words > map->dimensions.x)
			map->dimensions.x = num_words;
		ft_free_split(line_split);
		free(line);
		line = get_next_line(fd);
		map->dimensions.y++;
	}
	close(fd);
}

static void	extract_values(char **line_split, int row, t_map *map)
{
	int	cols;

	cols = 0;
	while (cols < map->dimensions.x)
	{
		map->points[row][cols].x = cols - (map->dimensions.x / 2);
		map->points[row][cols].y = row - (map->dimensions.y / 2);
		if (*line_split)
		{
			map->points[row][cols].z = ft_atoi(*line_split);
			line_split++;
		}
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
	if (map.dimensions.x + map.dimensions.y < 3)
	{
		ft_putendl_fd("Error: Invalid map", 1);
		exit(EXIT_FAILURE);
	}
	ft_putendl_fd("Parsing map from file...", 1);
	map.points = allocate_points_matrix(map.dimensions.y, map.dimensions.x);
	if (!map.points)
		exit(EXIT_FAILURE);
	get_map_points(filename, &map);
	map.offset = vector3_zero();
	map.angle_rad = vector3_zero();
	map.scale = 10.0F;
	map.z_scale = 1.0F;
	map.view = ISO;
	return (map);
}
