/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:00:17 by brensant          #+#    #+#             */
/*   Updated: 2025/10/14 17:33:18 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_BONUS_H
# define INPUT_BONUS_H

# include "common_bonus.h"

int	handle_keypress(int keysym, t_env *env);
int	handle_mousepress(int keysym, int x, int y, t_env *env);

#endif
