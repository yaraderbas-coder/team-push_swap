/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderbas <yderbas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 13:43:41 by yderbas           #+#    #+#             */
/*   Updated: 2026/11/12 09:07:21 by yderbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	size_stack(t_stack *stack)
{
	t_stack	*now;
	int		i;

	now = stack;
	i = 0;
	while (now != NULL)
	{
		i++;
		now = now -> next;
	}
	return (i);
}

double	compute_disorder(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next_node;
	int		n;
	int		mistakes;
	int		total_pairs;

	current = stack;
	mistakes = 0;
	while (current != NULL)
	{
		next_node = current -> next;
		while (next_node != NULL)
		{
			if (current->value > next_node->value)
				mistakes += 1;
			next_node = next_node -> next;
		}
		current = current -> next;
	}
	n = size_stack(stack);
	total_pairs = n * (n - 1) / 2;
	if (total_pairs == 0)
		return (0);
	return ((double) mistakes / total_pairs);
}
