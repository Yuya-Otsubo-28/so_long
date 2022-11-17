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

void draw(t_map *map);

#endif