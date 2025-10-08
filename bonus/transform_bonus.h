/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:05 by brensant          #+#    #+#             */
/*   Updated: 2025/10/08 16:45:17 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_BONUS_H
# define TRANSFORM_BONUS_H

# include "header_bonus.h"

enum e_axis
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS
};

t_point3	point3_translate(t_point3 point, t_point3 offset);
t_point3	point3_scale(t_point3 point, int scalar);
t_point3	point3_rotate(t_point3 point, t_vector3 angle_rad);
t_point3	point3_iso(t_point3 point);

#endif
