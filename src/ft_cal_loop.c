#include "../include/ft_fractol.h"

void	ft_cal_loop(t_data *data)
{
	data->point.x_new = data->point.x * data->point.x - data->point.y * data->point.y + data->complex.c_re;
	data->point.y = 2 * data->point.x * data->point.y + data->complex.c_img;
	data->point.x = data->point.x_new;
	data->point.i += 1;
}
