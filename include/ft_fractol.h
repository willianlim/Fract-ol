/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 20:40:55 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/10 15:24:03 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "ft_fractol_struct.h"
# include "../libft/libft.h"

void			ft_create_window(t_data *data);
void			ft_create_image(t_data *data);
void			ft_set_pointer(t_data *data);
void			ft_picture(const char *argv[], t_data *data);
void			ft_mandelbrot(t_data *data);
int				ft_mouse_hook(int key, int x, int y, t_data *data);
int				ft_key_hook(int key, t_data *data);
unsigned int	color(t_data *data);
void			ft_julia(t_data *data);
int				ft_display_usage(int t, t_data *data);
void			init(const char *argv[], t_data *data);
int				ft_name_fractol(const char *argv[]);
void			c_vect(t_data *data);
void			ft_burningship(t_data *data);
void			ft_parameter_julia(const char *argv[], t_data *data);
void			chek_frac(t_data *data);
void			define_color(t_data *data);
void			death_star(t_data *data);
void			verify_minus(const char *s, double *fact);

#endif
