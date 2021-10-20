#include "../include/ft_fractol.h"

unsigned int	color(t_data *data)
{
	unsigned int	rgb[3];
	double			t;

	t = (double)log(data->point.i) / log(MAX_ITERATION);
	rgb[0] = 9 * (1 - t) * t*t*t * 255;
	rgb[1] = 15 * (1 - t) * (1 - t) * t*t * 255;
	rgb[2] = 8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255;
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	ft_mandelbrot(t_data *data)
{
	unsigned int	*rgb;

	data->point.row = 0;
	while (data->point.row < IMG_HEIGHT)
	{
		data->point.col = 0;
		while (data->point.col < IMG_WIDTH)
		{
			ft_map(data);
			while (pow(data->point.x, 2) + pow(data->point.y, 2) <= 4 && data->point.i < MAX_ITERATION)
				ft_cal_loop(data);
			rgb = (unsigned int *)&data->img.data[data->point.col * IMG_WIDTH + data->point.row];
			//*(int *)rgb = data->point.i / MAX_ITERATION * 0xFFFFFF;
			*rgb = color(data);
			// if (data->point.i < MAX_ITERATION)
			// 	data->img.data[data->point.col * IMG_WIDTH + data->point.row] = 0xFFFFFF;
			// else
			// 	data->img.data[data->point.col * IMG_WIDTH + data->point.row] = 0x000000;
		data->point.col += 1;
		}
	data->point.row += 1;
	}
}
