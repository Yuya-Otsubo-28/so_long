#include "events.h"

int get_c_num(t_map *map)
{
    int x;
    int y;
    int num_c;

    num_c = 0;
    y = 1;
    while ((size_t)y < map->num_of_line)
    {
        x = 1;
        while ((size_t)x < map->num_of_column)
        {
            if (map->map_data[y][x] == 'C')
                num_c++;
            x++;
        }
        y++;
    }
    return (num_c);
}

void search_player(t_map *map, t_pt *p)
{
    p->y = 1;
    while ((size_t)p->y < map->num_of_line)
    {
        p->x = 1;
        while ((size_t)p->x < map->num_of_column)
        {
            if (map->map_data[p->y][p->x] == 'P' || map->map_data[p->y][p->x] == P_ON_C || map->map_data[p->y][p->x] == P_ON_E)
                return ;
            p->x++;
        }
        p->y++;
    }
}