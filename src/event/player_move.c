#include "events.h"

void adj_position(t_param *param, int y, int x)
{
    if (param->map->map_data[y][x] == 'C')
    {
        param->map->map_data[y][x] = P_ON_C;
        param->count_c++;
    }
    else if (param->map->map_data[y][x] == OLD_C)
        param->map->map_data[y][x] = P_ON_C;
    else if (param->map->map_data[y][x] == '0')
        param->map->map_data[y][x] = 'P';
    else if (param->map->map_data[y][x] == 'P')
        param->map->map_data[y][x] = '0';
    else if (param->map->map_data[y][x] == P_ON_C)
        param->map->map_data[y][x] = OLD_C;
    else if (param->map->map_data[y][x] == P_ON_E)
        param->map->map_data[y][x] = 'E';    
}

void player_move(int move, t_param *param)
{
    t_pt p;
    t_pt dst;

    search_player(param->map, &p);
    dst.x = 0;
    dst.y = 0;
    if (move == W_KEY)
        dst.y = -1;
    if (move == S_KEY)
        dst.y = 1;
    if (move == D_KEY)
        dst.x = 1;
    if (move == A_KEY)
        dst.x = -1;
    if (param->map->map_data[p.y + dst.y][p.x + dst.x] == '1')
        return ;
    if (param->map->map_data[p.y + dst.y][p.x + dst.x] == 'E')
    {
        if (param->count_c == param->num_c)
            exit(0);
        param->map->map_data[p.y + dst.y][p.x + dst.x] = P_ON_E;
    }
    else
        adj_position(param, p.y + dst.y, p.x + dst.x);
    adj_position(param, p.y, p.x);
    draw(param->map, param->mlx, param->img);
    param->res++;
}