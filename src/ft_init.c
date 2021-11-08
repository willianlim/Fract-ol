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


double	stof(const char* s)
{
	double	rez;
	double	fact;
	int		d;
	int		point_seen;

	rez = 0;
	fact = 1;
	point_seen = 0;
	if (*s == '-')
	{
		s++;
		fact = -1;
	}
	while (*s)
	{
		if (*s == '.')
			point_seen = 1;
		d = *s++ - '0';
		if (d >= 0 && d <= 9)
		{
			if (point_seen) fact /= 10.0f;
			rez = rez * 10.0f + (double)d;
		}
	}
	return (rez * fact);
}

void	ft_parameter_julia(int argc, const char *argv[], t_data *data)
{
	int	i;

	i = 2;
	if (argv[i] == NULL)
		ft_display_usage();
	while (i <= 3)
	{
		if (ft_strchr(argv[i], 105))
			data->jul_i = stof(argv[i]);
		else
			data->jul_r = stof(argv[i]);
		i++;
	}
	// data->jul_r = stof(argv[i]);
	// data->jul_i = stof(argv[i+1]);
}

void	ft_picture(int argc, const char *argv[], t_data *data)
{
	data->k = 1;
	if (!ft_strcmp(argv[1], MANDELBROT))
	{
		data->j = 0;
		ft_mandelbrot(data);
	}
	else if (!ft_strcmp(argv[1], JULIA))
	{
		data->j = 1;
		ft_parameter_julia(argc, argv, data);
		ft_julia(data);
	}
	else if (!ft_strcmp(argv[1], BURNINGSHIP))
	{
		data->j = 2;
		ft_burningship(data);
	}
}

void	init(int argc, const char *argv[], t_data *data)
{
	ft_set_pointer(data);
	ft_create_window(data);
	ft_create_image(data);
	c_vect(data);
	ft_picture(argc, argv, data);
}
