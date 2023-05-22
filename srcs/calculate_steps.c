/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_steps.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:44:41 by ogenc             #+#    #+#             */
/*   Updated: 2023/05/20 22:28:52 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_exit_e(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	calculate_steps_2_u(t_list *list, int i, int take)
{
	if (take < list->b_len / 2)
	{
		if (i < (list->a_len / 2))
		{
			if (take <= i + 1)
				list->steps[i] = i + 1;
			else
				list->steps[i] = take;
		}
		else
			list->steps[i] += take;
	}
	else if (take >= list->b_len / 2)
	{
		if (i >= list->a_len / 2)
		{
			if (list->b_len - take <= list->a_len - i)
				list->steps[i] = list->a_len - i;
			else
				list->steps[i] = list->b_len - take;
		}
		else
			list->steps[i] += list->b_len - take;
	}
}

void	calculate_steps_2(t_list *list, int i)
{
	int	index;
	int	take;

	index = 0;
	take = 0;
	while (index < list->b_len)
	{
		while (list->a[i] - list->b[take] <= 0)
			take++;
		if (list->a[i] - list->b[take] > list->a[i] - list->b[index] && \
				list->a[i] - list->b[index] > 0)
					take = index;
		index++;
	}
	calculate_steps_2_u(list, i, take);
}

void	calculate_steps_min_u(t_list *list, int i)
{
	if (list->b_max_i < list->b_len / 2)
	{
		if (i < (list->a_len / 2))
		{
			if (list->b_max_i <= i + 1)
				list->steps[i] = i + 1;
			else
				list->steps[i] = list->b_max_i;
		}
		else
			list->steps[i] += list->b_max_i;
	}
	else if (list->b_max_i >= list->b_len / 2)
		list->steps[i] += list->b_len - list->b_max_i;
}

void	calculate_steps(t_list *list)
{
	int	i;

	i = 0;
	while (i < list->a_len)
	{
		if (i < (list->a_len / 2))
			list->steps[i] = i + 1;
		else if (i >= list->a_len / 2)
			list->steps[i] = list->a_len - i + 1;
		if (list->a[i] < list->b[list->b_min_i])
			calculate_steps_min_u(list, i);
		else
			calculate_steps_2(list, i);
		i++;
	}
}
