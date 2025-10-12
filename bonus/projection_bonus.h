/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 01:25:34 by brensant          #+#    #+#             */
/*   Updated: 2025/10/12 01:54:12 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_BONUS_H
# define PROJECTION_BONUS_H

# include "common_bonus.h"

t_vector3	vector3_iso(t_vector3 v);
t_vector3	vector3_ortho(t_vector3 v, enum e_view view);

#endif
