/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsort_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 03:49:32 by ogenc             #+#    #+#             */
/*   Updated: 2023/05/17 10:42:45 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	ft_wordcounter(char **str, char c)
{
	int	i;
	int	wordcount;
	int	index;

	index = 1;
	wordcount = 0;
	while (str[index])
	{
		i = 0;
		while (str[index][i] != '\0' && str[index][i] == c)
			i++;
		while (str[index][i] != '\0')
		{
			while (str[index][i] != '\0' && str[index][i] != c)
				i++;
			wordcount++;
			while (str[index][i] != '\0' && str[index][i] == c)
				i++;
		}
		index++;
	}
	return (wordcount);
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

int	ft_atoi2(char *str, t_list *list)
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

void	ft_free_split(char **split)
{
	int	i;

	if (split)
	{
		i = 0;
		while (split[i])
		{
			free(split[i]);
			i++;
		}
		free(split);
	}
}

int	ft_take_split(t_list *list, char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		list->a[i] = ft_atoi2(split[i], list);
		list->a_len++;
		i++;
	}
	return (i);
}
