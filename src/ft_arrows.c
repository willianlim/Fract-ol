/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:41:53 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/11 22:41:54 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

void	positive_arrow(double *min, double *max, t_data *data)
{
	*min += 0.02 * (*max - *min);
	*max += 0.02 * (*max - *min);
	chek_frac(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win, \
		data->img.img_ptr, 0, 0);
}

void	negative_arrow(double *min, double *max, t_data *data)
{
	*min -= 0.02 * (*max - *min);
	*max -= 0.02 * (*max - *min);
	chek_frac(data);
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win, \
		data->img.img_ptr, 0, 0);
}
