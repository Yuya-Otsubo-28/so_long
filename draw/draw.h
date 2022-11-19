#ifndef DRAW_H
#define DRAW_H

#include "../error/error.h"
#include "../src/map/map.h"
#include "../gnl/get_next_line.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include "../src/struct.h"

#define WPB 50
#define HPB 50
#define P_ON_C '2'
#define P_ON_E '3'
#define OLD_C '4'


void draw(t_map *map, t_mlx *mlx, t_img *img);

#endif