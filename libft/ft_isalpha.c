/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:40:11 by ogenc             #+#    #+#             */
/*   Updated: 2022/12/09 22:45:21 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int str)
{
	if (str >= 'a' && str <= 'z')
		return (1);
	else if (str >= 'A' && str <= 'Z')
		return (1);
	else
		return (0);
}