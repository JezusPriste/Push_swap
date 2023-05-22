#include "push_swap.h"

static void push(t_stack_node **dest, t_stack_node **src)
{
	t_stack_node *to_push;
	if (*src == NULL)
		return ;
	to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	to_push->prev = NULL;
	if (*dest == NULL)
	{
		*dest = to_push;
		to_push->next = NULL;
	}
	else
	{
		to_push->next = *dest;
		to_push->next->prev = to_push;
		*dest = to_push;
	}
}

void	pa(t_stack_node **a, t_stack_node **b, bool check)
{
	push(a, b);
	if(!check)
		write(1, "pa\n", 3);
}

void	pb(t_stack_node **a, t_stack_node **b, bool check)
{
	push(a, b);
	if(!check)
		write(1, "pb\n", 3);
}