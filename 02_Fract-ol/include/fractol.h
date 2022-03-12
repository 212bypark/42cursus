#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# include "../miniliblx/mlx.h"

# define MAN "Mandelbrot"
# define JUL "Julia"
# define BUR "Burningship"

# define WIN_W 800
# define WIN_H 800
# define MAX_ITER 100

# define MAX_R 2.0
# define MIN_R -2.0
# define MIN_I -2.0

# define JULIA_R -0.4
# define JULIA_I 0.6

# define COLOR_1 0x00C1FF33
# define COLOR_2 0x0092D8FA
# define COLOR_3 0x00FA92F1 

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}		t_img;

typedef struct s_fractol
{
	char	name;

	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;

	double	scale_r;
	double	scale_i;

	double	c_r;
	double	c_i;

	int		max_iter;
	int		color;
}		t_fractol;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	t_img			*img;
	t_fractol		*frac;
}		t_data;

t_data	*ft_init_data(char *name);

int		ft_strcmp(const char *s1, const char *s2);

void	ft_draw_frac(t_data *data);

char	free_data(t_data *data);
void	ft_reset(t_fractol *frac);

void	ft_mandelbrot(int *index, t_fractol *frac);
void	ft_julia(int *index, t_fractol *frac);
void	ft_burningship(int *iter, t_fractol *frac);
#endif
