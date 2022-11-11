#include "../mlx/mlx.h"
#include "./gnl/get_next_line.h"
#include "./libft/libft.h"
#include <fcntl.h>

typedef struct s_map
{
    char **map_data;
    int num_of_line;
    int num_of_column;
} t_map;

void error_handle(void)
{
    ft_putstr_fd("Error", STDERR_FILENO);
    exit (1);
}

void ft_stradd(char **double_array, char *new)
{
    char **res;
    int i;
    int  pre_size;

    pre_size = 0;
    while (double_array[pre_size])
        pre_size++;
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

int filename_check(char *filename)
{
    int fd;

    if (!ft_strcmp_from_last(filename, ".ber"))
        error_handle();
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        error_handle();
    return (fd);
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
    map->num_of_line = i;
    map->num_of_column = j;
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
    check_map_char(map);
    //goalできるかアルゴリズムcheck
}

t_map map_init(char *filename)
{
    int fd;
    t_map map;

    fd = filename_check(filename);
    get_map_data(fd, &map);
    check_map_data(&map);
    return (map);
}