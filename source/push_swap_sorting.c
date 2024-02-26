/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:27:08 by jde-orma          #+#    #+#             */
/*   Updated: 2023/11/01 21:27:08 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libraries/libft/include/libft.h"
#include <stdlib.h>

//Internal quicksort_a stack a 3 array size sorting function
void	ft_quicksort_3a(t_stack *stack, int set)
{
	if (set == 3 && stack->size_a == 3)
		ft_sort_3a(stack);
	else if (set == 2)
	{
		if (stack->a[0] > stack->a[1])
			ft_sa(stack);
	}
	else if (set == 3)
	{
		while (set != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (set == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				ft_sa(stack);
			else if (set == 3 && !(stack->a[2] > stack->a[0]
					&& stack->a[2] > stack->a[1]))
				set = ft_push(stack, set, PUSHTOB);
			else if (stack->a[0] > stack->a[1])
				ft_sa(stack);
			else if (set++)
				ft_pa(stack, 0);
		}
	}
}

//Internal quicksort_b stack b 3 array size sorting function
int	ft_quicksort_3b(t_stack *s, int set)
{
	if (set == 1)
		ft_pa(s, 0);
	else if (set == 2)
	{
		if (s->b[0] < s->b[1])
			ft_sb(s);
		while (set--)
			ft_pa(s, 0);
	}
	else if (set == 3)
	{
		while (set || !(s->a[0] < s->a[1] && s->a[1] < s->a[2]))
		{
			if (set == 1 && s->a[0] > s->a[1])
				ft_sa(s);
			else if (set == 1 || (set >= 2 && s->b[0] > s->b[1])
				|| (set == 3 && s->b[0] > s->b[2]))
				set = ft_push(s, set, PUSHTOA);
			else
				ft_sb(s);
		}
	}
	return (0);
}

int	ft_check_sorted(int *stack, int size, int order)
{
	int	i;

	if (order == ASCENDING)
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] > stack[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] < stack[i])
				return (0);
			i++;
		}
		return (1);
	}
}

void	ft_sort_3a(t_stack *s)
{
	if (s->a[0] > s->a[1] && s->a[0] < s->a[2] && s->a[1] < s->a[2])
		ft_sa(s);
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
	{
		ft_sa(s);
		ft_rra(s);
	}
	if (s->a[0] > s->a[1] && s->a[0] > s->a[2] && s->a[1] < s->a[2])
		ft_ra(s);
	if (s->a[0] < s->a[1] && s->a[0] < s->a[2] && s->a[1] > s->a[2])
	{
		ft_sa(s);
		ft_ra(s);
	}
	if (s->a[0] < s->a[1] && s->a[0] > s->a[2] && s->a[1] > s->a[2])
		ft_rra(s);
}

int	ft_sort(t_stack *stack, int size)
{
	if (ft_check_sorted(stack->a, stack->size_a, ASCENDING) == 0)
	{
		if (size == 2)
			ft_sa(stack);
		else if (size == 3)
			ft_sort_3a(stack);
		else
			ft_quicksort_a(stack, size, 0);
	}
	return (0);
}
