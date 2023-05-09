/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:22:51 by ogenc             #+#    #+#             */
/*   Updated: 2023/05/09 23:20:26 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	bmax(t_list *list)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i < list->b_len)
	{
		if (list->b[index] < list->b[i])
			index = i;
		i++;
	}
	list->b_max_i = index;
}

void	bmin(t_list *list)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i < list->b_len)
	{
		if (list->b[index] > list->b[i])
			index = i;
		i++;
	}
	list->b_min_i = index;
}

void	calculate_steps(t_list *list)
{
	int	i;
	int	index;
	int	take;

	i = 0;
	index = 0;
	take = 0;
	while (i < list->a_len)
	{
		list->steps[i] = i + 1;
		if (list->a[i] > list->b[list->b_max_i])
			list->steps[i] += list->b_max_i;
		else if (list->a[i] < list->b[list->b_min_i])
			list->steps[i] += list->b_max_i;
		else
		{
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
			list->steps[i] += take;
		}
		i++;
	}
}

void	take_chepest(t_list *list)
{
	int	i;
	int	index;

	i = 1;
	index = 0;
	while (i < list->a_len)
	{
		if (list->steps[index] > list->steps[i])
			index = i;
		i++;
	}
	list->chepest_index = index;
}

void	find_chepest(t_list *list)
{
	bmax(list);
	bmin(list);
	calculate_steps(list);
	take_chepest(list);
}

void	fstart(t_list *list)
{
	int	index;
	int	take;

	index = 0;
	take = 0;
	if (list->a[list->chepest_index] < list->b[list->b_min_i])
	{
		while (list->chepest_index != 0)
		{
			if (list->chepest_index != 0)
			{
				ra(list);
				list->chepest_index--;
			}
		}
		while (list->b_max_i != 0)
		{
			rb(list);
			list->b_max_i--;
		}
		pb(list);
	}
	else
	{
		index = 0;
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
			if (take > 0 && list->chepest_index != 0)
			{
				rr(list);
				list->chepest_index--;
				take--;
			}
			else if (list->chepest_index != 0)
			{
				ra(list);
				list->chepest_index--;
			}
			else if (take > 0)
			{
				rb(list);
				take--;
			}
		}
		pb(list);
	}
}

void	fstart2(t_list *list)
{
	bmin(list);
	while (list->b_min_i != list->b_len - 1)
	{
		rrb(list);
		bmin(list);
	}
}

void	fsort(t_list *list)
{
	int	i;

	i = 0;
	list->steps = malloc(sizeof(int) * list->a_len);
	pb(list);
	pb(list);
	if (list->b[0] < list->b[1])
		rb(list);
	while (i < list->a_len)
	{
		find_chepest(list);
		fstart(list);
	}
	fstart2(list);
	while (list->b_len != 0)
		pa(list);
}

void	ft_exit(char *message)
{
	ft_printf("%s\n", message);
	exit(1);
}

void	is_all_num(char **av, int ac)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (ac > i)
	{
		while (av[i][j])
		{
			if (av[i][j] != ' ')
				if (!ft_isdigit(av[i][j]))
					ft_exit("error");
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_args(char **av, int ac)
{
	is_all_num(av, ac);
}

void	ft_set_stacks(t_list *list, char **split, int argc)
{
	int	i;

	i = 0;
	list->a = malloc(sizeof(int) * argc);
	list->b = malloc(sizeof(int) * argc);
	while (split[i])
	{
		list->a[i] = ft_atoi(split[i]);
		list->a_len++;
		i++;
	}
}

int	ft_take_set_args(t_list *list, char **argv, int argc)
{
	int		i;
	char	**split;

	check_args(argv, argc);
	list->str = ft_strdup("");
	list->a_len = 0;
	i = 0;
	while (argc - 1 > i)
	{
		list->str = ft_strjoin(list->str, argv[i + 1]);
		list->str = ft_strjoin(list->str, " ");
		i++;
	}
	split = ft_split(list->str, ' ');
	i = 0;
	while (split[i])
		i++;
	ft_set_stacks(list, split, i);
	return (i);
}

int	main(int argc, char **argv)
{
	t_list	*list;

	if (argc >= 2)
	{
		list = malloc (sizeof(t_list));
		argc = ft_take_set_args(list, argv, argc);
		list->a_len = 0;
		list->b_len = 0;
		system("leaks push_swap");
		fsort(list);
		free(list->a);
		free(list->b);
		free(list->steps);
		free(list);
	}
	else
		ft_exit("Error");
}
