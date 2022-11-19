#include "events.h"

int key_hook(int keycode, t_param *param)
{
    if (keycode == W_KEY || keycode == A_KEY || keycode == S_KEY || keycode == D_KEY)
        player_move(keycode, param);
    return (0);
}

void events(t_mlx *mlx, t_img *img, t_map *map)
{
    t_param param;

    param.map = map;
    param.mlx = mlx;
    param.img = img;
    param.count_c = 0;
    param.res = 0;
    param.num_c = get_c_num(map);
    mlx_key_hook(mlx->win_ptr, &key_hook, &param);
    mlx_loop(mlx->mlx_ptr);
}