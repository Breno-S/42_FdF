/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:05 by brensant          #+#    #+#             */
/*   Updated: 2025/10/10 01:33:06 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "header.h"

# define COS_30 0.86602540378
# define SIN_30 0.5

enum e_axis
{
	X_AXIS,
	Y_AXIS,
	Z_AXIS
};

t_vector3	vector3_translate(t_vector3 point, t_vector3 offset);
t_vector3	vector3_scale(t_vector3 point, int scalar);
t_vector3	vector3_iso(t_vector3 point);

#endif
