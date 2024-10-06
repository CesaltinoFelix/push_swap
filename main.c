/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:15:52 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/06 15:09:13 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

void	ft_init_list(t_node **list, int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (new == NULL)
		return ;
	new->value = value;
	new->next = *list;
	*list = new;
}

void	ft_print_list(t_node *list)
{
	while (list)
	{
		ft_printf("%d\n", list->value);
		list = list->next;
	}
}

int	main(int ac, char **av)
{
	t_node	*pilha1;
	t_node	*pilha2;

	if (ac == 1)
		return (0);
	pilha1 = NULL;
	pilha2 = NULL;
	if (!ft_validate_global(ac, av, &pilha1))
		return (0);
	if (ft_count_list(pilha1) == 2)
		ft_sort_two(&pilha1);
	else if (ft_count_list(pilha1) == 3)
		ft_sort_three(&pilha1);
	else
		ft_sort_more(&pilha1, &pilha2);
	ft_free_list(pilha1);
	ft_free_list(pilha2);
	return (0);
}
