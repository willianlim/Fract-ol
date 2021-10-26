#include "../include/ft_fractol.h"

void	zoom(int key, int x, int y, t_data *data)
{
	double	xrat;
	double	yrat;
	double	d_re;
	double	d_img;

	xrat = (double)x / WIN_WIDTH;
	yrat = (double)y / WIN_HEIGHT;

	d_re = data->point.xmx - data->point.xmn;
	d_img = data->point.ymx - data->point.ymn;
	if (key == 5)
	{
		d_re = (1.05 * d_re) - d_re;
		d_img = (1.05 * d_img) - d_img;
	}
	else
	{
		d_re = ((1.0 / 1.05) * d_re) - d_re;
		d_img = ((1.0 / 1.05) * d_img) - d_img;
	}
	data->point.xmn = data->point.xmn - (d_re * xrat);
	data->point.xmx = data->point.xmx + (d_re * (1 - xrat));
	data->point.ymn = data->point.ymn - (d_img * yrat);
	data->point.ymx = data->point.ymx + (d_img * (1 - yrat));

}

int	ft_mouse_hook(int key, int x, int y, t_data *data)
{
	if (key == 4)
	{
		zoom(key, x, y, data);
		ft_mandelbrot(data);
		mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win, data->img.img_ptr, 0, 0);
	}
	if (key == 5)
	{
		zoom(key, x, y, data);
		ft_mandelbrot(data);
		mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win, data->img.img_ptr, 0, 0);
	}
	printf("key: %d\n x: %d\n y: %d\n", key, x, y);
	return(0);
}

void	death_star(t_data *data)
{
	mlx_destroy_image(data->mlx->mlx_ptr, data->img.img_ptr);
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win);
	mlx_destroy_window(data->mlx->mlx_ptr, data->mlx->win);
	mlx_destroy_display(data->mlx->mlx_ptr);
	free(data->mlx);
	free(data->mlx->mlx_ptr);
	exit(0);
}

int	ft_key_hook(int key, t_data *data)
{
	if (key == 65307)
		death_star(data);
	return (0);
}
