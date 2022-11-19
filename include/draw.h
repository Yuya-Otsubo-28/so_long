#ifndef DRAW_H
#define DRAW_H

#include "error.h"
#include "map.h"
#include "get_next_line.h"
#include "libft.h"
#include "../mlx/mlx.h"
#include "struct.h"

#define WPB 50
#define HPB 50
#define P_ON_C '2'
#define P_ON_E '3'
#define OLD_C '4'


void draw(t_map *map, t_mlx *mlx, t_img *img);

void draw_marginy(t_pt *margin, t_data *res_data, t_data *f_data);

void draw_marginx(t_pt *pt, t_pt *margin, t_data *res_data, t_data *f_data);

void init_window_image(t_mlx *mlx, t_img *img, t_map *map);
#endif