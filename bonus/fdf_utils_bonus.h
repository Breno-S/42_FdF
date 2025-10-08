/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 13:25:12 by brensant          #+#    #+#             */
/*   Updated: 2025/10/08 16:42:13 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_UTILS_BONUS_H
# define FDF_UTILS_BONUS_H

# include "header_bonus.h"

void		free_point_matrix(t_point3 **matrix);
t_point3	**allocate_point_matrix(int rows, int columns);
void		free_split(char	**split);
int			count_split(char **split);
int			open_file_r(const char *filename);

#endif
