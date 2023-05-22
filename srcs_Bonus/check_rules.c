/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rules.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:39:30 by ogenc             #+#    #+#             */
/*   Updated: 2023/05/20 23:14:15 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

void	ft_check_rules_2(t_list *list, char *str)
{
	if (!ft_strncmp("rra", str, 3) && str)
		rra(list);
	else if (!ft_strncmp("rrb", str, 3) && str)
		rrb(list);
	else if (!ft_strncmp("rrr", str, 3) && str)
		rrr(list);
	else if (!ft_strncmp("ra", str, 2) && str)
		ra(list);
	else if (!ft_strncmp("rb", str, 2) && str)
		rb(list);
	else if (!ft_strncmp("rr", str, 2) && str)
		rr(list);
	else if (str)
		ft_exit_free_all(list, 'e');
}

void	ft_check_rules(t_list *list, char *str)
{
	if (str == NULL && !(is_sorted(list)))
		ft_exit_free_all(list, 'k');
	if (!str && is_sorted(list) && list->b_len == 0)
		ft_exit_free_all(list, 'o');
	if (!str && list->b_len > 0)
		ft_exit_free_all(list, 'k');
	if (!(ft_strncmp("sa", str, 2)) && str)
		sa(list);
	else if (!ft_strncmp("sb", str, 2) && str)
		sb(list);
	else if (!ft_strncmp("ss", str, 2) && str)
		ss(list);
	else if (!ft_strncmp("pa", str, 2) && str)
		pa(list);
	else if (!ft_strncmp("pb", str, 2) && str)
		pb(list);
	else
		ft_check_rules_2(list, str);
}

void	ft_exit(char *message)
{
	ft_printf("%s\n", message);
	exit(1);
}
