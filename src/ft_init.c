/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:56:03 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/09 20:56:48 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	data->mlx->win = mlx_new_window(data->mlx->mlx_ptr, \
	WIN_WIDTH, WIN_HEIGHT, "fractol");
}

void	ft_create_image(t_data *data)
{
	data->img.img_ptr = mlx_new_image(data->mlx->mlx_ptr, \
	IMG_WIDTH, IMG_HEIGHT);
	data->img.data = (int *)mlx_get_data_addr(data->img.img_ptr, \
	&data->img.bpp, &data->img.size_l, &data->img.endian);
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
