/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_check_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:40:05 by ogenc             #+#    #+#             */
/*   Updated: 2023/05/20 21:40:06 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"checker.h"

void	check_args(t_list *list, char **av, int ac)
{
	int	x;

	list->i = 0;
	list->j = 0;
	while (ac > ++list->i)
	{
		x = 1;
		if (!av[list->i][list->j])
			free_exit_l(list);
		while (av[list->i][list->j])
		{
			if (av[list->i][list->j] != ' ')
			{
				x = 0;
				if (av[list->i][list->j] == '+' || av[list->i][list->j] == '-')
					list->j++;
				if (!ft_isdigit(av[list->i][list->j]))
					free_exit_l(list);
			}
			list->j++;
		}
		if (x)
			free_exit_l(list);
		list->j = 0;
	}
}

void	set_a_b(t_list *list, int argc)
{
	list->a = malloc(sizeof(int) * argc + 1);
	list->b = malloc(sizeof(int) * argc + 1);
}

void	ft_check_errors(t_list *list, size_t result, char c)
{
	if (c == '+' || c == '-')
	{
		free(list->b);
		free(list->a);
		free_exit_l(list);
	}
	if (!(result <= 2147483647))
	{
		free(list->b);
		free(list->a);
		free_exit_l(list);
	}
}

int	ft_atoi2(const char *str, t_list *list)
{
	int		i;
	int		sign;
	size_t	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		result = result * 10;
		result += (str[i] - 48);
		i++;
	}
	ft_check_errors(list, result, str[i]);
	return (result * sign);
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
	i = 0;
	split = ft_split(str, ' ');
	i = ft_take_split(list, split);
	free(str);
	ft_free_split(split);
	return (i + 1);
}
