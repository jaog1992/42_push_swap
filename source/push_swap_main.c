/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 6:22:32 by jde-orma           #+#    #+#             */
/*   Updated: 2023/10/31 6:22:32 by jde-orma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libraries/libft/include/libft.h"

t_stack	*inicializar_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_print_error("Memory allocation for Stack data type failed\n");
		return (stack);
	}
	stack->error = 0;
	stack->a = NULL;
	stack->b = NULL;
	stack->size_a = 0;
	stack->size_b = 0;
	return (stack);
}

void	stack_fill(t_stack *stack, int argc, char **argv)
{
	int		i;
	char	**str;

	i = 1;
	if (argc == 2)
		str = ft_split(argv[1], ' ');
	while (i <= stack->size_a)
	{
		if (argc == 2)
			stack->a[i - 1] = ft_atoi_error(str[i - 1], stack);
		else
			stack->a[i - 1] = ft_atoi_error(argv[i], stack);
		if (stack->error > 0)
			return ;
		i++;
	}
}

int	stack_ini(t_stack *stack, int argc, char **argv)
{
	int			size;

	if (argc == 1)
		return (write(2, "Error\n", 6));
	if (argc == 2)
		size = ft_double_strlen(ft_split(argv[1], ' '), 1) + 1;
	else
		size = ft_double_strlen(argv, 0);
	stack->a = malloc((size) * sizeof(int));
	if (!stack->a)
		return (EXIT_FAILURE);
	stack->size_a = size - 1;
	stack_fill(stack, argc, argv);
	if (stack->error > 0)
		return (EXIT_FAILURE);
	if (ft_check_duplicates(stack->a, size - 1) != 0)
	{
		ft_error(stack);
		return (EXIT_FAILURE);
	}
	ft_sort(stack, stack->size_a);
	return (EXIT_SUCCESS);
}

void	free_malloc(t_stack *stack)
{
	if (stack->a != NULL)
		free(stack->a);
	if (stack->b != NULL)
		free(stack->b);
	if (stack != NULL)
		free(stack);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	stack = inicializar_stack();
	if (!stack)
		return (EXIT_FAILURE);
	if (stack_ini(stack, argc, argv) != 0 || stack->error > 0)
	{
		free_malloc(stack);
		return (EXIT_FAILURE);
	}
	free_malloc(stack);
	return (EXIT_SUCCESS);
}
