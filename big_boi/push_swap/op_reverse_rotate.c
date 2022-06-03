/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:53:14 by xchouina          #+#    #+#             */
/*   Updated: 2022/05/10 12:04:44 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks, int rrr)
{
	t_stack	t;
	int		c;

	if (stacks->count_a < 1)
		return ;
	if (!rrr)
		write(1, "rra\n", 4);
	t = stacks->a[stacks->count_a];
	c = stacks->count_a;
	while (c >= 0)
	{
		stacks->a[c] = stacks->a[c - 1];
		c--;
	}
	stacks->a[0] = t;
}

void	rrb(t_stacks *stacks, int rrr)
{
	t_stack	t;
	int		c;

	if (stacks->count_b < 1)
		return ;
	if (!rrr)
		write(1, "rrb\n", 4);
	t = stacks->b[stacks->count_b];
	c = stacks->count_b;
	while (c >= 0)
	{
		stacks->b[c] = stacks->b[c - 1];
		c--;
	}
	stacks->b[0] = t;
}

void	rrr(t_stacks *stacks)
{
	write(1, "rrr\n", 4);
	rra(stacks, 1);
	rrb(stacks, 1);
}
