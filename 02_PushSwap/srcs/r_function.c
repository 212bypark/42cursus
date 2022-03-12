#include "../include/pushswap.h"

void	rx(t_stack *x)
{
	if (x->size < 2)
		return ;
	x->head = x->head->nxt;
	if (x->name)
	{
		ft_putchar_fd('r', 1);
		ft_putchar_fd(x->name, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	rr(t_data *data)
{
	if (data->a->size >= 2)
		data->a->head = data->a->head->nxt;
	if (data->b->size >= 2)
		data->b->head = data->b->head->nxt;
	if (data->a->size >= 2 || data->b->size >= 2)
		ft_putstr_fd("rr\n", 1);
}

void	rrx(t_stack *x)
{
	if (x->size < 2)
		return ;
	x->head = x->head->pre;
	if (x->name)
	{
		ft_putstr_fd("rr", 1);
		ft_putchar_fd(x->name, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	rrr(t_data *data)
{
	if (data->a->size >= 2)
		data->a->head = data->a->head->pre;
	if (data->b->size >= 2)
		data->b->head = data->b->head->pre;
	if (data->a->size >= 2 || data->b->size >= 2)
		ft_putstr_fd("rrr\n", 1);
}
