#include "../include/fractol.h"
#include "../include/events.h"

int	ft_quit(t_data *data)
{
	exit(0);
	(void)data;
	return (0);
}

static void	ft_move_plane(int keycode, t_fractol *frac)
{
	double	shift;

	shift = (frac->max_r - frac->min_r) * SHIFT_SCALE;
	if (keycode == KEY_A || keycode == ARR_LEFT)
	{
		frac->min_r -= shift;
		frac->max_r -= shift;
	}
	else if (keycode == KEY_D || keycode == ARR_RIGHT)
	{
		frac->min_r += shift;
		frac->max_r += shift;
	}
	else if (keycode == KEY_W || keycode == ARR_UP)
	{
		frac->min_i += shift;
		frac->max_i += shift;
	}
	else
	{
		frac->min_i -= shift;
		frac->max_i -= shift;
	}
}

int	ft_key_hook(int key, t_data *data)
{
	t_fractol	*frac;

	frac = data->frac;
	if (key == KEY_ESC)
		ft_quit(data);
	else if (key == KEY_Q)
		frac->max_iter = (int)(frac->max_iter * 0.95);
	else if (key == KEY_E)
		frac->max_iter = (int)(frac->max_iter * 1.05);
	else if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D || \
	key == ARR_UP || key == ARR_DOWN || key == ARR_LEFT || key == ARR_RIGHT)
		ft_move_plane(key, frac);
	else if (key == KEY_C)
	{
		frac->color += 1;
		frac->color %= 4;
	}
	else if (key == KEY_R)
		ft_reset(frac);
	else
		return (key);
	ft_draw_frac(data);
	return (key);
}

static void	ft_zoom(t_fractol *frac, double x, double y, double zoom)
{
	double	mouse_x;
	double	mouse_y;

	mouse_x = frac->min_r + x * frac->scale_r;
	mouse_y = frac->min_i + y * frac->scale_i;
	frac->min_r = mouse_x + (frac->min_r - mouse_x) * zoom;
	frac->max_r = mouse_x + (frac->max_r - mouse_x) * zoom;
	frac->min_i = mouse_y + (frac->min_i - mouse_y) * zoom;
	frac->max_i = mouse_y + (frac->max_i - mouse_y) * zoom;
}

int	ft_mouse_hook(int keycode, int x, int y, t_data *data)
{
	double	zoom;

	if (keycode == MOUSE_UP || keycode == MOUSE_DOWN)
	{
		if (keycode == MOUSE_UP)
			zoom = ZOOM_IN;
		else
			zoom = ZOOM_OUT;
		ft_zoom(data->frac, x, y, zoom);
		ft_draw_frac(data);
	}
	return (0);
}
