#include "../include/pushswap.h"

void	push(t_stack *stack, t_node *node)
{
	if (!stack || !node)
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
		stack->head = node;
	}
	stack->size++;
}

t_node	*pop(t_stack *stack)
{
	t_node	*poped_node;

	if (!stack || !stack->size)
		return (NULL);
	poped_node = stack->head;
	if (stack->size == 1)
		stack->head = NULL;
	else
	{
		stack->head = stack->head->nxt;
		poped_node->pre->nxt = poped_node->nxt;
		poped_node->nxt->pre = poped_node->pre;
	}
	poped_node->pre = NULL;
	poped_node->nxt = NULL;
	stack->size--;
	return (poped_node);
}
