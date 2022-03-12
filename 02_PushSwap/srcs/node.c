#include "../include/pushswap.h"

static t_node	*new_node(t_data *data, int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		error_process(data);
	node->value = value;
	node->pre = NULL;
	node->nxt = NULL;
	return (node);
}

void	stack_build(t_data *data, t_stack *stack, int value)
{
	t_node	*node;

	node = new_node(data, value);
	if (!stack)
		return ;
	if (!stack->head)
	{
		node->pre = node;
		node->nxt = node;
		stack->head = node;
	}
	else
	{
		stack->head->pre->nxt = node;
		node->pre = stack->head->pre;
		stack->head->pre = node;
		node->nxt = stack->head;
	}
	stack->size++;
}
