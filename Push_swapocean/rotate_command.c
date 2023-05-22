#include "push_swap.h"

static void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	if (*stack == NULL || stack == NULL)
		return ;
	last = find_last_node(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_stack_node **a, bool check)
{
	rotate(a);
	if (!check)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool check)
{
	rotate(b);
	if (!check)
		write(1, "rb\n", 3);
}

void	rr(t_stack_node **a, t_stack_node **b, bool check)
{
	rotate(a);
	rotate(b);
	if (!check)
		write(1, "rr\n", 3);
}