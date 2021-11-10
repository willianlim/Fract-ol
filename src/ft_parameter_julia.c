/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter_julia.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:10:31 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/10 00:43:34 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

// arrumar essa função para colocar na norma
double	stof(const char *s)
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

int	point_img(int a, const char **ptr, t_jul *jul)
{
	while (*(*(ptr + a) + jul->i) >= 48 && \
	*(*(ptr + a) + jul->i) <= 57 || *(*(ptr + a) + jul->i) == 46)
	{
		if (*(*(ptr + a) + jul->i) == 46)
		{
			if (++jul->k >= 2)
				ft_display_usage(6);
		}
		if (!*(*(ptr + a) + ++jul->i))
			return (0);
	}
	if (a == 3)
	{
		if (*(*(ptr + a) + jul->i) == 105 && *(*(ptr + a) + ++jul->i) == 0)
			return (0);
		else
			ft_display_usage(7);
	}
	else
		ft_display_usage(8);
}

void	plus_minus_digit(int a, const char	**ptr, t_jul *jul)
{
	while (*(*(ptr + a) + jul->i) == 43 || *(*(ptr + a) + jul->i) == 45)
	{
		jul->j++;
		if (jul->j >= 2)
			ft_display_usage(3);
		++jul->i;
	}
	if (!jul->j)
		ft_display_usage(4);
	while (*(*(ptr + a) + jul->w) != 0)
	{
		if (ft_isdigit(*(*(ptr + a) + jul->w++)))
		{
			jul->l = 0;
			break ;
		}
	}
	if (jul->l)
		ft_display_usage(5);
}

// Essa função deve verificar se o valor do meu argumento tem letras, mais
// que um ponto, caracteres especias, sinal de mais ou de menos e assim por
// diante
static int	verify_argv(int a, const char *argv[])
{
	t_jul	jul;

	jul.i = 0;
	jul.k = 0;
	jul.j = 0;
	jul.l = 1;
	jul.w = 0;
	plus_minus_digit(a, argv, &jul);
	point_img(a, argv, &jul);
}

void	ft_parameter_julia(int argc, const char *argv[], t_data *data)
{
	if (argv[2] == NULL || argv[3] == NULL)
		ft_display_usage(2);
	if (!ft_strchr(argv[2], 'i'))
	{
		verify_argv(2, argv);
		data->jul.jul_r = stof(argv[2]);
	}
	else
		ft_display_usage(10);
	if (ft_strchr(argv[3], 'i'))
	{
		verify_argv(3, argv);
		data->jul.jul_i = stof(argv[3]);
	}
	else
		ft_display_usage(9);
}
