#include "map.h"

static void check_upper_lower(char *line, t_map *map)
{
    size_t i;

    i = 0;
    while (line[i] != '\n')
    {
        if (line[i] != '1')
            map_errors(map->map_data, map->num_of_line, INPUT_ERROR);
        i++;
    }
}

static void check_wall(t_map *map)
{
    size_t i;

    check_upper_lower(map->map_data[0], map);
    i = 1;
    while (i + 1 < map->num_of_line)
    {
        if (map->map_data[i][0] != '1' || map->map_data[i][map->num_of_column - 1] != '1')
            map_errors(map->map_data, map->num_of_line, INPUT_ERROR);
        i++;
    }
    check_upper_lower(map->map_data[i], map);
    return ;
}

static void check_map_char(t_map *map)
{
    size_t i;
    size_t j;
    t_count count;

    i = 0;
    count.c_count = 0;
    count.e_count = 0;
    count.p_count = 0;
    while (map->map_data[i])
    {
        j = 0;
        while (map->map_data[i][j] != '\n')
        {
            if (!(map->map_data[i][j] == '0' || map->map_data[i][j] == '1' || map->map_data[i][j] == 'C' || map->map_data[i][j] == 'E' || map->map_data[i][j] == 'P'))
                map_errors(map->map_data, map->num_of_line, INPUT_ERROR);
            if (map->map_data[i][j] == 'P')
                count.p_count++;
            if(map->map_data[i][j] == 'E')
                count.e_count++;
            if (map->map_data[i][j] == 'C')
                count.c_count++;
            j++;
        }
        i++;
    }
    if (count.c_count < 1 || count.e_count != 1 || count.p_count != 1)
       map_errors(map->map_data, map->num_of_line, INPUT_ERROR);
}

void check_map_data(t_map *map)
{
    if (map->num_of_column < 3 || map->num_of_line < 3)
        map_errors(map->map_data, map->num_of_line, INPUT_ERROR);
    check_map_char(map);
    check_wall(map);
    check_goal(map);
    return ;
}