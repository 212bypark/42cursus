#include "../include/fractol.h"

static void	ft_load_frac(int *iter, t_fractol *frac)
{
	if (frac->name == 'M')
		ft_mandelbrot(iter, frac);
	else if (frac->name == 'J')
		ft_julia(iter, frac);
	else if (frac->name == 'B')
		ft_burningship(iter, frac);
}

static void	ft_put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

static int	ft_colorize(int iter, t_fractol *frac)
{
	int			color_option;
	double		t;
	double		t_p;

	t = (double)iter / (double)(frac->max_iter);
	t_p = 1 - t;
	color_option = frac->color;
	if (color_option == 0)
		return ((int)(iter * COLOR_1) & 0x00ffffff);
	else if (color_option == 1)
		return ((int)(iter * COLOR_2) & 0x00ffffff);
	else if (color_option == 2)
		return ((int)(iter * COLOR_3) & 0x00ffffff);
	else if (color_option == 3)
		return ((int)(9 * t_p * t * t * t * 255) << 16 \
			| (int)(15 * t_p * t_p * t * t * 255) << 8 \
			| (int)(8.5 * t_p * t_p * t_p * t * 255));
	else
		return (0);
}

void	ft_draw_frac(t_data *data)
{
	int			x;
	int			y;
	int			iter;
	t_fractol	*frac;

	frac = data->frac;
	frac->scale_r = (frac->max_r - frac->min_r) / WIN_W;
	frac->scale_i = (frac->max_i - frac->min_i) / WIN_H;
	y = 0;
	while (y < WIN_H)
	{
		frac->c_i = frac->max_i - y * frac->scale_i;
		x = 0;
		while (x < WIN_W)
		{
			frac->c_r = frac->min_r + x * frac->scale_r;
			ft_load_frac(&iter, frac);
			ft_put_pixel(data->img, x, y, ft_colorize(iter, frac));
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}
