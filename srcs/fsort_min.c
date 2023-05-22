/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsort_min.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 02:33:47 by ogenc             #+#    #+#             */
/*   Updated: 2023/05/17 03:52:10 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	fstart_min1(t_list *list)
{
	list->boole1 = 1;
	list->boole2 = 1;
	if (list->chepest_index == list->a_len - 1 && \
		list->b_max_i == list->b_len - 1 && list->a_len > 1)
	{
		rrr(list);
		list->chepest_index = 0;
		list->b_max_i = 0;
	}
	else if (list->chepest_index == list->a_len - 1 && list->a_len > 1)
	{
		rra(list);
		list->chepest_index = 0;
	}
	else if (list->b_max_i == list->b_len - 1 && list->b_len > 1)
	{
		rrb(list);
		list->b_max_i = 0;
	}
}

void	fstart_min2(t_list *list)
{
	if (list->b_max_i > 0 && list->chepest_index != 0 && \
	(list->chepest_index <= list->a_len / 2 && \
		list->b_max_i <= list->b_len / 2))
	{
		rr(list);
		list->boole2 = 0;
		list->chepest_index--;
		list->b_max_i--;
	}
	else if (list->b_max_i > 0 && list->chepest_index != 0 && \
		(list->chepest_index > list->a_len / 2 && \
			list->b_max_i > list->b_len / 2))
	{
		rrr(list);
		list->chepest_index++;
		list->b_max_i++;
		list->boole1 = 0;
	}
}

void	fstart_min3(t_list *list)
{
	if (list->chepest_index != 0 && \
		list->chepest_index <= list->a_len / 2 && list->boole2)
	{
		ra(list);
		list->chepest_index--;
	}
	else if (list->chepest_index != 0 && (list->a_len > 1 && \
		list->chepest_index > list->a_len / 2) && list->boole1)
	{
		rra(list);
		list->chepest_index++;
	}
	if (list->b_max_i > 0 && list->b_max_i <= list->b_len / 2 && list->boole2)
	{
		rb(list);
		list->b_max_i--;
	}
	else if (list->b_max_i > 0 && \
		list->b_max_i > list->b_len / 2 && list->boole1)
	{
		rrb(list);
		list->b_max_i++;
	}
}
