/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:23:34 by brensant          #+#    #+#             */
/*   Updated: 2025/10/01 16:11:08 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

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
