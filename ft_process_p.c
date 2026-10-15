/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/14 00:50:54 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/15 05:40:17 by besaipid         ###   ########.fr       */
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


void	ft_process_p(void *ptr, char **line, char *spec)
{
	int					counter;
	unsigned long		n;
	char				buffer[32];
	int					res;
	char				*hex;

	if (ptr == NULL)
		*line = ft_strdup("(nil)");
	n = (unsigned long)ptr;
	hex = "0123456789abcdef";


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

	rules->hash = 1;
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

	if (rules->sign == 0)
		ft_add_sign(line, 1, rules);
}
