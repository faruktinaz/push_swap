/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:39:33 by ogenc             #+#    #+#             */
/*   Updated: 2023/05/20 22:57:59 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./get_next_line/get_next_line.h"
#include"../library/libft/libft.h"
#include"../library/printf/ft_printf.h"
#include"checker.h"
#include<stdio.h>
#include<unistd.h>

void	free_exit_l(t_list *list)
{
	free(list);
	ft_exit_e();
}

int	is_duplicated(t_list *list)
{
	int	i;
	int	index;
	int	count;

	i = 0;
	while (i < list->a_len)
	{
		index = 0;
		count = 0;
		while (index < list->a_len)
		{
			if (list->a[i] == list->a[index])
				count++;
			index++;
		}
		if (count > 1)
		{
			free(list->a);
			free(list->b);
			free(list);
			ft_exit_e();
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_list *list)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	while (i < list->a_len - 1)
	{
		if (list->a[i] > list->a[i + 1])
		{
			result = 0;
			break ;
		}
		i++;
	}
	return (result);
}

void	ft_exit_free_all(t_list *list, char c)
{
	free(list->a);
	free(list->b);
	free(list);
	if (c == 'o')
		ft_printf("OK\n");
	else if (c == 'k')
		ft_printf("KO\n");
	else if (c == 'e')
		write(2, "Error\n", 6);
	exit(0);
}

int	main(int argc, char **argv)
{
	t_list	*list;
	char	*str;

	if (argc >= 2)
	{
		list = malloc(sizeof(t_list));
		argc = ft_take_args(list, argv, argc);
		is_duplicated(list);
		while (1)
		{
			str = get_next_line(0);
			ft_check_rules(list, str);
			free(str);
		}
	}
	else
		return (0);
}
