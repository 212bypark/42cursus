#include "../include/pushswap.h"

void	parsing(t_data *data, char **str, int ac)
{
	int	index;

	index = 1;
	if (ac == 2)
		index = 0;
	while (str[index])
	{
		stack_build(data, data->a, get_int(data, str[index]));
		if (ac == 2)
			free(str[index]);
		index++;
	}
	if (ac == 2)
		free(str);
}

void	check_duplicates(t_data *data)
{
	int		index;
	t_node	*n1;
	t_node	*n2;

	index = -1;
	n1 = data->a->head;
	while (++index < (int)data->a->size)
	{
		n2 = n1->nxt;
		while (n1 != n2)
		{
			if (n1->value == n2->value)
				error_process(data);
			n2 = n2->nxt;
		}
		n1 = n1->nxt;
	}
}

int	check_sorted(t_stack *stack)
{
	t_node	*node;
	int		tmp;

	node = stack->head;
	if (!node)
		return (0);
	tmp = node->value;
	node = node->nxt;
	while (node != stack->head)
	{
		if (tmp > node->value)
			return (1);
		tmp = node->value;
		node = node->nxt;
	}
	return (0);
}

void	quick_sort(int *arr, int x, int y)
{
	int		i;
	int		j;
	int		pivot;
	int		tmp;

	i = x;
	j = y;
	pivot = arr[(x + y) / 2];
	while (i <= j)
	{
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j)
		{
			tmp = arr[i];
			arr[i++] = arr[j];
			arr[j--] = tmp;
		}
	}
	if (x < j)
		quick_sort(arr, x, j);
	if (i < y)
		quick_sort(arr, i, y);
}

void	sorting(t_data *data)
{
	if (data->a->size == 2 || \
		!(((data->origin[0] == data->arr[2]) && \
		(data->origin[1] == data->arr[0])) || \
		((data->origin[1] == data->arr[2]) && \
		(data->origin[2] == data->arr[0]))))
		sx(data->a);
	if (data->a->size == 2)
		return ;
	data->origin[0] = data->a->head->value;
	data->origin[1] = data->a->head->nxt->value;
	data->origin[2] = data->a->head->nxt->nxt->value;
	if ((data->origin[0] == data->arr[2]) && \
		(data->origin[1] == data->arr[0]))
		rx(data->a);
	else if ((data->origin[1] == data->arr[2]) && \
		(data->origin[2] == data->arr[0]))
		rrx(data->a);
}
