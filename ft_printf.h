/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 02:06:01 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/09 04:39:45 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	left;
	int	sp_size;
	int sign;
	int	zero_pad;
	int	precision;
	int	hash;
	int	space;
} t_flags;

int		ft_printf(const char *format, ...);
void	ft_join(char c, char **line);
int		ft_isspecifier(char c);
char	*ft_substr(char *s);

int		ft_def_width(char *spec);
int	ft_atoi(char *nptr);
int	ft_defleft(char *spec);
int	ft_strlen(char *s);
int	ft_def_precision(char *s);
char	*ft_itoa(int n);
void	ft_make_precision(char **nb, int precision, int sign, int n);

void	ft_process_char(char c, char **line, char *spec);
void	ft_process_str(char *str, char **line, char *spec);
void	ft_process_id(int n, char **line, char *spec);
#endif
