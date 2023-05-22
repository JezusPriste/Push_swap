#include "push_swap.h"

//ensure that the passed stack is sorted

bool	is_sorted(t_stack_node *stack)
{
	if (stack == NULL)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

//find the highest number in the passed stack

static t_stack_node	*is_highest(t_stack_node *stack)
{
	int     high;
	t_stack_node *highest;

	if (stack == NULL)
		return (NULL);
	high = INT_MIN;
	while (stack)
	{
		if (stack->nbr > high)
		{
			high = stack->nbr;
			highest = stack;
		}
		stack = stack->next;
	}
	return (highest);
}

t_stack_node	*is_smallest(t_stack_node *stack)
{
	long	small;
	t_stack_node	*smallest;

	if (stack == NULL)
		return (NULL);
	small = LONG_MAX;
	while (stack)
	{
		if (stack->nbr < small)
		{
			small = stack->nbr;
			smallest = stack;
		}
		stack = stack->next;
	}
	return (smallest);
}

//sort only stacks with 3 numbers

void	tiny_sort(t_stack_node **a)
{
	t_stack_node *highest;
	
	highest = is_highest(*a);
	if (*a == highest)
		ra(a, false);
	else if ((*a)->next == highest)
		rra(a, false);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, false);
}

void	handle_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, is_smallest(*a), 'a');
		pb(b, a, false);
	}
}