/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:53:13 by shimakaori        #+#    #+#             */
/*   Updated: 2022/11/09 12:07:18 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# ifndef FD_MAX
#  define FD_MAX	256
# endif	

# ifndef BUF_MAX
#  define BUF_MAX	INT_MAX
# endif	

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	10000
# endif	

char		*get_next_line(int fd);
size_t		gnl_strlen(const char *str);
char		*gnl_strchr(const char *s, int c);
char		*gnl_calloc(size_t num, size_t size);
char		*gnl_strdup(const char *s);
char		*gnl_strjoin(char *s1, char *s2);

#endif