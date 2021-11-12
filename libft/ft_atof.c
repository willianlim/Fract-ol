/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 22:43:26 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/11 22:43:27 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	verify_minus(const char *s, double *fact)
{
	s++;
	*fact = -1;
}

double	ft_atof(const char *s)
{
	double	rez;
	double	fact;
	int		d;
	int		point_seen;

	rez = 0;
	fact = 1;
	point_seen = 0;
	if (*s == '-')
		verify_minus(s, &fact);
	while (*s)
	{
		if (*s == '.')
			point_seen = 1;
		d = *s++ - '0';
		if (d >= 0 && d <= 9)
		{
			if (point_seen)
				fact /= 10.0f;
			rez = rez * 10.0f + (double)d;
		}
	}
	return (rez * fact);
}
