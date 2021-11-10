/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:20:47 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/10 01:47:01 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

int	main(int argc, const char *argv[])
{
	t_data	data;

	if (argc < 2 || !ft_name_fractol(argv))
		ft_display_usage(1, &data);
	data.mlx = (struct s_mlx *)malloc(sizeof(struct s_mlx));
	init(argc, argv, &data);
	mlx_put_image_to_window(data.mlx->mlx_ptr, \
	data.mlx->win, data.img.img_ptr, 0, 0);
	mlx_mouse_hook(data.mlx->win, ft_mouse_hook, &data);
	mlx_key_hook(data.mlx->win, ft_key_hook, &data);
	mlx_loop(data.mlx->mlx_ptr);
	return (0);
}
