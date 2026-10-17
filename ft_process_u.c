/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 01:06:26 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/17 04:49:40 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_u(unsigned int n, char **line, char *spec)
{
	t_flags	*rules;
	t_flags	node;

	rules = &node;
	rules->left = -1;
	rules->sp_size = -1;
	rules->zero_pad = -1;
	rules->precision = -1;
	rules->hash = -1;
	*line = ft_utoa(n);
	if ((*line)[0] == '0')
		*line = ft_strdup("");
	ft_parser(rules, spec);
	rules->sign = -1;
	rules->space = -1;
	if (n < 0)
	{
		rules->sign = 1;
		rules->space = -1;
	}
	ft_make_precision(line, rules->precision);
	ft_make_id_line(line, rules, n);
}
