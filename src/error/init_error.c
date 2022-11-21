#include "struct.h"
#include "error.h"

void error_mlx_init(t_map *map)
{
    free_double_ptr(map->map_data, map->num_of_line);
    error_handle(MLX_ERROR, NULL);
}

void error_win_init(t_mlx *mlx, t_map *map)
{
    free_double_ptr(map->map_data, map->num_of_line);
    mlx_destroy_display(mlx->mlx_ptr);
    error_handle(MLX_ERROR, NULL);
}

void error_init_floor(t_mlx *mlx, t_map *map)
{
    free_double_ptr(map->map_data, map->num_of_line);
    mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
    mlx_destroy_display(mlx->mlx_ptr);
    error_handle(MLX_ERROR, NULL);
}