/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:48:16 by yotsubo           #+#    #+#             */
/*   Updated: 2022/11/21 17:48:37 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include "libft.h"
# include "map.h"
# include "struct.h"
# include <stdarg.h>

# define ARGS_ERROR 0
# define FILENAME_ERROR 1
# define INPUT_ERROR 2
# define MALLOC_ERROR 3
# define MLX_ERROR 4

void	free_double_ptr(char **ptr, size_t count);

void	free_double_ptr_int(int **ptr, size_t i);

void	error_handle(int error_num, ...);

void	error_mlx_init(t_map *map);

void	error_win_init(t_mlx *mlx, t_map *map);

void	error_init_floor(t_mlx *mlx, t_map *map);
#endif
