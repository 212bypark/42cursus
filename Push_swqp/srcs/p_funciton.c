#include "../include/pushswap.h"

void	pa(t_data *data)
{
	if (data->b->size < 1)
		return ;
	push(data->a, pop(data->b));
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_data *data)
{
	if (data->a->size < 1)
		return ;
	push(data->b, pop(data->a));
	ft_putstr_fd("pb\n", 1);
}
