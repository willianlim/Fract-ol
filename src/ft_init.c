#include "../include/ft_fractol.h"

void	ft_set_pointer(t_data *data)
{
	data->point.xmx = 2;
	data->point.xmn = -2;
	data->point.ymx = 2;
	data->point.ymn = -2;
}

void	ft_create_window(t_data *data)
{
	data->mlx->mlx_ptr = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fractol");
}

void	ft_create_image(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	data->img.data = (int *)mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, &data->img.size_l, &data->img.endian);
}

void	ft_picture(t_data *data, const char *argv[])
{
	if (!ft_strncmp(MANDELBROT, argv[1], ft_strlen(MANDELBROT)))
		ft_mandelbrot(data);
	// else if (!ft_strncmp(JULIA, argv[1], ft_strlen(JULIA)))
	// 	ft_julia(data);
}

void	init(t_data *data, const char *argv[])
{
	ft_set_pointer(data);
	ft_create_window(data);
	ft_create_image(data);
	ft_picture(data, argv);
}
