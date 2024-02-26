/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_quicksort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 21:27:36 by jde-orma          #+#    #+#             */
/*   Updated: 2024/02/14 11:41:36 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libraries/libft/include/libft.h"
#include <stdlib.h>

void	ft_tmp_sort_for_median(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	ft_get_median(int *pivot, int *stack, int size)
{
	int		*tmp_stack;
	int		i;

	tmp_stack = (int *)malloc(size * sizeof(int));
	if (!tmp_stack)
		return (EXIT_FAILURE);
	i = 0;
	while (i < size)
	{
		tmp_stack[i] = stack[i];
		i++;
	}
	ft_tmp_sort_for_median(tmp_stack, size);
	*pivot = tmp_stack[size / 2];
	free(tmp_stack);
	return (EXIT_SUCCESS);
}

int	ft_quicksort_a(t_stack *stack, int set, int count)
{
	int	i;
	int	pivot;

	if (ft_check_sorted(stack->a, set, ASCENDING) == 1)
		return (1);
	i = set;
	if (set <= 3)
	{
		ft_quicksort_3a(stack, set);
		return (1);
	}
	if (!count && ft_get_median(&pivot, stack->a, set))
		return (0);
	while (set != i / 2 + i % 2)
	{
		if (stack->a[0] < pivot && (set--))
			ft_pb(stack, 0);
		else if (++count)
			ft_ra(stack);
	}
	while (i / 2 + i % 2 != stack->size_a && count--)
		ft_rra(stack);
	return (ft_quicksort_a(stack, i / 2 + i % 2, 0)
		&& ft_quicksort_b(stack, i / 2, 0));
	return (1);
}

int	ft_quicksort_b(t_stack *stack, int set, int count)
{
	int	i;
	int	pivot;

	if (!count && ft_check_sorted(stack->b, set, DESCENDING) == 1)
		while (set--)
			ft_pa(stack, 0);
	if (set <= 3)
	{
		ft_quicksort_3b(stack, set);
		return (1);
	}
	i = set;
	if (ft_get_median(&pivot, stack->b, set))
		return (0);
	while (set != i / 2)
	{
		if (stack->b[0] >= pivot && set--)
			ft_pa(stack, 0);
		else if (++count)
			ft_rb(stack);
	}
	while (i / 2 != stack->size_b && count--)
		ft_rrb(stack);
	return (ft_quicksort_a(stack, i / 2 + i % 2, 0)
		&& ft_quicksort_b(stack, i / 2, 0));
}
