#include "push_swap.h"

void	node_evaluation(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;
	
	len_a = stack_len(a);
	len_b = stack_len(b);
	while (b)
	{
		b->value = b->final_index;
		if (!(b->above_median))
			b->value = len_b - (b->final_index);
		if (b->target_node->above_median)
			b->value += b->target_node->final_index;
		else
			b->value += len_a - (b->target_node->final_index);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long	best_match;
	t_stack_node	*best_match_node;

	if (b == NULL)
		return ;
	best_match = LONG_MAX;
	while (b)
	{
		if (b->value < best_match)
		{
			best_match = b->value;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_node->cheapest = true;
}

t_stack_node	*return_cheapest(t_stack_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	stack_len(t_stack_node *stack)
{
	int	count;

	if (stack == NULL)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}