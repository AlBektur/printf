/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 02:06:01 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/07 03:51:11 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct
{
	int	width;
	int	left;
	int	sp_size;
	int sign;
	int	zero_pad;
	int	precision;
} flags;

int		ft_printf(const char *format, ...);
void	ft_join(char c, char **line);
int		ft_isspecifier(char c);
char	*ft_substr(char *s);

int		ft_def_width(char *spec);
int	ft_atoi(char *nptr);
int	ft_defleft(char *spec);
int	ft_strlen(char *s);
int	ft_def_precision(char *s);

void	ft_process_char(char c, char **line, char *spec);
void	ft_process_str(char *str, char **line, char *spec);
void	ft_process_id(int n, char **line, char *spec);
#endif
