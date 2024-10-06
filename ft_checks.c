/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cefelix <cefelix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:15:16 by cefelix           #+#    #+#             */
/*   Updated: 2024/10/06 15:09:13 by cefelix          ###   ########.fr       */
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

int	ft_validate_input_one(char **av, int i, t_node **list)
{
	while (--i > 0)
	{
		if (!ft_isbigdigit(av[i]))
			return (0);
		if (!ft_isvalid(atoi(av[i])))
			return (0);
		if (!ft_check_duplicates(*list, atoi(av[i])))
			return (0);
		ft_init_list(list, atoi(av[i]));
	}
	return (1);
}

int	ft_validate_input_two(char **av, int i, t_node **list)
{
	while (i-- > 0)
	{
		if (!ft_isbigdigit(av[i]))
			return (0);
		if (!ft_isvalid(atoi(av[i])))
			return (0);
		if (!ft_check_duplicates(*list, atoi(av[i])))
			return (0);
		ft_init_list(list, atoi(av[i]));
	}
	return (1);
}

int	ft_case_one_arg(char **rede)
{
	if (!ft_isbigdigit(rede[0]))
		return (ft_free_matrix(rede), ft_printf("Error\n"), 0);
	if (!ft_isvalid(atoi(rede[0])))
		return (ft_free_matrix(rede), ft_printf("Error\n"), 0);
	return (ft_free_matrix(rede), 0);
}

int	ft_validate_global(int ac, char **av, t_node **pilha1)
{
	char	**rede;
	int		i;

	if (ac == 2)
	{
		rede = ft_split(av[1], ' ');
		i = ft_count_array(rede);
		if (i == 0)
			return (ft_free_matrix(rede), 0);
		else if (i == 1)
		{
			if (!ft_case_one_arg(rede))
				return (0);
		}
		else if (!ft_validate_input_two(rede, i, pilha1))
			return (ft_free_matrix(rede), ft_free_list(*pilha1),
				ft_printf("Error\n"), 0);
		ft_free_matrix(rede);
	}
	else if (ac > 2)
		if (!ft_validate_input_one(av, ac, pilha1))
			return (ft_free_list(*pilha1), ft_printf("Error\n"), 0);
	if (ft_check_sorted(*pilha1))
		return (ft_free_list(*pilha1), 0);
	return (1);
}
