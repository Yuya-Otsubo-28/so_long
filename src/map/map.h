#ifndef MAP_H
#define MAP_H

#include "../../mlx/mlx.h"
#include "../../libft/libft.h"
#include "../../gnl/get_next_line.h"
#include "../../error/error.h"
#include "../../draw/draw.h"
#include "../struct.h"

t_map map_init(char *filename);

void get_map_data(int fd, t_map *map);

void check_map_data(t_map *map);

void check_goal(t_map *map);

void map_errors(char **ptr, size_t ptr_size, int error_num);

char	*sl_strtrim(char const *s1, char const *set);

#endif