/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 21:08:04 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/16 02:54:31 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_make_c_line(t_flags *rules, char **line, char c, int len)
{
	int		i;

	i = 0;
	if (rules->left != -1)
	{
		(*line)[i] = c;
		i++;
		while (i < len)
		{
			(*line)[i] = ' ';
			i++;
		}
		(*line)[len] = '\0';
	}
	else
	{
		while (i < (len - 1))
		{
			(*line)[i] = ' ';
			i++;
		}
		(*line)[i] = c;
		(*line)[++i] = '\0';
	}
}

void	ft_process_char(char c, char **line, char *spec)
{
	t_flags	*rules;
	t_flags	node;
	int		len;

	rules = &node;
	rules->left = -1;
	rules->sp_size = -1;
	rules->precision = -1;
	ft_parser(rules, spec);
	rules->sign = -1;
	rules->zero_pad = -1;
	rules->hash = -1;
	rules->space = -1;
	len = 0;
	len += rules->sp_size;
	*line = (char *)malloc(sizeof(char) * (len + 1));
	if (*line == NULL)
		return ;
	ft_make_c_line(rules, line, c, len);
}
