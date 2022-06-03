/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 08:36:25 by xchouina          #+#    #+#             */
/*   Updated: 2022/05/10 12:12:14 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three(t_stacks *stacks)
{
	if (case_one(stacks) == 1)
		return ;
	else if (case_two(stacks) == 1)
	{
		if (stacks->a[0].value > stacks->a[2].value)
			rra(stacks, 0);
		else if (stacks->a[0].value < stacks->a[2].value)
		{
			rra(stacks, 0);
			sa(stacks);
		}
	}
	else if (case_three(stacks) == 1)
	{
		if (stacks->a[0].value < stacks->a[2].value)
			sa(stacks);
		else
			ra(stacks, 0);
	}
	else if (case_four(stacks) == 1)
	{
		sa(stacks);
		rra(stacks, 0);
	}
}

int	case_one(t_stacks *stacks)
{
	if ((stacks->a[0].value < stacks->a[1].value)
		&& (stacks->a[1].value < stacks->a[2].value))
		return (1);
	else
		return (0);
}

int	case_two(t_stacks *stacks)
{
	if ((stacks->a[0].value < stacks->a[1].value)
		&& (stacks->a[1].value > stacks->a[2].value))
		return (1);
	else
		return (0);
}

int	case_three(t_stacks *stacks)
{
	if ((stacks->a[0].value > stacks->a[1].value)
		&& (stacks->a[1].value < stacks->a[2].value))
		return (1);
	else
		return (0);
}

int	case_four(t_stacks *stacks)
{
	if ((stacks->a[0].value > stacks->a[1].value)
		&& (stacks->a[1].value > stacks->a[2].value))
		return (1);
	else
		return (0);
}
