#include "map.h"

static int strcmp_from_last(char *str1, char *str2)
{
    size_t i;

    while (*str1)
    {
        i = 0;
        while (str1[i] && str2[i] && str1[i] == str2[i])
            i++;
        if (!str1[i] && !str2[i])
            return (1);
        str1++;
    }
    return (0);
}

static int filename_check(char *filename)
{
    int fd;

    if (!strcmp_from_last(filename, ".ber"))
        error_handle(ARGS_ERROR, NULL);
    fd = open(filename, O_RDONLY);
    if (fd == -1)
        error_handle(ARGS_ERROR, NULL);
    return (fd);
}

t_map map_init(char *filename)
{
    int fd;
    t_map map;

    map.map_data = NULL;
    fd = filename_check(filename);
    puts("hello");
    get_map_data(fd, &map);
    check_map_data(&map);
    return (map);
}

int main(void)
{
    t_map map;
    t_mlx mlx;
    t_img img;

    map = map_init("../test.ber");
    img.c_img = NULL;
    draw(&map, &mlx, &img);
    events(&mlx, &img, &map);
    return (0);
}