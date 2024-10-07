/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:15:16 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/07 12:52:40 by cefelix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicates(t_node *list, int n)
{
	while (list)
	{
		if (list->value == n)
			return (0);
		list = list->next;
	}
	return (1);
}

int	ft_validate_input(char **av, int i, t_node **list, int start_from)
{
	while (i-- > start_from)
	{
		if (!ft_check_is_num(av[i]))
			return (0);
		if (!ft_check_max_min(av[i]))
			return (0);
		if (!ft_check_duplicates(*list, atoi(av[i])))
			return (0);
		ft_init_stack(list, atoi(av[i]));
	}
	return (1);
}

int	ft_case_one_arg(char **arguments)
{
	if (!ft_check_is_num(arguments[0]))
		return (ft_free_matrix(arguments), ft_printf("Error\n"), 0);
	if (!ft_check_max_min(arguments[0]))
		return (ft_free_matrix(arguments), ft_printf("Error\n"), 0);
	return (ft_free_matrix(arguments), 0);
}

int	ft_validate_global(int ac, char **av, t_node **stack_a)
{
	char	**arguments;
	int		i;

	if (ac == 2)
	{
		arguments = ft_split(av[1], ' ');
		i = ft_count_args(arguments);
		if (i == 0)
			return (ft_free_matrix(arguments), 0);
		else if (i == 1)
		{
			if (!ft_case_one_arg(arguments))
				return (0);
		}
		else if (!ft_validate_input(arguments, i, stack_a, 0))
			return (ft_free_matrix(arguments), ft_free_stack(*stack_a),
				ft_printf("Error\n"), 0);
		ft_free_matrix(arguments);
	}
	else if (ac > 2)
		if (!ft_validate_input(av, ac, stack_a, 1))
			return (ft_free_stack(*stack_a), ft_printf("Error\n"), 0);
	if (ft_check_sorted(*stack_a))
		return (ft_free_stack(*stack_a), 0);
	return (1);
}
