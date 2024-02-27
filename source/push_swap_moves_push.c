/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves_push.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:21:02 by jde-orma          #+#    #+#             */
/*   Updated: 2023/12/05 16:21:02 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libraries/libft/include/libft.h"

int	ft_push(t_stack *stack, int set, int operation)
{
	if (operation == PUSHTOB)
		ft_pb(stack, 0);
	else
		ft_pa(stack, 0);
	set--;
	return (set);
}

void	ft_pa(t_stack *stack, int i)
{
	if (stack->size_b)
	{
		stack->a = ft_rearray(stack->a, stack->size_a, stack->size_a + 1);
		stack->size_a++;
		i = stack->size_a - 1;
		while (i > 0)
		{
			stack->a[i] = stack->a[i - 1];
			i--;
		}
		stack->a[0] = stack->b[0];
		i = 0;
		while (i < stack->size_b - 1)
		{
			stack->b[i] = stack->b[i + 1];
			i++;
		}
		stack->b = ft_rearray(stack->b, stack->size_b, stack->size_b - 1);
		stack->size_b--;
		ft_printf("pa\n");
	}
	return ;
}

void	ft_pb(t_stack *stack, int i)
{
	if (stack->size_a)
	{
		stack->b = ft_rearray(stack->b, stack->size_b, stack->size_b + 1);
		stack->size_b++;
		i = stack->size_b - 1;
		while (i > 0)
		{
			stack->b[i] = stack->b[i - 1];
			i--;
		}
		stack->b[0] = stack->a[0];
		i = 0;
		while (i < stack->size_a - 1)
		{
			stack->a[i] = stack->a[i + 1];
			i++;
		}
		stack->a = ft_rearray(stack->a, stack->size_a, stack->size_a - 1);
		stack->size_a--;
		ft_printf("pb\n");
	}
	return ;
}
