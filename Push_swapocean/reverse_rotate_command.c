#include "push_swap.h"

static void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	int		len;

	len = stack_len(*stack);
	if (*stack == NULL || stack == NULL || len == 1)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_stack_node **a, bool check)
{
	reverse_rotate(a);
	if (!check)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool check)
{
	reverse_rotate(b);
	if (!check)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack_node **a, t_stack_node **b, bool check)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!check)
		write(1, "rrr\n", 4);
}