#include "../include/ft_fractol.h"

void	ft_map(t_data *data)
{
	t_point *p;
	double	s_x;
	double	s_y;

	p = &data->point;
	s_x = (double)(p->xmx - p->xmn) / WIN_WIDTH;
	s_y = (double)(p->ymx - p->ymn) / WIN_HEIGHT;
	data->complex.c_re = p->xmn + (double)(data->point.row * s_x);
	data->complex.c_img = p->ymn + (double)(data->point.col * s_y);
	data->point.zr = 0;
	data->point.zi = 0;
	data->point.zr2 = 0;
	data->point.zi2 = 0;
	data->point.i = 0;
}
