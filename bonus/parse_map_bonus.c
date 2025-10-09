/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:55:23 by brensant          #+#    #+#             */
/*   Updated: 2025/10/09 17:16:45 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>

#include "libft.h"

#include "fdf_utils_bonus.h"
#include "header_bonus.h"
#include "transform_bonus.h"

static void	get_map_dimensions(const char *filename, t_map *map)
{
	int			fd;
	char		*line;
	char		**line_split;
	int			num_words;
	t_point2	dimensions;

	fd = open_file_r(filename);
	dimensions.x = -1;
	dimensions.y = 0;
	line = get_next_line(fd);
	while (line)
	{
		line_split = ft_split(line, ' ');
		num_words = count_split(line_split);
		if (dimensions.x == -1)
			dimensions.x = num_words;
		if (num_words > dimensions.x)
			dimensions.x = num_words;
		free_split(line_split);
		free(line);
		line = get_next_line(fd);
		dimensions.y++;
	}
	map->dimensions = dimensions;
	close(fd);
}

static void	extract_values(char **line_split, int row, t_map *map)
{
	int	cols;

	cols = 0;
	while (cols < map->dimensions.x)
	{
		map->points[row][cols].x = cols;
		map->points[row][cols].y = row;
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
		free_split(line_split);
		free(line);
		line = get_next_line(fd);
		row++;
	}
	close(fd);
}

static void	move_centers_to_origin(t_map *map)
{
	t_point3	offset;
	int			z_max;
	int			z_min;
	int			i;
	int			j;

	z_min = map->points[0][0].z;
	z_max = map->points[0][0].z;
	i = 0;
	while (i < map->dimensions.y)
	{
		j = 0;
		while (j < map->dimensions.x)
		{
			if (map->points[i][j].z < z_min)
				z_min = map->points[i][j].z;
			if (map->points[i][j].z > z_max)
				z_max = map->points[i][j].z;
			j++;
		}
		i++;
	}
	offset.x = -(map->dimensions.x / 2);
	offset.y = -(map->dimensions.y / 2);
	offset.z = -((z_max - z_min) / 2);
	i = 0;
	while (i < map->dimensions.y)
	{
		j = 0;
		while (j < map->dimensions.x)
		{
			map->points[i][j] = point3_translate(map->points[i][j], offset);
			j++;
		}
		i++;
	}
}

/*
 * Reads the .fdf file and saves the data into a `t_map` variable.
 * Exits the program in case of errors.
 */
void	parse_map(const char *filename, t_map *map)
{
	get_map_dimensions(filename, map);
	if (map->dimensions.x == 0 || map->dimensions.y == 0)
		exit(EXIT_FAILURE);
	map->points = allocate_point_matrix(map->dimensions.y, map->dimensions.x);
	if (!map->points)
		exit(EXIT_FAILURE);
	get_map_points(filename, map);
	move_centers_to_origin(map);
}
