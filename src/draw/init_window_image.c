/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:10:27 by yotsubo           #+#    #+#             */
/*   Updated: 2022/11/21 17:41:25 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static int	key_make(t_img *img)
{
	int	key;

	key = 1;
	if (!img->c_img)
		key = key * 2;
	if (!img->e_img)
		key = key * 3;
	if (!img->f_img)
		key = key * 5;
	if (!img->p_img)
		key = key * 7;
	if (!img->p_on_c_img)
		key = key * 11;
	if (!img->p_on_e_img)
		key = key * 13;
	if (!img->w_img)
		key = key * 17;
	return (key);
}

static void	image_check(t_mlx *mlx, t_img *img, t_map *map)
{
	int	key;

	key = key_make(img);
	if (key > 1 && key % 2 != 0)
		mlx_destroy_image(mlx->mlx_ptr, img->c_img);
	if (key > 1 && key % 3 != 0)
		mlx_destroy_image(mlx->mlx_ptr, img->e_img);
	if (key > 1 && key % 5 != 0)
		mlx_destroy_image(mlx->mlx_ptr, img->f_img);
	if (key > 1 && key % 7 != 0)
		mlx_destroy_image(mlx->mlx_ptr, img->p_img);
	if (key > 1 && key % 11 != 0)
		mlx_destroy_image(mlx->mlx_ptr, img->p_on_c_img);
	if (key > 1 && key % 13 != 0)
		mlx_destroy_image(mlx->mlx_ptr, img->p_on_e_img);
	if (key > 1 && key % 17 != 0)
		mlx_destroy_image(mlx->mlx_ptr, img->w_img);
	if (key > 1)
	{
		free_double_ptr(map->map_data, map->num_of_line);
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx_destroy_display(mlx->mlx_ptr);
		error_handle(MLX_ERROR, NULL);
	}
}

static void	init_image(t_mlx *mlx, t_img *img)
{
	t_data	f_data;

	f_data.addr = (unsigned int *)mlx_get_data_addr(img->f_img, &f_data.bpp,
			&f_data.size_l, &f_data.endian);
	img->w_img = make_image(mlx, &f_data, "./src/xpm/w.xpm");
	img->c_img = make_image(mlx, &f_data, "./src/xpm/c.xpm");
	img->p_img = make_image(mlx, &f_data, "./src/xpm/p.xpm");
	img->e_img = make_image(mlx, &f_data, "./src/xpm/e.xpm");
	f_data.addr = (unsigned int *)mlx_get_data_addr(img->c_img, &f_data.bpp,
			&f_data.size_l, &f_data.endian);
	img->p_on_c_img = make_image(mlx, &f_data, "./src/xpm/p.xpm");
	f_data.addr = (unsigned int *)mlx_get_data_addr(img->e_img, &f_data.bpp,
			&f_data.size_l, &f_data.endian);
	img->p_on_e_img = make_image(mlx, &f_data, "src/xpm/p.xpm");
}

void	init_window_image(t_mlx *mlx, t_img *img, t_map *map)
{
	int		width;
	int		height;

	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		error_mlx_init(map);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, map->num_of_column * WPB,
			map->num_of_line * HPB, "so_long");
	if (!mlx->win_ptr)
		error_win_init(mlx, map);
	img->f_img = mlx_xpm_file_to_image(mlx->mlx_ptr, "src/xpm/floor.xpm",
			&width, &height);
	if (!img->f_img)
		error_init_floor(mlx, map);
	init_image(mlx, img);
	image_check(mlx, img, map);
}
