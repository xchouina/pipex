/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:53:08 by xchouina          #+#    #+#             */
/*   Updated: 2022/05/10 12:03:52 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stacks *stacks)
{
	int	c;

	if (stacks->count_b < 0)
		return ;
	write(1, "pa\n", 3);
	c = stacks->count_a;
	if (stacks->count_a > -1)
	{
		while (c >= 0)
		{
			stacks->a[c + 1] = stacks->a[c];
			c--;
		}
	}
	stacks->a[0] = stacks->b[0];
	stacks->count_a++;
	c = -1;
	while (++c < stacks->count_b)
		stacks->b[c] = stacks->b[c + 1];
	stacks->count_b--;
	stacks->b[c].value = 0;
	stacks->b[c].index = 0;
}

void	pb(t_stacks *stacks)
{
	int	c;

	if (stacks->count_a < 0)
		return ;
	write(1, "pb\n", 3);
	c = stacks->count_b;
	if (stacks->count_b > -1)
	{
		while (c >= 0)
		{
			stacks->b[c + 1] = stacks->b[c];
			c--;
		}
	}
	stacks->b[0] = stacks->a[0];
	stacks->count_b++;
	c = -1;
	while (++c < stacks->count_a)
		stacks->a[c] = stacks->a[c + 1];
	stacks->count_a--;
	stacks->a[c].value = 0;
	stacks->a[c].index = 0;
}
