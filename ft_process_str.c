/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 21:09:14 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/17 05:08:27 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_make_str_line_2(char **line, char *str, int str_size, int len)
{
	int	i;
	int	j;

	i = 0;
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

void	ft_make_str_line(char **line, char *str, int str_size, int len)
{
	int	i;

	i = 0;
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

void	ft_process_str(char *str, char **line, char *spec)
{
	int		len;
	int		str_size;
	t_flags	*rules;
	t_flags	node;

	if (str == NULL)
	{
		*line = ft_strdup("(null)");
		return ;
	}
	if (ft_strlen(str) == 0)
	{
		*line = ft_strdup("");
		return ;
	}

	rules = &node;
	ft_def_rules(rules);
	ft_parser(rules, spec);
	str_size = ft_strlen(str);
	if (rules->precision != -1 && str_size > rules->precision)
		str_size = rules->precision;
	if (rules->sp_size > str_size)
		len = rules->sp_size;
	else
		len = str_size;
	*line = malloc(sizeof(char) * (len + 1));
	if ((*line) == NULL)
		return ;
	if (rules->left != -1)
		ft_make_str_line(line, str, str_size, len);
	else
		ft_make_str_line_2(line, str, str_size, len);
}
