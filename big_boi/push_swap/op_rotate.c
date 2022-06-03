/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:53:12 by xchouina          #+#    #+#             */
/*   Updated: 2022/05/10 12:05:23 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks, int rr)
{
	t_stack	t;
	int		c;

	if (stacks->count_a < 2)
		return ;
	if (!rr)
		write(1, "ra\n", 3);
	t = stacks->a[0];
	c = -1;
	while (++c <= stacks->count_a)
		stacks->a[c] = stacks->a[c + 1];
	stacks->a[c - 1] = t;
}

void	rb(t_stacks *stacks, int rr)
{
	t_stack	t;
	int		c;

	if (stacks->count_b < 2)
		return ;
	if (!rr)
		write(1, "rb\n", 3);
	t = stacks->b[0];
	c = -1;
	while (++c <= stacks->count_b)
		stacks->b[c] = stacks->b[c + 1];
	stacks->b[c - 1] = t;
}

void	rr(t_stacks *stacks)
{
	write(1, "rr\n", 3);
	ra(stacks, 1);
	rb(stacks, 1);
}
