/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 16:50:05 by brensant          #+#    #+#             */
/*   Updated: 2025/10/13 13:08:25 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_BONUS_H
# define TRANSFORM_BONUS_H

# include "common_bonus.h"

t_vector3	vector3_zero(void);
t_vector3	vector3_translate(t_vector3 point, t_vector3 offset);
t_vector3	vector3_scale(t_vector3 point, float scalar);
t_vector3	vector3_rotate(t_vector3 point, t_vector3 angle_rad);

#endif
