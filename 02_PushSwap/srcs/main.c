#include "../include/pushswap.h"

void	push_swap(t_data *data)
{
	int		index;
	t_node	*node;

	if (check_sorted(data->a) == 0)
		return ;
	data->origin = (int *)malloc(sizeof(int) * data->a->size);
	data->arr = (int *)malloc(sizeof(int) * data->a->size);
	if (!data->arr || !data->origin)
		error_process(data);
	node = data->a->head;
	index = -1;
	while (++index < data->a->size)
	{
		data->origin[index] = node->value;
		data->arr[index] = node->value;
		node = node->nxt;
	}
	quick_sort(data->arr, 0, data->a->size - 1);
	if (data->size <= 3)
		sorting(data);
	else
		sort(data, data->a, data->b, data->box);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_data	*data;
	char	**str;

	if (ac < 2)
		return (0);
	a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	b = (t_stack *)ft_calloc(1, sizeof(t_stack));
	data = (t_data *)ft_calloc(1, sizeof(t_data));
	a->name = 'a';
	b->name = 'b';
	data->a = a;
	data->b = b;
	if (ac == 2)
	{
		str = ft_split(av[1], ' ');
		parsing(data, str, ac);
	}
	else
		parsing(data, av, ac);
	check_duplicates(data);
	data->size = a->size;
	push_swap(data);
	return (free_process(data));
}
