/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:23:34 by brensant          #+#    #+#             */
/*   Updated: 2025/10/10 16:46:46 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "libft.h"

#include "header_bonus.h"

/*
 * Frees a matrix of `t_vector3` returned by `allocate_points_matrix()`.
 */
void	free_points_matrix(t_vector3 **matrix)
{
	free(matrix[0]);
	free(matrix);
}

/*
 * Allocates a contiguous 2D matrix of type `t_vector3`.
 */
t_vector3	**allocate_points_matrix(int rows, int columns)
{
	t_vector3	**matrix;
	int			i;

	matrix = ft_calloc(rows, sizeof(*matrix));
	if (!matrix)
		return (NULL);
	matrix[0] = ft_calloc(rows * columns, sizeof(**matrix));
	if (!matrix[0])
	{
		free(matrix);
		return (NULL);
	}
	i = 1;
	while (i < rows)
	{
		matrix[i] = matrix[0] + i * columns;
		i++;
	}
	return (matrix);
}

/*
 * Frees a null-terminated array of strings,
 * like the ones returned by `ft_split()`.
 */
void	free_split(char	**split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

/*
 * Counts the number of elements present in a null-terminated array of strings,
 * like the ones returned by `ft_split()`.
 *
 * Returns:
 * - Number of strings in the array.
 */
int	count_split(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}

/*
 * Opens the given file in read-only mode. Exits the program
 * in case of errors.
 *
 * Returns:
 * - File descriptor.
 */
int	open_file_r(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("open() failed");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
