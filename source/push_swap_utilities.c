/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-orma <jde-orma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 16:41:05 by jde-orma          #+#    #+#             */
/*   Updated: 2023/12/05 16:41:05 by jde-orma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libraries/libft/include/libft.h"

int	*ft_rearray(int	*array, size_t	old_size, size_t	new_size)
{
	int		*new_array;
	size_t	elem_to_copy;

	new_array = (int *)malloc(new_size * sizeof(int));
	if (new_array == NULL)
	{
		ft_print_error("No se pudo asignar memoria.");
		return (NULL);
	}
	if (old_size < new_size)
		elem_to_copy = old_size;
	else
		elem_to_copy = new_size;
	ft_memcpy(new_array, array, elem_to_copy * sizeof(int));
	free(array);
	return (new_array);
}

void	ft_error(t_stack *stack)
{
	write(2, "Error\n", 6);
	stack->error++;
}

int	ft_atoi_error(char *str, t_stack *stack)
{
	unsigned int		i;
	int					neg;
	unsigned long int	num;

	i = 0;
	num = 0;
	neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		neg = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error(stack);
		num = (str[i] - '0') + (num * 10);
		i++;
	}
	if ((num > 2147483648 && neg == -1) || (num > 2147483647 && neg == 1))
		ft_error(stack);
	return (num * neg);
}

int	ft_check_duplicates(int *stack, int set)
{
	int	i;
	int	j;

	i = 0;
	while (i < set - 1)
	{
		j = i + 1;
		while (j < set)
		{
			if (stack[i] == stack[j])
				return (EXIT_FAILURE);
			j++;
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
