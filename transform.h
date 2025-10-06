/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:05 by brensant          #+#    #+#             */
/*   Updated: 2025/10/06 20:08:47 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "header.h"

enum e_axis
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS
};

t_point3	point3_translate(t_point3 point, t_point3 offset);
t_point3	point3_scale(t_point3 point, int scalar);
t_point3	point3_rotate(t_point3 point, float theta, enum e_axis axis);
t_point3	point3_iso(t_point3 point);

#endif
