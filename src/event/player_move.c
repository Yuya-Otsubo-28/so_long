/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo <y.otsubo.886@ms.saitama-u.ac.j    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 08:56:42 by yotsubo           #+#    #+#             */
/*   Updated: 2022/11/21 10:13:11 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	destroy_image(t_mlx *mlx, t_img *img)
{
	mlx_destroy_image(mlx->mlx_ptr, img->c_img);
	mlx_destroy_image(mlx->mlx_ptr, img->e_img);
	mlx_destroy_image(mlx->mlx_ptr, img->f_img);
	mlx_destroy_image(mlx->mlx_ptr, img->p_img);
	mlx_destroy_image(mlx->mlx_ptr, img->p_on_c_img);
	mlx_destroy_image(mlx->mlx_ptr, img->p_on_e_img);
	mlx_destroy_image(mlx->mlx_ptr, img->w_img);
}

void	finish(int key, t_param *param)
{
	destroy_image(param->mlx, param->img);
	free_double_ptr(param->map->map_data, param->map->num_of_line);
	mlx_destroy_window(param->mlx->mlx_ptr, param->mlx->win_ptr);
	mlx_destroy_display(param->mlx->mlx_ptr);
	free(param->mlx->mlx_ptr);
	if (key != ESC_KEY)
	{
		param->res++;
		ft_printf("%d\n", param->res);
	}
	if (key == MLX_ERROR)
		error_handle(MLX_ERROR, NULL);
	exit(0);
}

static void	adj_position(t_param *param, int y, int x)
{
	if (param->map->map_data[y][x] == 'C')
	{
		param->map->map_data[y][x] = P_ON_C;
		param->count_c++;
	}
	else if (param->map->map_data[y][x] == OLD_C)
		param->map->map_data[y][x] = P_ON_C;
	else if (param->map->map_data[y][x] == '0')
		param->map->map_data[y][x] = 'P';
	else if (param->map->map_data[y][x] == 'P')
		param->map->map_data[y][x] = '0';
	else if (param->map->map_data[y][x] == P_ON_C)
		param->map->map_data[y][x] = OLD_C;
	else if (param->map->map_data[y][x] == P_ON_E)
		param->map->map_data[y][x] = 'E';
}

static void	dst_set(int move, t_pt *dst)
{
	dst->x = 0;
	dst->y = 0;
	if (move == W_KEY)
		dst->y = -1;
	if (move == S_KEY)
		dst->y = 1;
	if (move == A_KEY)
		dst->x = -1;
	if (move == D_KEY)
		dst->x = 1;
}

void	player_move(int move, t_param *param)
{
	t_pt	p;
	t_pt	dst;

	search_player(param->map, &p);
	dst_set(move, &dst);
	if (param->map->map_data[p.y + dst.y][p.x + dst.x] == '1')
		return ;
	if (param->map->map_data[p.y + dst.y][p.x + dst.x] == 'E')
	{
		if (param->count_c == param->num_c)
			finish(move, param);
		param->map->map_data[p.y + dst.y][p.x + dst.x] = P_ON_E;
	}
	else
		adj_position(param, p.y + dst.y, p.x + dst.x);
	adj_position(param, p.y, p.x);
	draw(param->map, param->mlx, param->img);
	param->res++;
	ft_printf("%d\n", param->res);
}
