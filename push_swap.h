/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dal-mahr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 10:06:46 by dal-mahr          #+#    #+#             */
/*   Updated: 2024/12/03 10:06:51 by dal-mahr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int					data;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_node	*next;
	struct s_node	*prev;
	struct s_node	*target_node;
}	t_node;

int				error_syntax(char *str_n);
int				error_duplicate(t_node *a, int n);
void			free_stack(t_node **stack);
void			free_errors(t_node **a);

void			init_stack_a(t_node **a, char **argv);
char			**split(char *s, char c);

void			init_nodes_a(t_node *a, t_node *b);
void			init_nodes_b(t_node *a, t_node *b);
void			current_index(t_node *stack);
void			set_cheapest(t_node *stack);
t_node	*get_cheapest(t_node *stack);
void			prep_for_push(t_node **s, t_node *n, char c);

int				stack_len(t_node *stack);
t_node	*find_last(t_node *stack);
bool			stack_sorted(t_node *stack);
t_node	*find_min(t_node *stack);
t_node	*find_max(t_node *stack);

void			sa(t_node **a, bool print);
void			sb(t_node **b, bool print);
void			ss(t_node **a, t_node **b, bool print);
void			ra(t_node **a, bool print);
void			rb(t_node **b, bool print);
void			rr(t_node **a, t_node **b, bool print);
void			rra(t_node **a, bool print);
void			rrb(t_node **b, bool print);
void			rrr(t_node **a, t_node **b, bool print);
void			pa(t_node **a, t_node **b, bool print);
void			pb(t_node **b, t_node **a, bool print);

void			sort_three(t_node **a);
void			sort_stacks(t_node **a, t_node **b);

#endif
