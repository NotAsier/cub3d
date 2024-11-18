/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 10:26:45 by aarranz-          #+#    #+#             */
/*   Updated: 2024/03/26 13:55:36 by aarranz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

//get_next_line.c
char	*ft_read(char *s, int fd);
char	*change_the_static(char *s);
char	*get_line(char *res);
char	*get_next_line(int fd);

//get_next_line_utils.c
char	*gnl_strchr(char *s, int c);
size_t	gnl_strlen(const char *s);
char	*gnl_strjoin(char *s1, char *s2);
#endif // GET_NEXT_LINE_H
