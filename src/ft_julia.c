#include "../include/ft_fractol.h"

static void	ft_map_jul(t_data *data)
{
	t_point *p;
	double	s_x;
	double	s_y;

	p = &data->point;
	s_x = (double)(p->xmx - p->xmn) / WIN_WIDTH;
	s_y = (double)(p->ymx - p->ymn) / WIN_HEIGHT;
	data->point.zr = p->xmn + (double)(data->point.row * s_x);
	data->point.zi = p->ymn + (double)(data->point.col * s_y);
	data->complex.c_re = 0.835;
	data->complex.c_img = 0.2321;
	data->point.zr2 = 0;
	data->point.zi2 = 0;
	data->point.i = 0;
}

static void	ft_cal_loop_jul(t_data *data)
{
	while (data->point.zr2 + data->point.zi2 <= 4 && data->point.i < MAX_ITERATION)
	{
		data->point.zr2 = data->point.zr * data->point.zr;
		data->point.zi2 = data->point.zi * data->point.zi;
		data->point.zi = 2 * data->point.zr * data->point.zi - data->complex.c_img;
		data->point.zr = data->point.zr2 - data->point.zi2 - data->complex.c_re;
		data->point.i++;
	}
}

void	ft_julia(t_data *data)
{
	unsigned int	*rgb;

	data->point.row = 0;
	while (data->point.row < IMG_HEIGHT)
	{
		data->point.col = 0;
		while (data->point.col < IMG_WIDTH)
		{
			ft_map_jul(data);
			ft_cal_loop_jul(data);
			rgb = (unsigned int *)&data->img.data[data->point.col * IMG_WIDTH + data->point.row];
			*rgb = color(data);
		data->point.col++;
		}
	data->point.row++;
	}
}

