/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xchouina <xchouina@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:46:11 by xchouina          #+#    #+#             */
/*   Updated: 2022/05/10 12:02:28 by xchouina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	looking_4_smallest(t_stacks *stacks)
{
	int	v;
	int	n;

	v = INT_MAX;
	n = -1;
	while (++n <= stacks->count_a)
	{
		if (v > stacks->a[n].value)
			v = stacks->a[n].value;
	}
	n = 0;
	while (stacks->a[n].value != v)
		n++;
	return (n);
}

int	looking_from_top(t_stacks *stacks)
{
	int	n;

	n = 0;
	while (stacks->b[n].index != biggest(stacks))
		n++;
	return (n);
}

int	looking_from_bot(t_stacks *stacks)
{
	int	v;
	int	n;

	n = stacks->count_b;
	v = 0;
	while (stacks->b[n].index != biggest(stacks))
	{
		n--;
		v++;
	}
	return (v);
}

int	biggest(t_stacks *stacks)
{
	int	v;
	int	n;

	v = -1;
	n = -1;
	while (++n <= stacks->count_b)
	{
		if (v < stacks->b[n].index)
			v = stacks->b[n].index;
	}
	return (v);
}

void	indexing_nmbs(t_stacks *stacks, int n)
{
	int	i;
	int	j;
	int	m;
	int	v;

	i = -1;
	while (++i <= stacks->count_a)
		stacks->a[i].index = -1;
	stacks->a[n].index = 0;
	i = 0;
	while (i < stacks->count_a)
	{
		m = INT_MAX;
		j = -1;
		while (++j <= stacks->count_a)
		{
			if ((m > stacks->a[j].value) && (stacks->a[j].index == -1))
			{
				m = stacks->a[j].value;
				v = j;
			}
		}
		i++;
		stacks->a[v].index = i;
	}
}
