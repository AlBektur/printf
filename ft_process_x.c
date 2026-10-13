/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 03:21:33 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/13 05:19:19 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_add_hash(char **nb, int capital)
{
	int		len;
	char	c;
	int		i;
	char	*temp;
	int		j;

	if (capital)
		capital = 'X';
	else
		capital = 'x';

	len = ft_strlen(*nb) + 2;

	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		*nb = NULL;

	i = 0;
	j = 0;
	while ((*nb)[i])
	{
		if (ft_isdigit((*nb)[i]) == 1 || (*nb)[i] != ' ')
			break ;
		temp[i] = (*nb)[i];
		i++;
	}
	j = i;
	temp[i++] = '0';
	temp[i++] = c;
	while((*nb)[j])
	{
		temp[i] = (*nb)[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	free(*nb);
	*nb = temp;
	temp = NULL;
}

static void	ft_filler(char hex[], unsigned int n, char **line, int hash, int capital)
{
	int				i;
	int				j;
	char			buffer[32];
	char			temp[8];

	// if (n == 0)
	// 	return (ft_putchar('0'));
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

	//this should be finished
	// if (hash)
	// 	ft_add_hash(line, capital);
}

void	ft_process_x(unsigned int nb, int lowercase, char **line, char *spec)
{
	char	*cap_chars;
	char	*low_chars;

	t_flags	*rules;
	t_flags	node;

	rules = &node;
	rules->left = -1;
	rules->sp_size = -1;
	rules->sign = -1;
	rules->zero_pad = -1;
	rules->precision = -1;
	rules->hash = -1;
	rules->space = -1;

	ft_parser(rules, spec);

	if (rules->sign != -1)
		rules->sign = -1;
	if (rules->space != -1)
		rules->space = -1;


	cap_chars = "0123456789ABCDEF";
	low_chars = "0123456789abcdef";
	if (lowercase)
		ft_filler(low_chars, nb, line, rules->hash, lowercase);
	else
		ft_filler(cap_chars, nb, line, rules->hash, lowercase);

	ft_make_precision(line, rules->precision);
	ft_make_id_line(line, rules, nb);
	printf("%s\n", *line);
}
