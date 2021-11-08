#include "../include/ft_fractol.h"

void	c_vect(t_data *data)
{
	int		i;
	int		fd;
	char	*s;

	i = 0;
	fd = open(COLOR1 , O_RDONLY);
	while (1)
	{
		s = get_next_line(fd);
		if (s == NULL)
		{
			free(s);
				break ;
		}
		data->c[i++] = ft_atoi(s);
		free(s);
	}
	close(fd);
}

unsigned int	color(t_data *data)
{
	int	i;

	i = data->point.i % 16;
	if (data->point.i < MAX_ITERATION && data->point.i > 0 && data->k == 1)
		return (data->c[i*3] << 16 | data->c[i*3+1] << 8 | data->c[i*3+2]);
	if (data->point.i < MAX_ITERATION && data->point.i > 0 && data->k == 2)
		return (data->c[i*3] << 16 | data->c[i*3+2] << 8 | data->c[i*3+1]);
	if (data->point.i < MAX_ITERATION && data->point.i > 0 && data->k == 3)
		return (data->c[i*3+1] << 16 | data->c[i*3] << 8 | data->c[i*3+2]);
	if (data->point.i < MAX_ITERATION && data->point.i > 0 && data->k == 4)
		return (data->c[i*3+1] << 16 | data->c[i*3+2] << 8 | data->c[i*3]);
	if (data->point.i < MAX_ITERATION && data->point.i > 0 && data->k == 5)
		return (data->c[i*3+2] << 16 | data->c[i*3+1] << 8 | data->c[i*3]);
	if (data->point.i < MAX_ITERATION && data->point.i > 0 && data->k == 6)
		return (data->c[i*3+2] << 16 | data->c[i*3] << 8 | data->c[i*3+1]);
	else
		return (0);
}
