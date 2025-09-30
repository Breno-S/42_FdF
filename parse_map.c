/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 12:55:23 by brensant          #+#    #+#             */
/*   Updated: 2025/09/30 20:03:02 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

#include "fdf_utils.h"
#include "header.h"
#include "libft.h"

static int	get_file_num_lines(const char *filename)
{
	int		fd;
	char	*line;
	int		num_lines;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Error:");
		exit(EXIT_FAILURE);
	}
	num_lines = 0;
	line = get_next_line(fd);
	while (line)
	{
		free(line);
		num_lines++;
		line = get_next_line(fd);
	}
	close(fd);
	return (num_lines);
}

static int	get_file_points_per_line(const char *filename)
{
	int		fd;
	char	*line;
	int		points_per_line;

	points_per_line = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open() failed:");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (line)
	{
		points_per_line = get_w_count(line, ' ');
		free(line);
	}
	return (points_per_line);
}

/*
 * Verifies if the file has a valid (rectangular) map.
 */
static int	is_map_valid(const char *filename)
{
	int		fd;
	char	*line;
	int		points_per_line;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open() failed:");
		exit(EXIT_FAILURE);
	}
	line = get_next_line(fd);
	if (line)
		points_per_line = get_w_count(line, ' ');
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
			if (get_w_count(line, ' ') != points_per_line)
				return (0);
	}
	close(fd);
	return (1);
}

void	fill_map_points(const char *filename, t_map *map)
{
	int		fd;
	char 	*line;
	int		i;
	int		j;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	i = 0;
	line = get_next_line(fd);
	while (i < map->rows && line)
	{
		j = 0;
		while (j < map->cols)
		{
			map->points[i * map->cols + j].x = j;
			map->points[i * map->cols + j].y = i;
			map->points[i * map->cols + j].z = ft_atoi(line);
			line += get_w_len(line, ' ');
			j++;
		}
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
}

/*
 * Reads the .fdf file and saves the data into a `t_map` variable.
 *
 * Returns:
 * - 1 on success
 * - 0 on failure.
 */
int	parse_file(const char *filename, t_map *map)
{
	if (!is_map_valid(filename) || !map)
		return (0);
	map->rows = get_file_num_lines(filename);
	map->cols = get_file_points_per_line(filename);
	map->points = ft_calloc(map->rows * map->cols, sizeof(*(map->points)));
	fill_map_points(filename, map);
	return (1);
}
