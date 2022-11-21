/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:45:10 by yotsubo           #+#    #+#             */
/*   Updated: 2022/11/21 17:09:48 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

static void	draw_block(t_mlx *mlx, t_img *img, t_map *map, t_pt *pt)
{
	if (map->map_data[pt->x][pt->y] == '1')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			img->w_img, pt->y * WPB, pt->x * HPB);
	else if (map->map_data[pt->x][pt->y] == 'C'
		|| map->map_data[pt->x][pt->y] == OLD_C)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			img->c_img, pt->y * WPB, pt->x * HPB);
	else if (map->map_data[pt->x][pt->y] == 'P')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			img->p_img, pt->y * WPB, pt->x * HPB);
	else if (map->map_data[pt->x][pt->y] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			img->e_img, pt->y * WPB, pt->x * HPB);
	else if (map->map_data[pt->x][pt->y] == P_ON_C)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			img->p_on_c_img, pt->y * WPB, pt->x * HPB);
	else if (map->map_data[pt->x][pt->y] == P_ON_E)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			img->p_on_e_img, pt->y * WPB, pt->x * HPB);
}

void	draw_map(t_mlx *mlx, t_img *img, t_map *map, t_pt *pt)
{
	pt->x = 0;
	while ((size_t)pt->x < map->num_of_line)
	{
		pt->y = 0;
		while ((size_t)pt->y < map->num_of_column)
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
				img->f_img, pt->y * WPB, pt->x * HPB);
			draw_block(mlx, img, map, pt);
			pt->y++;
		}
		pt->x++;
	}
}

void	draw(t_map *map, t_mlx *mlx, t_img *img)
{
	t_pt	pt;

	if (!img->c_img)
		init_window_image(mlx, img, map);
	draw_map(mlx, img, map, &pt);
}
