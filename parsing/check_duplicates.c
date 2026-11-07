/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderbas <yderbas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 12:19:56 by yderbas           #+#    #+#             */
/*   Updated: 2026/11/07 11:49:11 by yderbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;

	current = stack;
	while (current != NULL)
	{
		runner = current -> next;
		while (runner != NULL)
		{
			if (current -> value == runner -> value)
				return (1);
			runner = runner -> next;
		}
		current = current -> next;
	}
	return (0);
}
