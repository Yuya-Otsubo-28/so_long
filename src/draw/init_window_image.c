#include "draw.h"

static void *insert(t_data *tmp_data, t_data *f_data, t_pt *tmp_size, t_mlx *mlx)
{
    t_pt pt;
    void *res;
    t_data res_data;

    res = mlx_new_image(mlx->mlx_ptr, WPB, HPB);
    res_data.addr = (unsigned int *)mlx_get_data_addr(res, &res_data.bpp, &res_data.size_l, &res_data.endian);
    pt.y = 0;    
    while (pt.y < tmp_size->y)
    {
        pt.x = 0;
        while (pt.x < tmp_size->x)
        {
            if (tmp_data->addr[pt.y * tmp_size->x + pt.x] == 0xFF000000)
                res_data.addr[pt.y * tmp_size->x + pt.x] = f_data->addr[pt.y * tmp_size->x + pt.x];
            else
                res_data.addr[pt.y * tmp_size->x + pt.x] = tmp_data->addr[pt.y * tmp_size->x + pt.x];
            pt.x++;
        }
        pt.y++;
    }
    return (res);
}

static void *make_image(t_mlx *mlx, t_data *f_data, char *filename)
{
    void *tmp;
    void *res;
    t_pt tmp_size;
    t_data tmp_data;

    tmp = mlx_xpm_file_to_image(mlx->mlx_ptr, filename, &tmp_size.x, &tmp_size.y);
    tmp_data.addr = (unsigned int *)mlx_get_data_addr(tmp, &tmp_data.bpp, &tmp_data.size_l, &tmp_data.endian);
    res = insert(&tmp_data, f_data, &tmp_size, mlx);
    mlx_destroy_image(mlx->mlx_ptr, tmp);
    return (res);
}

void init_window_image(t_mlx *mlx, t_img *img, t_map *map)
{
    int width;
    int height;
    t_data f_data;

    mlx->mlx_ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, map->num_of_column * WPB, map->num_of_line * HPB, "so_long");
    img->f_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "src/xpm/floor.xpm", &width, &height);
    f_data.addr = (unsigned int *)mlx_get_data_addr(img->f_img, &f_data.bpp, &f_data.size_l, &f_data.endian);
    img->w_img = make_image(mlx, &f_data, "./src/xpm/w.xpm");
    img->c_img = make_image(mlx, &f_data, "./src/xpm/c.xpm");
    img->p_img = make_image(mlx, &f_data, "./src/xpm/p.xpm");
    img->e_img = make_image(mlx, &f_data, "./src/xpm/e.xpm");
    f_data.addr = (unsigned int *)mlx_get_data_addr(img->c_img, &f_data.bpp, &f_data.size_l, &f_data.endian);
    img->p_on_c_img = make_image(mlx, &f_data, "./src/xpm/p.xpm");
    f_data.addr = (unsigned int *)mlx_get_data_addr(img->e_img, &f_data.bpp, &f_data.size_l, &f_data.endian);
    img->p_on_e_img = make_image(mlx, &f_data, "src/xpm/p.xpm");
}