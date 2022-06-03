/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:53:18 by xchouina          #+#    #+#             */
/*   Updated: 2022/05/11 12:43:31 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	t_stack	t;

	if (stacks->count_a < 1)
		return ;
	write(1, "sa\n", 3);
	t = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = t;
}

void	sb(t_stacks *stacks)
{
	t_stack	t;

	if (stacks->count_b < 1)
		return ;
	write(1, "sb\n", 3);
	t = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = t;
}

void	ss(t_stacks *stacks)
{
	t_stack	t;

	if (stacks->count_a < 1)
		return ;
	write(1, "ss\n", 3);
	t = stacks->a[0];
	stacks->a[0] = stacks->a[1];
	stacks->a[1] = t;
	if (stacks->count_b < 1)
		return ;
	t = stacks->b[0];
	stacks->b[0] = stacks->b[1];
	stacks->b[1] = t;
}
