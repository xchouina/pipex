/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:42:25 by xchouina          #+#    #+#             */
/*   Updated: 2022/05/10 11:19:38 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	manager(t_stacks *stacks)
{
	if (stacks->max == 2)
		two(stacks);
	else if (stacks->max == 3)
		three(stacks);
	else if (stacks->max == 4)
		four(stacks);
	else if (stacks->max == 5)
		five(stacks);
	else
		ft_hundred(stacks);
}

void	two(t_stacks *stacks)
{
	if (stacks->a[0].value > stacks->a[1].value)
		sa(stacks);
}

void	four(t_stacks *stacks)
{
	if (sorted(stacks) == 1)
		return ;
	pb(stacks);
	three(stacks);
	pa(stacks);
	if (sorted(stacks) == 1)
		return ;
	else if (stacks->a[0].value > stacks->a[stacks->count_a].value)
		ra(stacks, 0);
	else
	{
		ra(stacks, 0);
		four(stacks);
	}
}

void	five(t_stacks *stacks)
{
	if (sorted(stacks) == 1)
		return ;
	find_me_the_smolls(stacks);
	three(stacks);
	if (stacks->b[0].value < stacks->b[1].value)
		sb(stacks);
	pa(stacks);
	pa(stacks);
}
