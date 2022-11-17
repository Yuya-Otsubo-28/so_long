#ifndef STRUCT_H
#define STRUCT_H

typedef struct s_pt
{
    int x;
    int y;
} t_pt;


typedef struct s_img
{
    void *w_img;
    void *f_img;
    void *p_img;
    void *c_img;
    void *e_img;
} t_img;

typedef struct s_data {
    void *img;
    unsigned int *addr;
    int bpp;
    int size_l;
    int endian;
}   t_data;

typedef struct s_map
{
    char **map_data;
    size_t num_of_line;
    size_t num_of_column;
}   t_map;

typedef struct s_mlx
{
    void *mlx_ptr;
    void *win_ptr;
} t_mlx;


#endif