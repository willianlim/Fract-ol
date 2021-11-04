#include "../include/ft_fractol.h"

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
			ft_cal_loop(data);
			rgb = (unsigned int *)&data->img.data[data->point.col * IMG_WIDTH + data->point.row];
			*rgb = color(data);
		data->point.col++;
		}
	data->point.row++;
	}
}
