#include "push_swap.h"

void	ft_sort_two(t_node **a)
{
	if (!ft_check_sorted(*a))
		ft_swap_a(a, 1);
}

void	ft_sort_three(t_node **a)
{
	if (ft_stack_get_min(*a) == (*a)->value)
	{
		ft_reverse_rotate_a(a, 1);
		ft_swap_a(a, 1);
	}
	else if (ft_stack_get_max(*a) == (*a)->value)
	{
		ft_rotate_a(a, 1);
		if (!ft_check_sorted(*a))
			ft_swap_a(a, 1);
	}
	else
	{
		if (ft_stack_get_min(*a) == (*a)->next->value)
			ft_swap_a(a, 1);
		else
			ft_reverse_rotate_a(a, 1);
	}
}
