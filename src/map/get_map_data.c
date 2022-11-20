#include "map.h"
#include "get_next_line.h"

static char *ignore_space(char *str)
{
    char *res;

    res = sl_strtrim(str, " ");
    free(str);
    if (!res)
        return (NULL);
    return (res);
}

static char *check_n(char *str)
{
    size_t i;
    char *res;

    if (ft_strchr(str, '\n'))
        return (str);
    res = (char *)malloc(sizeof(char) * ft_strlen(str) + 2);
    if (!res)
        return (NULL);
    i = 0;
    while (str[i] != '\0')
    {
        res[i] = str[i];
        i++;
    }
    res[i++] = '\n';
    res[i] = '\0';
    free(str);
    return (res);
}

static char **ft_stradd(char **double_array, char *new)
{
    char **res;
    size_t i;
    size_t  pre_size;

    pre_size = 0;
    while (double_array && double_array[pre_size])
        pre_size++;
    res = (char **)malloc(sizeof(char *) * (pre_size + 2));
    if (!res)
        map_errors(double_array, pre_size, MALLOC_ERROR);
    i = 0;
    while (i < pre_size)
    {
        res[i] = double_array[i];
        i++;
    }
    new = check_n(new);
    if (!new)
    {
        free_double_ptr(double_array, pre_size);
        error_handle(MALLOC_ERROR, new, NULL);
    }
    res[i++] = new;
    res[i] = NULL;
    free(double_array);
    return (res);
}

static void get_map_size(t_map *map)
{
    size_t i;
    size_t j;
    size_t pre_j;
    int flag;

    i = 0;
    flag = 0;
    pre_j = ft_strlen(map->map_data[0]);
    while (map->map_data[i])
    {
        j = ft_strlen(map->map_data[i]);
        if (j != pre_j)
            flag = 1;
        pre_j = j;
        i++;
    }
    map->num_of_line = i ;
    map->num_of_column = j - 1;
    if (flag > 0)
        map_errors(map->map_data, map->num_of_line, INPUT_ERROR);
}

void get_map_data(int fd, t_map *map)
{
    char *tmp;

    tmp = get_next_line(fd);
    if (!tmp)
        error_handle(INPUT_ERROR, NULL);
    while (tmp)
    {
        if (tmp[0] == '\n')
        {
            free(tmp);
            break ;
        }
        tmp = ignore_space(tmp);
        if (!tmp)
            error_handle(MALLOC_ERROR, NULL);
        map->map_data = ft_stradd(map->map_data, tmp);
        tmp = get_next_line(fd);
    }
    get_map_size(map);
}