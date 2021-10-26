#include "../include/ft_fractol.h"

void	ft_picture(t_data *data, const char *argv[])
{
	if (ft_strncmp(MANDELBROT, *argv, ft_strlen(MANDELBROT)) == 0)
		ft_mandelbrot(data);
	else if (ft_strncmp(JULIA, *argv, ft_strlen(JULIA)) == 0)
		ft_julia(data);
}
