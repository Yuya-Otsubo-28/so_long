/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:48:48 by yotsubo           #+#    #+#             */
/*   Updated: 2022/11/21 17:49:06 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "draw.h"

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define ESC_KEY 65307

void	events(t_mlx *mlx, t_img *img, t_map *map);

void	search_player(t_map *map, t_pt *p);

int		get_c_num(t_map *map);

void	player_move(int move, t_param *param);

void	finish(int key, t_param *param);
#endif
