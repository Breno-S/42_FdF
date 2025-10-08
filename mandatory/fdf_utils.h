/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:25:12 by brensant          #+#    #+#             */
/*   Updated: 2025/10/06 16:13:36 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_H
# define FDF_UTILS_H

# include "header.h"

void		free_point_matrix(t_point3 **matrix);
t_point3	**allocate_point_matrix(int rows, int columns);
void		free_split(char	**split);
int			count_split(char **split);
int			open_file_r(const char *filename);

#endif
