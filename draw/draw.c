#include "draw.h"

static void draw_marginy(t_pt *margin, t_data *res_data, t_data *f_data)
{
    int i;
    int j;

    i = 0;
    while (i <= margin->y)
    {
        j = 0;
        while (j <= WPB)
        {
            res_data->addr[i * WPB + j] = f_data->addr[i * WPB + j];
            j++;
        }
        i++;
    }
}

static void draw_marginx(t_pt *pt, t_pt *margin, t_data *res_data, t_data *f_data)
{
    int i;

    if (pt->x == margin->x)
    {
        i = 0;
        while (i <= margin->x)
        {
            res_data->addr[(margin->y + pt->y) + i] = f_data->addr[(margin->y + pt->y) + i];
            i++;
        }
    }
    else if (pt->x > margin->x)
    {
        i = margin->x + pt->x;
        while (i <= WPB)
        {
            res_data->addr[(margin->y + pt->y) + i] = f_data->addr[(margin->y + pt->y) + i];
            i++;
        }
    }
}

static void *insert(t_data *tmp_data, t_data *f_data, t_pt *tmp_size, t_mlx *mlx)
{
    t_pt pt;
    t_pt margin;
    void *res;
    t_data res_data;

    res = mlx_new_image(mlx->mlx_ptr, WPB, HPB);
    res_data.addr = (unsigned int *)mlx_get_data_addr(res, &res_data.bpp, &res_data.size_l, &res_data.endian);
    margin.x = (WPB - tmp_size->x) / 2;
    margin.y = (HPB - tmp_size->y) / 2;
    draw_marginy(&margin, &res_data, f_data);
    pt.y = margin.y;
    while (pt.y < tmp_size->y)
    {
        pt.x = margin.x;
        draw_marginx(&pt, &margin, &res_data, f_data);
        while (pt.x < tmp_size->x)
        {
            if (tmp_data->addr[pt.y * tmp_size->x + pt.x] == 0xFF000000)
                res_data.addr[(margin.y + pt.y) * WPB + (margin.x + pt.x)] = f_data->addr[(margin.y + pt.y) * WPB + (margin.x + pt.x)];
            else
                res_data.addr[(margin.y + pt.y) * WPB + (margin.x + pt.x)] = tmp_data->addr[pt.y * tmp_size->x + pt.x];
            pt.x++;
        }
        draw_marginx(&pt, &margin, &res_data, f_data);
        pt.y++;
    }
    draw_marginy(&margin, &res_data, f_data);
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

static void init_window_image(t_mlx *mlx, t_img *img, t_map *map)
{
    int width;
    int height;
    t_data f_data;

    mlx->mlx_ptr = mlx_init();
    mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, map->num_of_column * WPB, map->num_of_line * HPB, "so_long");
    (void)mlx->win_ptr;
    img->f_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "floor.xpm", &width, &height);
    f_data.addr = (unsigned int *)mlx_get_data_addr(img->f_img, &f_data.bpp, &f_data.size_l, &f_data.endian);
    img->w_img = make_image(mlx, &f_data, "w.xpm");
    img->c_img = make_image(mlx, &f_data, "c.xpm");
    img->p_img = make_image(mlx, &f_data, "p.xpm");
    img->e_img = make_image(mlx, &f_data, "e.xpm");
    f_data.addr = (unsigned int *)mlx_get_data_addr(img->c_img, &f_data.bpp, &f_data.size_l, &f_data.endian);
    img->p_on_c_img = make_image(mlx, &f_data, "p.xpm");
    f_data.addr = (unsigned int *)mlx_get_data_addr(img->e_img, &f_data.bpp, &f_data.size_l, &f_data.endian);
    img->p_on_e_img = make_image(mlx, &f_data, "p.xpm");
}

void draw_map(t_mlx *mlx, t_img *img, t_map *map)
{
    size_t i;
    size_t j;

    i = 0;
    while (i < map->num_of_line)
    {
        j = 0;
        while (j < map->num_of_column)
        {
            mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->f_img, j * WPB, i * HPB);
            if (map->map_data[i][j] == '1')
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->w_img, j * WPB, i * HPB);
            if (map->map_data[i][j] == 'C' || map->map_data[i][j] == OLD_C)
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->c_img, j * WPB, i * HPB);
            if (map->map_data[i][j] == 'P')
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->p_img, j * WPB, i * HPB);
            if (map->map_data[i][j] == 'E')
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->e_img, j * WPB, i * HPB);
            if (map->map_data[i][j] == P_ON_C)
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->p_on_c_img, j * WPB, i * HPB);
            if (map->map_data[i][j] == P_ON_E)
                mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->p_on_e_img, j * WPB, i * HPB);
            j++;
        }
        i++;
    }
}

void draw(t_map *map, t_mlx *mlx, t_img *img)
{
    if (!img->c_img)
        init_window_image(mlx, img, map);
    draw_map(mlx, img, map);
}