/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 00:50:54 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/17 03:51:44 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_fill(char hex[], unsigned long n, char **line)
{
	int				i;
	int				j;
	char			buffer[32];
	char			temp[32];

	if (n == 0)
	{
		*line = ft_strdup("0");
		return ;
	}
	i = 0;
	while (n > 0)
	{
		temp[i++] = hex[n % 16];
		n /= 16;
	}
	j = 0;
	while (i > 0)
	{
		buffer[j++] = temp[--i];
	}
	buffer[j] = '\0';
	*line = ft_strdup(buffer);
}

static void	ft_def_rules(t_flags *rules)
{
	rules->left = -1;
	rules->sp_size = -1;
	rules->sign = -1;
	rules->zero_pad = -1;
	rules->precision = -1;
	rules->hash = -1;
	rules->space = -1;
}

void	ft_process_p_1(void *ptr, char **line, t_flags *rules)
{
	char			*hex;
	unsigned long	n;

	hex = "0123456789abcdef";
	n = (unsigned long)ptr;
	if (ptr == NULL)
	{
		rules->hash = -1;
		rules->zero_pad = -1;
	}
	if (rules->sign != -1)
		rules->sign = 0;
	if (ptr != NULL)
		ft_fill(hex, n, line);
	ft_make_precision(line, rules->precision);
	ft_make_id_line(line, rules, n);
	if (ptr != NULL)
		ft_add_hash(line, 1, rules);
}

void	ft_process_p(void *ptr, char **line, char *spec)
{
	char				buffer[32];
	int					res;
	t_flags				*rules;
	t_flags				node;

	if (ptr == NULL)
		*line = ft_strdup("(nil)");
	rules = &node;
	ft_def_rules(rules);
	ft_parser(rules, spec);
	rules->hash = 1;
	ft_process_p_1(ptr, line, rules);
	if (rules->sign == 0)
		ft_add_sign(line, 1, rules);
}
