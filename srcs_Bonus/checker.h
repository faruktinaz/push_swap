/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 21:39:36 by ogenc             #+#    #+#             */
/*   Updated: 2023/05/20 22:39:43 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <stdio.h>
# include <unistd.h>
# include "../library/printf/ft_printf.h"
# include "../library/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	int	*a;
	int	*b;
	int	a_len;
	int	boole1;
	int	i;
	int	j;
	int	b_len;
}		t_list;

void	ft_down(t_list *list, char c);
void	ft_up(t_list *list, char c);
void	sa(t_list *list);
void	sb(t_list *list);
void	ss(t_list *list);
void	pa(t_list *list);
void	pb(t_list *list);
void	ra(t_list *list);
void	rb(t_list *list);
void	rr(t_list *list);
void	rra(t_list *list);
void	rrb(t_list *list);
void	rrr(t_list *list);
int		ft_wordcounter(char **str, char c);
int		ft_take_split(t_list *list, char **split);
void	ft_free_split(char **split);
void	check_args(t_list *list, char **av, int ac);
void	set_a_b(t_list *list, int argc);
void	ft_check_errors(t_list *list, size_t result, char c);
int		ft_atoi2(const char *str, t_list *list);
int		ft_take_args(t_list *list, char **av, int ac);
void	ft_check_rules(t_list *list, char *str);
void	ft_check_rules_2(t_list *list, char *str);
void	ft_exit_free_all(t_list *list, char c);
int		is_sorted(t_list *list);
int		is_duplicated(t_list *list);
void	free_exit_l(t_list *list);
void	ft_exit_e(void);
void	ft_exit(char *message);

#endif
