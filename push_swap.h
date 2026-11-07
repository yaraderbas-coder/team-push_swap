/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yderbas <yderbas@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 12:37:15 by yderbas           #+#    #+#             */
/*   Updated: 2026/11/07 11:43:49 by yderbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
        int value;
        struct s_stack *next;
}       t_stack;


t_stack  *new_node(int value);
t_stack  *create_stack(int *numbers, int size);
void     free_stack(t_stack **stc);
int     push_stack(t_stack **src, t_stack **dest);
void    pb(t_stack **stc_a, t_stack **stc_b);
void    pa(t_stack **stc_a, t_stack **stc_b);
int     swap_stack(t_stack **stack);
void    sa(t_stack **stack_a);
void    sb(t_stack **stack_b);
void    ss(t_stack **stack_a, t_stack **stack_b);
int     parse_num(char *str, int *result);
int     has_duplicates(t_stack *stack);
int     parse_args(int argc, char **argv);
int     check_errors(t_stack *stack);
#endif
