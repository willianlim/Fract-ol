#include "../include/ft_fractol.h"

int	ft_display_usage(void)
{
	int		fd;
	char	*s;

	fd = open(ERROR, O_RDONLY);
	s = get_next_line(fd);
	printf("%s", s);
	free(s);
	while(s != NULL)
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
	close(fd);
	exit(1);
}

int	ft_parameters(const char *argv[])
{
	if (!ft_strcmp(argv[1], JULIA))
		return (0);
	else if (!ft_strcmp(argv[1], MANDELBROT))
		return (0);
	return (1);
}
