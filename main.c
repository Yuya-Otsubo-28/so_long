#include "./src/map/map.h"
#include "./error/error.h"

int main(int argc, char *argv[])
{
    t_map map;

    if (argc != 2)
        error_handle(ARGS_ERROR, NULL);
    map = map_init(argv[1]);
    draw(map);
    events();
}