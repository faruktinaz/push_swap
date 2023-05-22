/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:44:03 by ogenc             #+#    #+#             */
/*   Updated: 2023/05/11 11:44:04 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	rra(t_list *list)
{
	int	temp;

	if (list->a_len != 0)
	{
		temp = list->a[list->a_len - 1];
		ft_up(list, 'a');
		list->a[0] = temp;
		ft_printf("rra\n");
	}
}

void	rrb(t_list *list)
{
	int	temp;

	if (list->b_len != 0)
	{
		temp = list->b[list->b_len - 1];
		ft_up(list, 'b');
		list->b[0] = temp;
		ft_printf("rrb\n");
	}
}

void	rrr(t_list *list)
{
	int	temp;

	if (list->a_len != 0)
	{
		temp = list->a[list->a_len - 1];
		ft_up(list, 'a');
		list->a[0] = temp;
	}
	if (list->b_len != 0)
	{
		temp = list->b[list->b_len - 1];
		ft_up(list, 'b');
		list->b[0] = temp;
	}
	ft_printf("rrr\n");
}
