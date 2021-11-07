#include "../include/ft_fractol.h"

void	c_vect(t_data *data)
{
	int		i;
	int		fd;
	char	*s;

	i = -1;
	fd = open(COLOR , O_RDONLY);
	while (++i < 48)
	{
		s = get_next_line(fd);
		if (s == NULL)
		{
			free(s);
				break ;
		}
		data->c[i] = ft_atoi(s);
		free(s);
	}
	close(fd);
}

unsigned int	color(t_data *data)
{
	int	i;

	i = data->point.i % 16;
	if (data->point.i < MAX_ITERATION && data->point.i > 0)
		return (data->c[i*3] << 16 | data->c[i*3+1] << 8 | data->c[i*3+2]);
	else
		return (0);
}

// unsigned int	color(t_data *data)
// {
// 	if (data->point.i < MAX_ITERATION && data->point.i > 0)
// 	{
// 		int	i;
// 		i = data->point.i % 16;
// 		int mapping[16][3] = {
// 		{66, 30, 15},
// 		{25, 7, 26},
// 		{9, 1, 47},
// 		{4, 4, 73},
// 		{0, 7, 100},
// 		{12, 44, 138},
// 		{24, 82, 177},
// 		{57, 125, 209},
// 		{134, 181, 229},
// 		{211, 236, 248},
// 		{241, 233, 191},
// 		{248, 201, 95},
// 		{255, 170, 0},
// 		{204, 128, 0},
// 		{153, 87, 0},
// 		{106, 52, 3},
// 		};
// 		return (mapping[i][0] << 16 | mapping[i][1] << 8 | mapping[i][2]);
// 	}
// 	else
// 		return (0);
// 	if (data->point.i < MAX_ITERATION && data->point.i > 0)
// 	{
// 		int i = data->point.i % 20;
// 		int mapping[20][3] = {
// 		{102, 255, 255}, // azul
// 		{51, 255, 255},
// 		{0, 255, 255},
// 		{0, 204, 204},
// 		{0, 153, 153},
// 		{0, 102, 102},
// 		{0, 51, 51}, //azul
// 		{0, 255, 0}, // verde
// 		{51, 255, 51},
// 		{102, 255, 102},
// 		{102, 255, 178}, //verde
// 		{255, 255, 102},// amarelo
// 		{255, 255, 51},
// 		{255, 255, 0},
// 		{204, 204, 0},//amarelo
// 		{204, 0, 102}, //rosa
// 		{255, 0, 127},
// 		{255, 51, 153},
// 		{255, 102, 178},
// 		{255, 153, 204}, //rosa
// 	};
// 		return (mapping[i][0] << 16 | mapping[i][1] << 8 | mapping[i][2]);
// 	}
// 	else
// 		return (0);
// }
