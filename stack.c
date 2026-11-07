/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderbas <yderbas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 14:15:10 by yderbas           #+#    #+#             */
/*   Updated: 2026/11/07 12:45:21 by yderbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = value;
	new -> index = 0;
	new -> next = NULL;
	return (new);
}

t_stack	*create_stack(int *numbers, int size)
{
	t_stack	*head;
	t_stack	*add;
	int		i;

	if (size <= 0)
		return (NULL);
	head = new_node(numbers[0]);
	if (!head)
		return (NULL);
	add = head;
	i = 1;
	while (i < size)
	{
		add -> next = new_node(numbers[i]);
		if (!add -> next)
		{
			free_stack(&head);
			return (NULL);
		}
		add = add ->next;
		i++;
	}
	return (head);
}

void	free_stack(t_stack **stc)
{
	t_stack	*temp;

	while (*stc)
	{
		temp = *stc;
		*stc = (*stc) -> next;
		free (temp);
	}
}
