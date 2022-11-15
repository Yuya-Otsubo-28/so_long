#include "map.h"

void error_handle(void)
{
    ft_putstr_fd("Error", STDERR_FILENO);
    exit (1);
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

t_map map_init(char *filename)
{
    int fd;
    t_map map;

    map.map_data = NULL;
    fd = filename_check(filename);
    get_map_data(fd, &map);
    check_map_data(&map);
    return (map);
}