/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_hundred_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:42:37 by xchouina          #+#    #+#             */
/*   Updated: 2022/05/10 13:04:28 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_home(t_stacks *stacks)
{
	while (stacks->count_b > -1)
	{
		rotating_stack_b(stacks);
		pa(stacks);
		if (stacks->a[0].index > stacks->a[1].index)
			sa(stacks);
	}
}

void	rotating_stack_b(t_stacks *stacks)
{
	int	i;

	if (looking_from_top(stacks) < looking_from_bot(stacks))
	{
		i = looking_from_top(stacks);
		while (i != 0)
		{
			rb(stacks, 0);
			i--;
		}
	}
	else
	{
		i = looking_from_bot(stacks);
		while (i != 0)
		{
			rrb(stacks, 0);
			i--;
		}
		rrb(stacks, 0);
	}
}

int	best_chunky(t_stacks *stacks)
{
	int	c;

	if ((stacks->max <= 100) && (stacks->max > 50))
		c = 15;
	if (stacks->max > 100)
		c = 33;
	else
		c = 10;
	return (c);
}
