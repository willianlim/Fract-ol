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
	// data->complex.c_re = (data->point.row - IMG_WIDTH / 2.0) * (p->xmx - p->xmn)/ IMG_WIDTH;
	// data->complex.c_img = (data->point.col - IMG_HEIGHT / 2.0) * (p->ymx - p->ymn) / IMG_HEIGHT;
	data->point.x = 0;
	data->point.y = 0;
	data->point.i = 0;
}
