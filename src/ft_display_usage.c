/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_usage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:54:43 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/10 02:01:13 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_fractol.h"

int	ft_option(int t)
{
	if (t == 1)
		return (open(ERROR1, O_RDONLY));
	if (t == 2)
		return (open(ERROR2, O_RDONLY));
	if (t == 3)
		return (open(ERROR3, O_RDONLY));
	if (t == 4)
		return (open(ERROR4, O_RDONLY));
	if (t == 5)
		return (open(ERROR5, O_RDONLY));
	if (t == 6)
		return (open(ERROR6, O_RDONLY));
	if (t == 7)
		return (open(ERROR7, O_RDONLY));
	if (t == 8)
		return (open(ERROR8, O_RDONLY));
	if (t == 9)
		return (open(ERROR9, O_RDONLY));
	if (t == 10)
		return (open(ERROR10, O_RDONLY));
}

int	ft_display_usage(int t, t_data *data)
{
	int		fd;
	char	*s;

	fd = ft_option(t);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	while (s != NULL)
	{
		s = get_next_line(fd);
		if (s == NULL)
		{
			free(s);
			break ;
		}
		printf("%s", s);
		free(s);
	}
	death_star(data);
	close(fd);
	exit(0);
}

int	ft_name_fractol(const char *argv[])
{
	if (!ft_strcmp(argv[1], JULIA))
		return (1);
	else if (!ft_strcmp(argv[1], MANDELBROT))
		return (1);
	else if (!ft_strcmp(argv[1], BURNINGSHIP))
		return (1);
	return (0);
}
