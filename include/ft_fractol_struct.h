# ifndef FT_FRACTOL_STRUCT_H
# define FT_FRACTOL_STRUCT_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include "../minilibx/mlx.h"
#include "../libft/libft.h"

# define WIN_WIDTH 800
# define WIN_HEIGHT 800

# define IMG_WIDTH 800
# define IMG_HEIGHT 800

# define MAX_ITERATION 600

# define ERROR "./menssage/error.txt"
# define COLOR "./menssage/colors.txt"

# define MANDELBROT "mandelbrot"
# define JULIA "julia"

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

typedef struct s_data
{
	t_mlx		*mlx;
	t_img		img;
	t_complex	complex;
	t_point		point;
	int			c[48];
}t_data;

# endif
