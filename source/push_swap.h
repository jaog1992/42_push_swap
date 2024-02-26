/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 04:49:52 by jde-orma          #+#    #+#             */
/*   Updated: 2023/10/31 04:49:52 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libraries/libft/include/libft.h"

typedef struct s_stack
{
	int	error;
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

# define ASCENDING 0
# define DESCENDING 1
# define PUSHTOA 0
# define PUSHTOB 1

// EXIT_SUCCESS	0
// EXIT_FAILURE	1

//Moves
void	ft_pa(t_stack *stack, int i);
void	ft_pb(t_stack *stack, int i);
void	ft_ra(t_stack *stack);
void	ft_rb(t_stack *stack);
void	ft_rr(t_stack *stack);
void	ft_sa(t_stack *stack);
void	ft_sb(t_stack *stack);
void	ft_ss(t_stack *stack);
void	ft_rra(t_stack *stack);
void	ft_rrb(t_stack *stack);
void	ft_rrr(t_stack *stack);
// Utilities
void	ft_error(t_stack *stack);
int		ft_atoi_error(char *str, t_stack *stack);
int		ft_check_duplicates(int *stack, int set);
int		ft_check_sorted(int *stack, int size, int order);
int		*ft_rearray(int *array, size_t old_size, size_t new_size);
//Sorting functions
int		ft_push(t_stack *stack, int set, int operation);
int		ft_get_median(int *pivot, int *stack, int size);
void	ft_tmp_sort_for_median(int *tmp_stack, int size);
int		ft_sort(t_stack *stack, int size);
void	ft_sort_3a(t_stack *s);
void	ft_quicksort_3a(t_stack *stack, int set);
int		ft_quicksort_3b(t_stack *s, int set);
int		ft_quicksort_a(t_stack *stack, int set, int count);
int		ft_quicksort_b(t_stack *stack, int set, int count);
#endif
