/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shimakaori <shimakaori@student.42tokyo.jp> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 12:53:46 by shimakaori        #+#    #+#             */
/*   Updated: 2022/08/14 12:21:03 by shimakaori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdlib.h>
# include <ctype.h>
# include <limits.h>
# include <string.h>
# include <unistd.h>
# include <errno.h>
# include <stdarg.h>
# include <stdint.h>
# include "libft.h"

# define ERROR -1

int	ft_printf(const char *format, ...);
int	ft_printchar(int c);
int	ft_printstr(char *s);
int	ft_printnbr(int n);
int	ft_printnbr_unsigned(unsigned int n);
int	ft_printhex(unsigned int n, int format);
int	ft_printaddr(unsigned long long point);

#endif