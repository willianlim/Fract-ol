// #include "../include/ft_fractol.h"

// void	ft_julia(t_data *data)
// {
// 	unsigned int	*rgb;

// 	data->point.row = 0;
// 	while (data->point.row < IMG_HEIGHT)
// 	{
// 		data->point.col = 0;
// 		while (data->point.col < IMG_WIDTH)
// 		{
// 			ft_map(data);
// 			while (pow(data->point.x, 2) + pow(data->point.y, 2) <= 4 && data->point.i < MAX_ITERATION)
// 				ft_cal_loop(data);
// 			rgb = (unsigned int *)&data->img.data[data->point.col * IMG_WIDTH + data->point.row];
// 			*rgb = color(data);
// 		data->point.col++;
// 		}
// 	data->point.row++;
// 	}
// }
