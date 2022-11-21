/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotsubo </var/mail/yotsubo>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 09:52:40 by yotsubo           #+#    #+#             */
/*   Updated: 2022/11/21 09:53:25 by yotsubo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "draw.h"
#include "events.h"
#include "error.h"

int	main(int ac, char *av[])
{
	t_map	map;
	t_mlx	mlx;
	t_img	img;

	if (ac != 2)
		error_handle(ARGS_ERROR, NULL);
	map = map_init(av[1]);
	img.c_img = NULL;
	draw(&map, &mlx, &img);
	events(&mlx, &img, &map);
	exit(0);
}
