#include "struct.h"
#include "draw.h"

void	*insert(t_data *tmp_data, t_data *f_data, t_pt *tmp_size, t_mlx *mlx)
{
	t_pt	pt;
	void	*res;
	t_data	res_data;

	res = mlx_new_image(mlx->mlx_ptr, WPB, HPB);
	res_data.addr = (unsigned int *)mlx_get_data_addr(res, &res_data.bpp,
			&res_data.size_l, &res_data.endian);
	pt.y = 0;
	while (pt.y < tmp_size->y)
	{
		pt.x = 0;
		while (pt.x < tmp_size->x)
		{
			if (tmp_data->addr[pt.y * tmp_size->x + pt.x] == 0xFF000000)
				res_data.addr[pt.y * tmp_size->x + pt.x]
					= f_data->addr[pt.y * tmp_size->x + pt.x];
			else
				res_data.addr[pt.y * tmp_size->x + pt.x]
					= tmp_data->addr[pt.y * tmp_size->x + pt.x];
			pt.x++;
		}
		pt.y++;
	}
	return (res);
}

void	*make_image(t_mlx *mlx, t_data *f_data, char *filename)
{
	void	*tmp;
	void	*res;
	t_pt	tmp_size;
	t_data	tmp_data;

	tmp = mlx_xpm_file_to_image(mlx->mlx_ptr, filename,
			&tmp_size.x, &tmp_size.y);
	tmp_data.addr = (unsigned int *)mlx_get_data_addr(tmp, &tmp_data.bpp,
			&tmp_data.size_l, &tmp_data.endian);
	res = insert(&tmp_data, f_data, &tmp_size, mlx);
	mlx_destroy_image(mlx->mlx_ptr, tmp);
	return (res);
}