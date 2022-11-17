
#include "map.h"

static int **init_map_copy(t_map *map)
{
    int **map_copy;
    size_t i;

    map_copy = (int **)malloc(sizeof(int *) * map->num_of_line);
    if (!map_copy)
        map_errors(map->map_data, map->num_of_line, MALLOC_ERROR);
    i = 0;
    while (i < map->num_of_line)
    {
        map_copy[i] = (int *)malloc(sizeof(int) * map->num_of_column);
        if (!map_copy[i])
        {
            free_double_ptr_int(map_copy, i);
            map_errors(map->map_data, map->num_of_line, MALLOC_ERROR);
        }
        ft_bzero(map_copy[i], sizeof(int) * map->num_of_column);
        i++;
    }
    return (map_copy);
}

static int check_collect(t_map *map, int **map_copy)
{
    size_t i;
    size_t j;
    int flag;

    i = 1;
    flag = 0;
    while (i < map->num_of_line)
    {
        j = 1;
        while (map->map_data[i][j] != '\n')
        {
            if (map->map_data[i][j] == 'C' && map_copy[i][j] != 1)
                return (0);
            if (map->map_data[i][j] == 'E' && map_copy[i][j] == 1)
                flag = 1;
            j++;
        }
        i++;
    }
    return (flag);
}

static void search_path(t_map *map, int **map_copy, size_t i, size_t j)
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

static void search_start(t_map *map, size_t *i, size_t *j)
{
    *i = 0;
    while (*i < map->num_of_line)
    {
        *j = 0;
        while (map->map_data[*i][*j] != '\n')
        {
            if (map->map_data[*i][*j] == 'P')
                return;
            (*j)++;
        }
        (*i)++;
    }
}

void check_goal(t_map *map)
{
    int **map_copy;
    size_t i;
    size_t j;

    map_copy = init_map_copy(map);
    search_start(map, &i, &j);
    search_path(map, map_copy, i, j);
    i = 0;
    while (i < map->num_of_line)
    {
        j = 0;
        while (j < map->num_of_column)
        {
            printf("%d ", map_copy[i][j]);
            j++;
        }
        puts("");
        i++;
    }
    if (check_collect(map, map_copy) == 1)
        printf("yatta-\n");
    else
        printf("xxx\n");
    free_double_ptr_int(map_copy, map->num_of_line);
}