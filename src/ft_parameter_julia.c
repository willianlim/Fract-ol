/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter_julia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:10:31 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/11 23:06:04 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

int	point_img(int p_arg, const char **ptr, t_jul *jul, t_data *data)
{
	while ((*(*(ptr + p_arg) + jul->i) >= 48 && \
	*(*(ptr + p_arg) + jul->i) <= 57) || \
	*(*(ptr + p_arg) + jul->i) == 46)
	{
		if (*(*(ptr + p_arg) + jul->i) == 46)
		{
			if (++jul->bool_dot >= 2)
				ft_display_usage(6, data);
		}
		if (!*(*(ptr + p_arg) + ++jul->i))
			return (0);
	}
	if (p_arg == 3)
	{
		if (*(*(ptr + p_arg) + jul->i) == 105 && \
		*(*(ptr + p_arg) + ++jul->i) == 0)
			return (0);
		else
			ft_display_usage(7, data);
	}
	else
		ft_display_usage(8, data);
	return (0);
}

void	plus_minus_digit(int p_arg, const char	**ptr, t_jul *jul, t_data *data)
{
	while (*(*(ptr + p_arg) + jul->i) == 43 || *(*(ptr + p_arg) + jul->i) == 45)
	{
		jul->bool_signal++;
		if (jul->bool_signal >= 2)
			ft_display_usage(3, data);
		++jul->i;
	}
	if (!jul->bool_signal)
		ft_display_usage(4, data);
	while (*(*(ptr + p_arg) + jul->i2) != 0)
	{
		if (ft_isdigit(*(*(ptr + p_arg) + jul->i2++)))
		{
			jul->bool_digit = 0;
			break ;
		}
	}
	if (jul->bool_digit)
		ft_display_usage(5, data);
}

static int	verify_argv(int position_argv, const char *argv[], t_data *data)
{
	t_jul	jul;

	jul.i = 0;
	jul.bool_dot = 0;
	jul.bool_signal = 0;
	jul.bool_digit = 1;
	jul.i2 = 0;
	plus_minus_digit(position_argv, argv, &jul, data);
	point_img(position_argv, argv, &jul, data);
	return (0);
}

void	ft_parameter_julia(const char *argv[], t_data *data)
{
	if (argv[2] == NULL || argv[3] == NULL)
		ft_display_usage(2, data);
	if (!ft_strchr(argv[2], 'i'))
	{
		verify_argv(2, argv, data);
		data->jul.jul_r = ft_atof(argv[2]);
	}
	else
		ft_display_usage(9, data);
	if (ft_strchr(argv[3], 'i'))
	{
		verify_argv(3, argv, data);
		data->jul.jul_i = ft_atof(argv[3]);
	}
	else
		ft_display_usage(10, data);
}
