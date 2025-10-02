/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:23:34 by brensant          #+#    #+#             */
/*   Updated: 2025/10/02 14:39:45 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

/*
 * Frees a null-terminated array of strings,
 * like the ones returned by `ft_split()`.
 *
 */
void	free_split(char	**split)
{
	int	i;

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
