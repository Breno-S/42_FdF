/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:25:12 by brensant          #+#    #+#             */
/*   Updated: 2025/10/13 23:12:20 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_BONUS_H
# define FDF_UTILS_BONUS_H

# include "common_bonus.h"

void		free_points_matrix(t_vertex **matrix);
t_vertex	**allocate_points_matrix(int rows, int columns);
int			count_split(char **split);
int			open_file_r(const char *filename);
t_map		parse_map(const char *filename);

#endif
