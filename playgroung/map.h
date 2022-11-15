#ifndef MAP_H
#define MAP_H

#include "../mlx/lx.h"
#include "./libft/libft.h"
#include "./gnl/get_next_line.h"

typedef struct s_map
{
    char map_data[5][7];
    int num_of_line;
    int num_of_column;
}   t_map;

void error_handle();

void check_goal(t_map map);