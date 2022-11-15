
#include "map.h"

typedef struct s_map
{
    char map_data[5][7];
    int num_of_line;
    int num_of_column;
}   t_map;


int **init_map_copy(t_map *map)
{
    int **map_copy;
    int i;

    map_copy = (int **)malloc(sizeof(int *) * map->num_of_line);
    if (!map_copy)
        error_handle();
    i = 0;
    while (i < map->num_of_line)
    {
        map_copy[i] = (int *)malloc(sizeof(int) * map->num_of_column);
        if (!map_copy[i])
            error_handle();
        ft_bzero(map_copy[i], map->num_of_column);
        i++;
    }
    return (map_copy);
}

int check_collect(t_map *map, int **map_copy)
{
    int i;
    int j;
    int flag;

    i = 1;
    flag = 0;
    while (i < map->num_of_line)
    {
        j = 1;
        while (map->map_data[i][j] != '\n')
        {
            if (map->map_data[i][j] == 'c' && map_copy[i][j] != 1)
                return (0);
            if (map->map_data[i][j] == 'g' && map_copy[i][j] == 1)
                flag = 1;
            j++;
        }
        i++;
    }
    return (flag);
}

void search_path(t_map *map, int **map_copy, int i, int j)
{
    if (map_copy[i][j] == 1)
        return;
    if (map->map_data[i][j] == '1')
        return;
    map_copy[i][j] = 1;
    if (i > 0 && i + 1 < map->num_of_line && j > 0 && j + 1 < map->num_of_column)
    {
        search_path(map, map_copy, i - 1, j);
        search_path(map, map_copy, i, j - 1);
        search_path(map, map_copy, i + 1, j);
        search_path(map, map_copy, i, j + 1);
    }
    return ;
}

void search_start(t_map *map, int *i, int *j)
{
    *i = 0;
    while (*i < map->num_of_line)
    {
        *j = 0;
        while (map->map_data[*i][*j] != '\n')
        {
            if (map->map_data[*i][*j] == 'p')
                return;
            (*j)++;
        }
        (*i)++;
    }
}

void make_map_data(t_map *map)
{
    map->map_data[0][0] = '1';
    map->map_data[0][1] = '1';
    map->map_data[0][2] = '1';
    map->map_data[0][3] = '1';
    map->map_data[0][4] = '1';
    map->map_data[0][5] = '\n';
    map->map_data[0][6] = '\0';
    map->map_data[1][0] = '1';
    map->map_data[1][1] = 'p';
    map->map_data[1][2] = '1';
    map->map_data[1][3] = 'c';
    map->map_data[1][4] = '1';
    map->map_data[1][5] = '\n';
    map->map_data[1][6] = '\0';
    map->map_data[2][0] = '1';
    map->map_data[2][1] = '0';
    map->map_data[2][2] = '0';
    map->map_data[2][3] = '1';
    map->map_data[2][4] = '1';
    map->map_data[2][5] = '\n';
    map->map_data[2][6] = '\0';
    map->map_data[3][0] = '1';
    map->map_data[3][1] = 'c';
    map->map_data[3][2] = '0';
    map->map_data[3][3] = 'g';
    map->map_data[3][4] = '1';
    map->map_data[3][5] = '\n';
    map->map_data[3][6] = '\0';
    map->map_data[4][0] = '1';
    map->map_data[4][1] = '1';
    map->map_data[4][2] = '1';
    map->map_data[4][3] = '1';
    map->map_data[4][4] = '1';
    map->map_data[4][5] = '\n';
    map->map_data[4][6] = '\0';
    map->num_of_column = 5;
    map->num_of_line = 5;
}

void check_goal(t_map map)
{
    int **map_copy;
    int i;
    int j;

    map_copy = init_map_copy(&map);
    search_start(&map, &i, &j);
    search_path(&map, map_copy, i, j);
    if (check_collect(&map, map_copy) == 1)
        printf("yatta-\n");
    else
        printf("xxx\n");
    free(map_copy);
}