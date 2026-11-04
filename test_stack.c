/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderbas <yderbas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 17:01:19 by yderbas           #+#    #+#             */
/*   Updated: 2026/11/04 10:52:43 by yderbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

typedef struct s_stack
{
	int value;
	struct s_stack *next;
}	t_stack;

t_stack *new_node (int value)
{
	t_stack *new;
	new = malloc(sizeof(t_stack));
	if(!new)
		return(NULL);
	new -> value = value;
	new -> next = NULL;
	return(new);
}
static void	ft_putnbr(long num, int fd)
{
	char	c;

	if (num >= 10)
		ft_putnbr(num / 10, fd);
	c = (num % 10) + '0';
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	ft_putnbr(num, fd);
}
void free_stack(t_stack *stc)
{
	t_stack *temp;
	while(stc)
	{
		temp = stc;
		stc = stc -> next;
		free(temp);
	}
}

t_stack *create_stack(int *numbers, int size)
{
	if (size <= 0)
		return(NULL);
	t_stack *head;
	t_stack *add;
	head = new_node(numbers[0]);
	if(!head)
		return(NULL);
	add = head;
	int i;
	i = 1;
	while(i < size)
	{
		add -> next = new_node(numbers[i]);
		if(!add -> next)
		{
			free_stack(head);
			return(NULL);
		}
		add = add ->next;
		i++;
	}
	return(head);
}
void print_stack(t_stack *stc)
{
	while(stc)
	{
		ft_putnbr_fd(stc->value, 1);
		write(1, " ",1);
		stc = stc -> next;
	}
} 
int main()
{
	t_stack *stack;
	int num[] = {2, 4, 6, 7, 33, 100};
	stack = create_stack(num, 6);
	if(!stack)
		return(1);
	print_stack(stack);
	free(stack);
	return(0);
}
