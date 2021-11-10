/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol_struct.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrosendo <wrosendo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 22:27:14 by wrosendo          #+#    #+#             */
/*   Updated: 2021/11/10 15:48:37 by wrosendo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_STRUCT_H
# define FT_FRACTOL_STRUCT_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../minilibx/mlx.h"
# include "../libft/libft.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

# define IMG_WIDTH 800
# define IMG_HEIGHT 800

# define MAX_ITERATION 600

# define COLOR1 "./menssage/colors1.txt"
# define ERROR1 "./menssage/error1.txt"
# define ERROR2 "./menssage/error2.txt"
# define ERROR3 "./menssage/error3.txt"
# define ERROR4 "./menssage/error4.txt"
# define ERROR5 "./menssage/error5.txt"
# define ERROR6 "./menssage/error6.txt"
# define ERROR7 "./menssage/error7.txt"
# define ERROR8 "./menssage/error8.txt"
# define ERROR9 "./menssage/error9.txt"
# define ERROR10 "./menssage/error10.txt"

# define MANDELBROT "mandelbrot"
# define JULIA "julia"
# define BURNINGSHIP "burning-ship"

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win;
}t_mlx;

typedef struct s_complex
{
	double	c_re;
	double	c_img;
}t_complex;

typedef struct s_point
{
	double	tmp;
	double	zi;
	double	zr;
	double	zi2;
	double	zr2;
	int		i;
	int		row;
	int		col;
	int		max;
	double	xmx;
	double	ymx;
	double	xmn;
	double	ymn;
}t_point;

typedef struct s_jul
{
	double		jul_r;
	double		jul_i;
	int			i;
	int			k;
	int			j;
	int			l;
	int			w;
}t_jul;

typedef struct s_data
{
	t_mlx		*mlx;
	t_img		img;
	t_complex	complex;
	t_point		point;
	t_jul		jul;
	int			c[48];
	int			j;
	int			k;
}t_data;

#endif
