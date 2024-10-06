/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:15:49 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/06 15:09:13 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_stack_get_top(t_node *list)
{
	return (list);
}

t_node	*ft_stack_get_last(t_node *list)
{
	t_node	*tmp;

	tmp = NULL;
	while (list)
	{
		tmp = list;
		list = list->next;
	}
	return (tmp);
}

void	ft_reverse_rotate_rotate(t_node **a, t_node **b)
{
	ft_reverse_rotate_a(a, 0);
	ft_reverse_rotate_b(b, 0);
	ft_printf("rrr\n");
}

void	ft_rotate_rotate(t_node **a, t_node **b)
{
	ft_rotate_a(a, 0);
	ft_rotate_b(b, 0);
	ft_printf("rr\n");
}
