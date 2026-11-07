/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderbas <yderbas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 12:19:56 by yderbas           #+#    #+#             */
/*   Updated: 2026/11/07 19:01:35 by dalqutob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*checker;

	current = stack;
	while (current != NULL)
	{
		checker = current -> next;
		while (checker != NULL)
		{
			if (current -> value == checker -> value)
				return (1);
			checker = checker -> next;
		}
		current = current -> next;
	}
	return (0);
}
