/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:22:55 by ogenc             #+#    #+#             */
/*   Updated: 2023/05/09 22:44:42 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int	*a;
	int	*b;
	int	*steps;
	char	*str;
	int	a_len;
	int	b_max_i;
	int	b_min_i;
	int	chepest_index;
	int	b_in;
	int	a_in;
	int	b_len;
}		t_list;

void	move_up(t_list *list, char c);
void	move_down(t_list *list, char c);
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

#endif