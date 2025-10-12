/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <brensant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:00:17 by brensant          #+#    #+#             */
/*   Updated: 2025/10/11 22:51:21 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_UTILS_BONUS_H
# define INPUT_UTILS_BONUS_H

int	handle_keypress(int keysym, t_env *mlx);
int	handle_mousepress(int keysym, int x, int y, t_env *mlx);

#endif
