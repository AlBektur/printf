/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 03:21:33 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/17 05:31:11 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	alpha(int c)
{
	return (((c >= 65 && c <= 90) || (c >= 97 && c <= 122)));
}

static int	digit(int c)
{
	return ((c >= '0' && c <= '9'));
}

int	ft_isalnum(int c)
{
	return ((alpha(c)) || (digit(c)));
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

void	ft_add_hash_2(int *i, int *j, char *temp, char **nb)
{
	while ((*nb)[*j])
	{
		temp[*i] = (*nb)[*j];
		(*i)++;
		(*j)++;
	}
	temp[*i] = '\0';
	free(*nb);
	*nb = temp;
	temp = NULL;
}

void	ft_add_hash_1(char **nb, char *temp, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*nb)[i])
	{
		if (ft_isalnum((*nb)[i]) == 1 || (*nb)[i] != ' ')
			break ;
		temp[i] = (*nb)[i];
		i++;
	}
	j = i;
	temp[i] = '0';
	i++;
	temp[i] = c;
	i++;
	ft_add_hash_2(&i, &j, temp, nb);
}

void	ft_add_hash(char **nb, int capital, t_flags *rules)
{
	int		len;
	char	c;
	char	*temp;

	if (capital)
		c = 'x';
	else
		c = 'X';
	len = ft_strlen(*nb);
	if (rules->sp_size < len)
		len += 2;
	else
		len = rules->sp_size - 2;
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		*nb = NULL;
	ft_add_hash_1(nb, temp, c);
}

static void	ft_filler(char hex[], unsigned int n, char **line)
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

void	ft_process_x(unsigned int nb, int lowercase, char **line, char *spec)
{
	char		*cap_chars;
	char		*low_chars;
	t_flags		*rules;
	t_flags		node;

	rules = &node;
	ft_def_rules(rules);
	ft_parser(rules, spec);
	if (rules->sign != -1)
		rules->sign = -1;
	if (rules->space != -1)
		rules->space = -1;
	cap_chars = "0123456789ABCDEF";
	low_chars = "0123456789abcdef";
	if (lowercase == 1)
		ft_filler(low_chars, nb, line);
	else if (lowercase == 0)
		ft_filler(cap_chars, nb, line);
	ft_make_precision(line, rules->precision);
	ft_make_id_line(line, rules, nb);
	if (rules->hash != -1 && nb != 0)
		ft_add_hash(line, lowercase, rules);
}
