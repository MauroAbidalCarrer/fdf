/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maabidal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 18:27:44 by maabidal          #+#    #+#             */
/*   Updated: 2022/02/13 00:00:39 by maabidal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_UTILS_H
# define MY_UTILS_H

# include<unistd.h>
# include<limits.h>
# include<stdlib.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

//gnl
char	*r_join(char *s1, char *s2, size_t len);
void	*free_prev(char **prev_add);
char	*join(char *s1, char *s2);
char	*alloc_line(size_t len);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
size_t	n_index(char *str);

//split
char	**ft_split(char const *s, char c);

double	ft_atof(const char *nptr);
#endif
