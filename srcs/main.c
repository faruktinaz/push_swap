/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:44:00 by ogenc             #+#    #+#             */
/*   Updated: 2023/05/17 03:53:59 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	fstart_2(t_list *list)
{
	int	index;
	int	take;

	index = 0;
	take = 0;
	while (index < list->b_len)
	{
		while (list->a[list->chepest_index] - list->b[take] <= 0)
			take++;
		if (list->a[list->chepest_index] - list->b[take] > \
			list->a[list->chepest_index] - list->b[index] && \
				list->a[list->chepest_index] - list->b[index] > 0)
			take = index;
		index++;
	}
	while (take > 0 || list->chepest_index != 0)
	{
		list->boole1 = 1;
		list->boole2 = 1;
		take = fstart_rrr(list, take);
		take = fstart_rr(list, take);
	}
}

void	fstart(t_list *list)
{
	if (list->a[list->chepest_index] < list->b[list->b_min_i])
	{
		while (list->chepest_index != 0 || list->b_max_i != 0)
		{
			fstart_min1(list);
			fstart_min2(list);
			fstart_min3(list);
		}
		pb(list);
	}
	else
	{
		fstart_2(list);
		pb(list);
	}
}

void	set_a_b(t_list *list, int argc)
{
	list->a = malloc(sizeof(int) * argc + 1);
	list->b = malloc(sizeof(int) * argc + 1);
}

int	ft_take_args(t_list *list, char **av, int ac)
{
	int		i;
	char	*str;
	char	**split;

	check_args(list, av, ac);
	str = ft_strdup("");
	str[0] = '\0';
	list->a_len = 0;
	i = 0;
	while (ac - 1 > i)
	{
		str = ft_strjoin(str, av[i + 1]);
		str = ft_strjoin(str, " ");
		i++;
	}
	set_a_b(list, ft_wordcounter(av, ' '));
	split = ft_split(str, ' ');
	i = ft_take_split(list, split);
	free(str);
	ft_free_split(split);
	return (i + 1);
}

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc >= 2)
	{
		list = malloc (sizeof(t_list));
		list->a_len = 0;
		list->b_len = 0;
		argc = ft_take_args(list, argv, argc);
		is_duplicated(list);
		if (is_sorted(list))
		{
			free(list->a);
			free(list->b);
			free(list);
			return (0);
		}
		if (argc <= 6)
			ft_chose_sort(list, argc);
		else
			fsort(list);
	}
	else
		return (0);
}
