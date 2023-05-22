/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:16:02 by ogenc             #+#    #+#             */
/*   Updated: 2023/01/31 13:42:54 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

size_t	ft_strlen_g(char *str);
char	*ft_strjoin_g(char *s1, char *s2);
int		ft_checknewline(char *buffer);
char	*ft_newline(char *buffer);
char	*new_buffer(char *buffer);
char	*read_line(int fd, char *buffer);
char	*get_next_line(int fd);
#endif
