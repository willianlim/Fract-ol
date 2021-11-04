#include "../include/ft_fractol.h"

static void		ft_check(t_data *data)
{
	double	tmp;

	tmp = (data->complex.c_re - 0.25) * (data->complex.c_re - 0.25) + data->complex.c_img * data->complex.c_img;
	if ((data->complex.c_re + 1.0) * (data->complex.c_re + 1.0) + data->complex.c_img * data->complex.c_img < 0.0625 \
		|| tmp * (tmp + (data->complex.c_re - 0.25)) < 0.25 * data->complex.c_img * data->complex.c_img \
		|| (((data->complex.c_re + 0.125) * (data->complex.c_re + 0.125)) + (data->complex.c_img - 0.744) * (data->complex.c_img - 0.744)) < 0.0088 \
		|| (((data->complex.c_re + 0.125) * (data->complex.c_re + 0.125)) + (data->complex.c_img + 0.744) * (data->complex.c_img + 0.744)) < 0.0088)
	{
		data->point.i = 600;
	}
}

void	ft_cal_loop(t_data *data)
{
	ft_check(data);
	while (data->point.zr2 + data->point.zi2 <= 4 && data->point.i < MAX_ITERATION)
	{
		data->point.zi = 2 * data->point.zr * data->point.zi + data->complex.c_img;
		data->point.zr = data->point.zr2 - data->point.zi2 + data->complex.c_re;
		data->point.zr2 = data->point.zr * data->point.zr;
		data->point.zi2 = data->point.zi * data->point.zi;
		data->point.i++;
	}
}
