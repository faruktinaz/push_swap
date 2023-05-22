/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftsort2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:44:27 by ogenc             #+#    #+#             */
/*   Updated: 2023/05/20 21:48:55 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	ft_sort_two(t_list *list)
{
	if (list->a[0] > list->a[1])
		sa(list);
}

void	ft_sort_three(t_list *list)
{
	if (list->a[0] < list->a[1] && list->a[1] < list->a[2])
		return ;
	if (list->a[0] < list->a[1])
	{
		if (list->a[0] > list->a[2])
			rra(list);
		else
		{
			rra(list);
			sa(list);
		}
	}
	else
	{
		if (list->a[0] < list->a[2])
			sa(list);
		else if (list->a[1] < list->a[2])
			ra(list);
		else
		{
			sa(list);
			rra(list);
		}
	}
}

void	ft_sort_five(t_list *list)
{
	while (a_min(list) != 0)
	{
		if (a_min(list) >= 2)
			rra(list);
		else
			ra(list);
	}
	pb(list);
	ft_sort_four(list);
	pa(list);
}

void	ft_sort_four(t_list *list)
{
	while (a_min(list) != 0)
	{
		if (a_min(list) == 1)
			ra(list);
		else if (a_min(list) == 2)
			rra(list);
		else if (a_min(list) == 3)
			rra(list);
	}
	pb(list);
	ft_sort_three(list);
	pa(list);
}

void	ft_chose_sort(t_list *list, int argc)
{
	if (argc == 3)
		ft_sort_two(list);
	else if (argc == 4)
		ft_sort_three(list);
	else if (argc == 5)
		ft_sort_four(list);
	else if (argc == 6)
		ft_sort_five(list);
	free(list->b);
	free(list->a);
	free(list);
	exit(0);
}
