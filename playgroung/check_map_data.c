#include "map.h"

void check_upper_lower(char *line)
{
    size_t i;

    i = 0;
    while (line[i] != '\n')
    {
        if (line[i] != '1')
            error_handle();
        i++;
    }
}

void check_wall(t_map *map)
{
    size_t i;

    check_upper_lower(map->map[0]);
    i = 1;
    while (i + 2 < map->num_of_line)
    {
        if (map->map[i][0] != '1' || map->map[i][map->num_of_column - 1] != '1')
            error_handle();
        i++;
    }
    check_upper_lower(map->map[])
}

void check_map_char(t_map map)
{
    size_t i;
    size_t j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (!(map[i][j] == '0' || map[i][j] == '1' || map[i][j] == 'C' || map[i][j] == 'E' || map[i][j] == 'P'))
                error_handle();
            j++;
        }
        i++;
    }
}

void check_map_data(t_map *map)
{
    if (map->num_of_column == 0 || map->num_of_line == 0)
        error_handle();
    check_map_char(map);
    //goalできるかアルゴリズムcheck
}