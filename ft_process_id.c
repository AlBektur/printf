/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 01:43:44 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/14 04:33:05 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void	ft_process_id(int n, char **line, char *spec)
{
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

	*line = ft_itoa(n);
	if ((*line)[0] == '0')
		*line = ft_strdup("");
	ft_parser(rules, spec);
	if (n < 0)
	{
		rules->sign = 1;
		rules->space = -1;
	}

	// if (rules->precision == -1 && n == 0)
	// 	return ;
	ft_make_precision(line, rules->precision);
	ft_make_id_line(line, rules, n);
	printf("%s",  *line);
}
