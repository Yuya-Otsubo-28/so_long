/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:50:12 by yotsubo           #+#    #+#             */
/*   Updated: 2022/11/21 17:50:30 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "../mlx/mlx.h"
# include "libft.h"
# include "get_next_line.h"
# include "error.h"
# include "draw.h"
# include "struct.h"
# include "events.h"

t_map	map_init(char *filename);

void	get_map_data(int fd, t_map *map);

void	check_map_data(t_map *map);

void	check_goal(t_map *map);

void	map_errors(char **ptr, size_t ptr_size, int error_num);

char	*sl_strtrim(char const *s1, char const *set);

#endif
