/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_burningship.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:46:10 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/09 20:48:11 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

static void	ft_map_burn(t_data *data)
{
	t_point	*p;
	double	s_x;
	double	s_y;

	p = &data->point;
	s_x = (double)(p->xmx - p->xmn) / WIN_WIDTH;
	s_y = (double)(p->ymx - p->ymn) / WIN_HEIGHT;
	data->complex.c_re = p->xmn + (double)(data->point.row * s_x);
	data->complex.c_img = p->ymn + (double)(data->point.col * s_y);
	data->point.zr = 0;
	data->point.zi = 0;
	data->point.zr2 = 0;
	data->point.zi2 = 0;
	data->point.i = 0;
}

void	ft_cal_loop_burn(t_data *data)
{
	while (data->point.zr2 + data->point.zi2 <= 4 \
	&& data->point.i < MAX_ITERATION)
	{
		data->point.zi = fabs(2 * data->point.zr * data->point.zi) + \
		data->complex.c_img;
		data->point.zr = data->point.zr2 - data->point.zi2 + data->complex.c_re;
		data->point.zr2 = data->point.zr * data->point.zr;
		data->point.zi2 = data->point.zi * data->point.zi;
		data->point.i++;
	}
}

void	ft_burningship(t_data *data)
{
	unsigned int	*rgb;

	data->point.row = 0;
	while (data->point.row < IMG_HEIGHT)
	{
		data->point.col = 0;
		while (data->point.col < IMG_WIDTH)
		{
			ft_map_burn(data);
			ft_cal_loop_burn(data);
			rgb = (unsigned int *)&data->img.data[data->point.col * \
			IMG_WIDTH + data->point.row];
			*rgb = color(data);
			data->point.col++;
		}
		data->point.row++;
	}
}
