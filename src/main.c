#include "map.h"
#include "draw.h"
#include "events.h"
#include "error.h"

int main(int ac, char *av[])
{
    t_map map;
    t_mlx mlx;
    t_img img;

    if (ac != 2)
        error_handle(ARGS_ERROR, NULL);
    map = map_init(av[1]);
    img.c_img = NULL;
    draw(&map, &mlx, &img);
    events(&mlx, &img, &map);
    exit(0);
}