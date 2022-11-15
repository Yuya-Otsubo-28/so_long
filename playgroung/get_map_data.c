#include "map.h"

void ft_stradd(char **double_array, char *new)
{
    char **res;
    int i;
    int  pre_size;

    pre_size = 0;
    if (double_array)
    {
        while (double_array[pre_size])
            pre_size++;
    }
    res = (char **)malloc(sizeof(char *) * (pre_size + 2));
    if (!res)
        error_handle();
    i = 0;
    while (i < pre_size)
    {
        res[i] = double_array[i];
        i++;
    }
    res[i++] = new;
    res[i] = NULL;
    free(double_array);
    return (res);
}

void get_map_data(int fd, t_map *map)
{
    char *tmp;
    int i;
    int j;
    int pre_j;

    while (!(tmp = get_next_line(fd)))
        map->map_data = ft_stradd(map->map_data, tmp);
    i = 0;
    while (map_data[i])
    {
        j = 0;
        while (map->map_data[i][j])
            j++;
        if (i > 0)
            if (j != pre_j)
                error_handle();
        pre_j = j;
        i++;
    }
    map->num_of_line = i ;
    map->num_of_column = j - 1;
}