#include "../include/ft_fractol.h"

unsigned int	color(t_data *data)
{
	unsigned int	rgb[3];
	double			t;

	t = (double)log(data->point.i) / log(MAX_ITERATION);
	rgb[0] = 9 * (1 - t) * pow(t, 3) * 255;
	rgb[1] = 15 * pow((1 - t), 2) * pow(t, 2) * 255;
	rgb[2] = 8.5 * pow((1 - t), 3) * t * 255;
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}
