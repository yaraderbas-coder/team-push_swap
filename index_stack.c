/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderbas <yderbas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 09:18:49 by yderbas           #+#    #+#             */
/*   Updated: 2026/11/19 09:48:31 by yderbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	index_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*other;
	int		rank;

	current = stack;
	while (current != NULL)
	{
		rank = 0;
		other = stack;
		while (other != NULL)
		{
			if (other->value < current-> value)
				rank++;
			other = other -> next;
		}
		current -> index = rank;
		current = current -> next;
	}
}
