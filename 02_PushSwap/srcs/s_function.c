#include "../include/pushswap.h"

void	sx(t_stack *x)
{
	t_node	*n1;
	t_node	*n2;

	if (x->size < 2)
		return ;
	n1 = pop(x);
	n2 = pop(x);
	push(x, n1);
	push(x, n2);
	if (x->name)
	{
		ft_putchar_fd('s', 1);
		ft_putchar_fd(x->name, 1);
		ft_putchar_fd('\n', 1);
	}
}

void	ss(t_data *data)
{
	t_node	*a1;
	t_node	*a2;
	t_node	*b1;
	t_node	*b2;

	if (data->a->size > 1)
	{
		a1 = pop(data->a);
		a2 = pop(data->a);
		push(data->a, a1);
		push(data->a, a2);
	}
	if (data->b->size > 1)
	{
		b1 = pop(data->b);
		b2 = pop(data->b);
		push(data->b, b1);
		push(data->b, b2);
	}
	if (data->a->size >= 2 || data->b->size >= 2)
		ft_putstr_fd("ss\n", 1);
}
