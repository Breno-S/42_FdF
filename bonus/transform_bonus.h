/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:05 by brensant          #+#    #+#             */
/*   Updated: 2025/10/10 16:39:55 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_BONUS_H
# define TRANSFORM_BONUS_H

# include "header_bonus.h"

# define COS_30 0.86602540378
# define SIN_30 0.5

t_vector3	vector3_translate(t_vector3 point, t_vector3 offset);
t_vector3	vector3_scale(t_vector3 point, float scalar);
t_vector3	vector3_rotate(t_vector3 point, t_vector3 angle_rad);
t_vector3	vector3_iso(t_vector3 point);
t_vector3	vector3_ortho(t_vector3 point, enum e_view view);

#endif
