#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>

typedef struct s_stack_node
{
	int					nbr;
    int					value;
    int 				current_position;
	int					final_index;
	int					push_price;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node *target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
} 	t_stack_node;


//split 
char			*ft_substr(char const *s, unsigned int start, size_t len);
unsigned int	ft_counter(char const *s, char c);
int				ft_strcheck(char const *s, char c);
void			*ft_cicle(char const *s, char **str, char c, unsigned int count);
char			**ft_split(char const *s, char c);

//error
void	free_matrix(char **av);
void	free_stack(t_stack_node **stack);
int		error_syntax(char *str_nbr);
void	error_free(t_stack_node **a, char **av, bool flag_ac2);
int		error_repetation(t_stack_node *a, int nbr);

//stack init

static long		ft_atoi(const char *str);
void			stack_init(t_stack_node **a, char **argv, bool flag_argc_2);
t_stack_node	*find_last_node(t_stack_node *head);
void			append_node(t_stack_node **stack, int nbr);
t_stack_node	*return_cheapest(t_stack_node *stack);
int				stack_len(t_stack_node *stack);

//swap commands

static void	swap(t_stack_node **head);
void	sa(t_stack_node **a, bool check);
void	sb(t_stack_node **b, bool check);
void	ss(t_stack_node **a, t_stack_node **b, bool check);

//push commands

static void push(t_stack_node **dest, t_stack_node **src);
void		pa(t_stack_node **a, t_stack_node **b, bool check);
void		pb(t_stack_node **a, t_stack_node **b, bool check);

//rotate commands

static void	rotate(t_stack_node **stack);
void		ra(t_stack_node **a, bool check);
void		rb(t_stack_node **b, bool check);
void		rr(t_stack_node **a, t_stack_node **b, bool check);

//reverse rotate commands

static void	reverse_rotate(t_stack_node **stack);
void		rra(t_stack_node **a, bool check);
void		rrb(t_stack_node **b, bool check);
void		rrr(t_stack_node **a, t_stack_node **b, bool check);

//tiny sort

bool				is_sorted(t_stack_node *stack);
static t_stack_node	*is_highest(t_stack_node *stack);
t_stack_node		*is_smallest(t_stack_node *stack);
void				tiny_sort(t_stack_node **a);
void				handle_five(t_stack_node **a, t_stack_node **b);

//pushswap.c

static void	rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
static void	rev_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest_node);
static void	move_nodes(t_stack_node **a, t_stack_node **b);
void	finish_rotation(t_stack_node **stack, t_stack_node *top, char stack_name);
void    push_swap(t_stack_node **a, t_stack_node **b);

//init swap

void	set_current_position(t_stack_node *stack);
static void set_target(t_stack_node *a, t_stack_node *b);
void	init_nodes(t_stack_node *a, t_stack_node *b);

//push_swap_utils

void			node_evaluation(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *b);
t_stack_node	*return_cheapest(t_stack_node *stack);
int				stack_len(t_stack_node *stack);


# endif