#include "mlx/mlx.h"
#include <stdio.h>

typedef struct s_data {
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}   t_data;

int hoge(void)
{
    printf("hello");
    return (0);
}

int main(void)
{
    void *mlx;
    void *mlx_win;
    int weight;
    int height;
    void *img;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 500, 500, "test_win");
    img = mlx_xpm_file_to_image(mlx, "iruka_50_34.xpm", &weight, &height);
    mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
    mlx_loop(mlx);
    return (0);
}