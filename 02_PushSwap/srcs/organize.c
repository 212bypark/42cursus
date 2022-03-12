#include "../include/pushswap.h"

#include <stdio.h>

static int	confirm(t_data *data, t_node *na, t_node *nb)
{
	if (data->size <= 1)
		return (0);
	if (na->value < na->pre->value)
	{
		if (na->value > nb->value)
			return (1);
		else if (na->pre->value < nb->value)
			return (1);
		else
			return (0);
	}
	if (na->value > nb->value && nb->value > na->pre->value)
		return (1);
	return (0);
}

static int	get_min_move(t_data *data, t_node *na, t_node *nb, int count_m)
{
	int		i;
	int		j;

	i = -1;
	while (++i < data->a->size)
	{
		j = -1;
		while (++j < data->b->size)
		{
			if (count_m > ft_max(i, j) + (ft_min(i, j) * !!(data->dir % 3)) && \
				confirm(data, na, nb) == 1)
			{
				count_m = ft_max(i, j) + (ft_min(i, j) * !!(data->dir % 3));
				data->move[data->dir * 2] = i;
				data->move[data->dir * 2 + 1] = j;
			}
			nb = nb->nxt;
			if (data->dir == 1 || data->dir == 3)
				nb = nb->pre->pre;
		}
		na = na->nxt;
		if (data->dir == 2 || data->dir == 3)
			na = na->pre->pre;
	}
	return (count_m);
}

static void	exec(t_data *d, t_stack *stack, int dir, int min_move)
{
	int		i;

	while (dir < 4 && d->box[dir] != min_move)
		dir++;
	if (d->move[dir * 2] < d->move[dir * 2 + 1])
		stack = d->b;
	i = -1;
	while (dir == 0 && ++i < ft_min(d->move[dir * 2], d->move[dir * 2 + 1]))
		rr(d);
	while (dir == 3 && ++i < ft_min(d->move[dir * 2], d->move[dir * 2 + 1]))
		rrr(d);
	while (dir == 0 && i++ < ft_max(d->move[dir * 2], d->move[dir * 2 + 1]))
		rx(stack);
	while (dir == 3 && i++ < ft_max(d->move[dir * 2], d->move[dir * 2 + 1]))
		rrx(stack);
	while (dir == 1 && ++i < d->move[dir * 2])
		rx(d->a);
	while (dir == 2 && ++i < d->move[dir * 2])
		rrx(d->a);
	i = -1;
	while (dir == 1 && ++i < d->move[dir * 2 + 1])
		rrx(d->b);
	while (dir == 2 && ++i < d->move[dir * 2 + 1])
		rx(d->b);
	pa(d);
}

static void	rotate(t_data *data, t_node *node)
{
	int		i;

	i = 0;
	while (node->value != data->arr[0])
	{
		node = node->nxt;
		i++;
	}
	while (data->a->head->value != data->arr[0])
	{
		if (i <= data->size / 2)
			rx(data->a);
		else
			rrx(data->a);
	}
}

void	sort(t_data *d, t_stack *a, t_stack *b, int *x)
{
	while (a->size > 2)
		pb(d);
	while (b->size > 0)
	{
		d->dir = -1;
		while (++d->dir < 4)
			x[d->dir] = get_min_move(d, a->head, b->head, MAX_INT);
		exec(d, d->a, 0, ft_min(x[0], ft_min(x[1], ft_min(x[2], x[3]))));
	}
	rotate(d, d->a->head);
}
