#include "../include/fractol.h"
#include "../include/error.h"

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		ft_error(ERR_FRAC);
	data = ft_init_data(argv[1]);
	ft_draw_frac(data);
	mlx_loop(data->mlx);
	free(data);
	return (0);
}
