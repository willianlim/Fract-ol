#include "../include/ft_fractol.h"

int main(int argc, const char *argv[])
{
	t_data	data;

	if (argc != 2 && ft_parameters(argv))
		ft_display_usage();
	data.mlx = (struct s_mlx*)malloc(sizeof(struct s_mlx));
	init(argc, argv, &data);
	mlx_put_image_to_window(data.mlx->mlx_ptr, data.mlx->win, data.img.img_ptr, 0, 0);
	mlx_mouse_hook(data.mlx->win, ft_mouse_hook, &data);
	mlx_key_hook(data.mlx->win, ft_key_hook, &data);
	mlx_loop(data.mlx->mlx_ptr);
	return (0);
}
