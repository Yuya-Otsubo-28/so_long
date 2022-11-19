#include "draw.h"

void draw_map(t_mlx *mlx, t_img *img, t_map *map, t_pt *pt)
{
    pt->x = 0;
    while ((size_t)pt->x < map->num_of_line)
    {
        pt->y = 0;
        while ((size_t)pt->y < map->num_of_column)
        {
            mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->f_img, pt->y * WPB, pt->x * HPB);
            if (map->map_data[pt->x][pt->y] == '1')
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->w_img, pt->y * WPB, pt->x * HPB);
            if (map->map_data[pt->x][pt->y] == 'C' || map->map_data[pt->x][pt->y] == OLD_C)
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->c_img, pt->y * WPB, pt->x * HPB);
            if (map->map_data[pt->x][pt->y] == 'P')
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->p_img, pt->y * WPB, pt->x * HPB);
            if (map->map_data[pt->x][pt->y] == 'E')
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->e_img, pt->y * WPB, pt->x * HPB);
            if (map->map_data[pt->x][pt->y] == P_ON_C)
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->p_on_c_img, pt->y * WPB, pt->x * HPB);
            if (map->map_data[pt->x][pt->y] == P_ON_E)
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->p_on_e_img, pt->y * WPB, pt->x * HPB);
            pt->y++;
        }
        pt->x++;
    }
}

void draw(t_map *map, t_mlx *mlx, t_img *img)
{
    t_pt pt;

    if (!img->c_img)
        init_window_image(mlx, img, map);
    draw_map(mlx, img, map, &pt);
}