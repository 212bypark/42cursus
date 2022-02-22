#include "../include/fractol.h"

void	ft_mandelbrot(int *iter, t_fractol *frac)
{
	double	z_r;
	double	z_i;
	double	z_r_2;
	double	z_i_2;

	*iter = 0;
	z_r = frac->c_r;
	z_i = frac->c_i;
	z_r_2 = z_r * z_r;
	z_i_2 = z_i * z_i;
	while (z_r_2 + z_i_2 <= 4 && *iter < frac->max_iter)
	{
		z_i = 2 * z_r * z_i + frac->c_i;
		z_r = z_r_2 - z_i_2 + frac->c_r;
		z_r_2 = z_r * z_r;
		z_i_2 = z_i * z_i;
		(*iter)++;
	}
}

void	ft_julia(int *iter, t_fractol *frac)
{
	double	z_r;
	double	z_i;
	double	z_r_2;
	double	z_i_2;

	*iter = 0;
	z_r = frac->c_r;
	z_i = frac->c_i;
	z_r_2 = z_r * z_r;
	z_i_2 = z_i * z_i;
	while (z_r_2 + z_i_2 <= 4 && *iter < frac->max_iter)
	{
		z_i = 2 * z_r * z_i + JULIA_I;
		z_r = z_r_2 - z_i_2 + JULIA_R;
		z_r_2 = z_r * z_r;
		z_i_2 = z_i * z_i;
		(*iter)++;
	}
}

void	ft_burningship(int *iter, t_fractol *frac)
{
	double	z_r;
	double	z_i;
	double	z_r_2;
	double	z_i_2;

	*iter = 0;
	z_r = frac->c_r;
	z_i = frac->c_i;
	z_r_2 = z_r * z_r;
	z_i_2 = z_i * z_i;
	while (z_r_2 + z_i_2 <= 4 && *iter < frac->max_iter)
	{
		z_i = fabs(2 * z_r * z_i) - frac->c_i;
		z_r = z_r_2 - z_i_2 - frac->c_r;
		z_r_2 = z_r * z_r;
		z_i_2 = z_i * z_i;
		(*iter)++;
	}
}
