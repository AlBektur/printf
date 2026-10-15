/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 21:09:14 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/15 05:15:54 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_process_str(char *str, char **line, char *spec)
{
	int		len;
	int		i;
	int		str_size;
	int		j;

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
	str_size = ft_strlen(str);

	if (rules->precision >= 0 && str_size > rules->precision)
    	str_size = rules->precision;

	if (rules->sp_size > str_size)
    	len = rules->sp_size;
	else
    	len = str_size;

	*line = malloc(sizeof(char) * (len + 1));

	i = 0;


	if (rules->left != -1)
	{
		while (i < str_size)
		{
			(*line)[i] = str[i];
			i++;
		}
		while (i < len)
		{
			(*line)[i] = ' ';
			i++;
		}
		(*line)[i] = '\0';
	}
	else
	{
		j = 0;
		while (i < (len - str_size))
		{
			(*line)[i] = ' ';
			i++;
		}
		while (i < len)
		{
			(*line)[i] = str[j];
			j++;
			i++;
		}
		(*line)[i] = '\0';
	}
}
