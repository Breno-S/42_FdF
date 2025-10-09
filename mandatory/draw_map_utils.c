/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 19:56:11 by brensant          #+#    #+#             */
/*   Updated: 2025/10/09 19:57:29 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

float	get_z_middle(t_map *map)
{
	int	z_max;
	int	z_min;
	int	i;
	int	j;

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
	return ((z_max - z_min) / 2);
}
