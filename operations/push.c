/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderbas <yderbas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 16:37:38 by yderbas           #+#    #+#             */
/*   Updated: 2026/11/04 17:16:30 by yderbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	push_stack(t_stack **src, t_stack **dest)
{
	t_stack	*temp;

	if (!src || !*src)
		return (0);
	temp = *src;
	*src = *src -> next;
	temp -> next = *dest;
	*dest = temp;
	return (1);
}

void	pb(t_stack **stc_a, t_stack **stc_b)
{
	if (push_stack(stc_a, stc_b))
		write(1, "pb\n", 3);
}

void	pa(t_stack **stc_a, t_stack **stc_b)
{
	if (push_stack(stc_b, stc_a))
		write(1, "pa\n", 3);
}
