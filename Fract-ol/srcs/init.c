#include "../include/fractol.h"
#include "../include/error.h"
#include "../include/events.h"

char	free_data(t_data *data)
{
	if (data == NULL)
		return (0);
	if (data->frac)
		free(data->frac);
	if (data->img)
	{
		mlx_destroy_image(data->mlx, data->img);
		free(data->img);
	}
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		free(data->mlx);
	if (data)
		free(data);
	return (0);
}

void	ft_reset(t_fractol *frac)
{
	frac->min_r = MIN_R;
	frac->max_r = MAX_R;
	frac->min_i = MIN_I;
	frac->max_i = MIN_I + (MAX_R - MIN_R) * WIN_H / WIN_W;
	frac->max_iter = MAX_ITER;
}

static t_img	*ft_init_img(void *mlx)
{
	t_img	*img;

	img = malloc(sizeof(t_img));
	if (img == NULL)
		ft_error(ERR_ALLOC);
	img->img = mlx_new_image(mlx, WIN_W, WIN_H);
	img->addr = mlx_get_data_addr(img->img, \
		&img->bpp, &img->line_len, &img->endian);
	if (img->addr == NULL)
		ft_error(ERR_CODE);
	return (img);
}

static t_fractol	*ft_init_frac(char *name)
{
	t_fractol	*frac;

	frac = malloc(sizeof(t_fractol));
	if (frac == NULL)
		ft_error(ERR_ALLOC);
	if (!ft_strcmp(name, MAN))
		frac->name = 'M';
	else if (!ft_strcmp(name, JUL))
		frac->name = 'J';
	else if (!ft_strcmp(name, BUR))
		frac->name = 'B';
	else
		ft_error(ERR_FRAC);
	ft_reset(frac);
	frac->color = 0;
	return (frac);
}

t_data	*ft_init_data(char *name)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		ft_error(ERR_ALLOC);
	data->mlx = mlx_init();
	if (data->mlx == NULL)
		ft_error(ERR_CODE);
	data->win = mlx_new_window(data->mlx, WIN_W, WIN_H, "fractol");
	if (data->win == NULL)
		ft_error(ERR_CODE);
	data->img = ft_init_img(data->mlx);
	data->frac = ft_init_frac(name);
	mlx_hook(data->win, KEY_PRESS, MASK_KEY_PRESS, ft_key_hook, data);
	mlx_hook(data->win, DESTROY, MASK_DESTROY, ft_quit, data);
	mlx_hook(data->win, BUTTON_PRESS, MASK_BUTTON_PRESS, ft_mouse_hook, data);
	return (data);
}
