#include "push_swap.h"

void	ft_push_b(t_node **a, t_node **b)
{
	t_node	*top;

	if (*a == NULL)
		return ;
	top = ft_stack_get_top(*a);
	*a = (*a)->next;
	top->next = *b;
	*b = top;
	ft_printf("pb\n");
}

void	ft_push_a(t_node **a, t_node **b)
{
	t_node	*top;

	if (*b == NULL)
		return ;
	top = ft_stack_get_top(*b);
	*b = (*b)->next;
	top->next = *a;
	*a = top;
	ft_printf("pa\n");
}
