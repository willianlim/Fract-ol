# ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

#include "ft_fractol_struct.h"
#include "../libft/libft.h"

void			ft_create_window(t_data *data);
void			ft_create_image(t_data *data);
void			ft_set_pointer(t_data *data);
void			ft_picture(int argc, const char *argv[], t_data *data);
void			ft_mandelbrot(t_data *data);
int				ft_mouse_hook(int key, int x, int y, t_data *data);
int				ft_key_hook(int key, t_data *data);
unsigned int	color(t_data *data);
void			ft_julia(t_data *data);
int				ft_display_usage(void);
void			init(int argc, const char *argv[], t_data *data);
int				ft_parameters(const char *argv[]);
void			c_vect(t_data *data);
void			ft_burningship(t_data *data);

# endif
