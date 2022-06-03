/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   partitions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:50:32 by xchouina          #+#    #+#             */
/*   Updated: 2022/05/10 14:33:40 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	am_i_an_integer(char **nmbs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (nmbs[i] != NULL)
	{
		if (ft_atol(nmbs[i]) > INT_MAX || ft_atol(nmbs[i]) < INT_MIN)
			return (0);
		j = 0;
		while (nmbs[i][j] != '\0')
		{
			if ((ft_isdigit(nmbs[i][j]) == 1)
			|| ((nmbs[i][0] == '-' && ((ft_isdigit(nmbs[i][j + 1]) == 1)))))
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	am_i_a_duplicate(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->count_a)
	{
		j = i + 1;
		while (j <= stacks->count_a)
		{
			if (stacks->a[i].value == stacks->a[j].value)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	error(t_stacks *stacks, int argc, char **nmbs)
{
	the_liberator(stacks, argc, nmbs);
	write(2, "Error\n", 6);
	return (0);
}
