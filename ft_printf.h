/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 02:06:01 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/17 04:40:15 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_flags
{
	int	left;
	int	sp_size;
	int	sign;
	int	zero_pad;
	int	precision;
	int	hash;
	int	space;
}	t_flags;

int		ft_printf(const char *format, ...);
void	ft_join(char c, char **line);
int		ft_isspecifier(char c);
char	*ft_substr(char *s);

int		ft_def_width(char *spec);
int		ft_atoi(char *nptr);
int		ft_defleft(char *spec);
int		ft_strlen(char *s);
int		ft_def_precision(char *s);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
int		ft_isdigit(char c);
char	*ft_strdup(const char *s);
void	ft_strjoin(char **line, char *s2, char c);

void	ft_parser(t_flags *rules, char *spec);
void	ft_make_precision(char **nb, int precision);
void	ft_make_id_line(char **nb, t_flags *rules, int n);
void	ft_add_sign(char **nb, int n, t_flags *rules);
void	ft_add_hash(char **line, int lowercase, t_flags *rules);

void	ft_process_char(char c, char **line, char *spec);
void	ft_process_str(char *str, char **line, char *spec);
void	ft_process_id(int n, char **line, char *spec);
void	ft_process_u(unsigned int n, char **line, char *spec);
void	ft_process_x(unsigned int nb, int lowercase, char **line, char *spec);
void	ft_process_p(void *ptr, char **line, char *spec);
#endif
