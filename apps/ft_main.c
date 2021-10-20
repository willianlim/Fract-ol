#include "../include/ft_fractol.h"

void	init(t_data *data)
{
	data->point.xmx = 1.2;
	data->point.xmn = -2.5;
	data->point.ymx = 1.2;
	data->point.ymn = -1.2;
}

int main(int argc, const char *argv[])
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->mlx = malloc(sizeof(t_mlx) * 1);
	init(data);
	data->mlx->mlx_ptr = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "fractol");
	data->img.img_ptr = mlx_new_image(data->mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	data->img.data = (int *)mlx_get_data_addr(data->img.img_ptr, &data->img.bpp, &data->img.size_l, &data->img.endian);
	//ft_mandelbrot(data);
	ft_picture(data, &argv[1]);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win, data->img.img_ptr, 0, 0);
	mlx_mouse_hook(data->mlx->win, ft_mouse_hook, data);
	mlx_key_hook(data->mlx->win, ft_key_hook, data);
	mlx_loop(data->mlx->mlx_ptr);
	return (0);
}
