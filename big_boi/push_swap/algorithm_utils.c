/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 14:16:10 by xchouina          #+#    #+#             */
/*   Updated: 2022/05/10 10:25:59 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_me_the_smolls(t_stacks *stacks)
{
	int	m;
	int	n;
	int	i;

	m = INT_MAX;
	n = INT_MAX;
	i = -1;
	while (++i <= stacks->count_a)
	{
		if (m > stacks->a[i].value)
			m = stacks->a[i].value;
		if (n > m)
			ft_pt_swap(&m, &n);
	}
	exclude_the_weak(stacks, m, n);
}

void	exclude_the_weak(t_stacks *stacks, int m, int n)
{
	int	c;

	c = 4;
	while ((c >= 0) && (stacks->count_a > 2))
	{
		if ((stacks->a[0].value == m) || (stacks->a[0].value == n))
			pb(stacks);
		else
			ra(stacks, 0);
		c--;
	}
}

int	sorted(t_stacks *stacks)
{
	int	c;

	c = 0;
	while (c < stacks->count_a)
	{
		if (stacks->a[c].value < stacks->a[c + 1].value)
			c++;
		else
			return (0);
	}
	if (stacks->count_b >= 0)
		return (0);
	return (1);
}

void	print_stacks(t_stacks *stacks)
{
	int	i;

	i = 0;
	while (i <= stacks->count_a)
	{
		printf("\033[0;32m|A%d|Value = %d |Index = %d\033[0;0m\n",
			i, stacks->a[i].value, stacks->a[i].index);
		i++;
	}
	i = 0;
	while (i <= stacks->count_b)
	{
		printf("			\033[0;31m|B%d|Value = %d |Index = %d\033[0;0m\n",
			i, stacks->b[i].value, stacks->b[i].index);
		i++;
	}
	printf("\n");
}
