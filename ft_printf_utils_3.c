/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/12 22:45:07 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/16 06:03:35 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_def_left(char *spec)
{
	int	i;

	i = 1;
	while (!(spec[i] > '0' && spec[i] <= '9') && (!ft_isspecifier(spec[i])))
	{
		if (spec[i] == '-')
			return (1);
		i++;
	}
	return (-1);
}

int	ft_defsign(char *str, int n)
{
	int	i;

	i = 0;
	if (n < 0)
		return (1);
	while (str[i] && !(str[i] > '0' && str[i] <= '9') && str[i] != '.')
	{
		if (str[i] == '+')
			return (1);
		i++;
	}
	return (-1);
}

int	ft_defzeropad(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '.')
	{
		if (s[i] == '0')
			return (1);
		i++;
	}
	return (0);
}

int	isflag(char c)
{
	if (c == ' ' || c == '+' || c == '0' || c == '-' || c == '#')
		return (1);
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_parser_1(t_flags *rules, char *spec, int *i)
{
	while (isflag(spec[*i]))
	{
		if (spec[*i] > '0' && spec[*i] <= '9')
			break ;
		if (spec[*i] == '-')
			rules->left = 1;
		else if (spec[*i] == '+')
			rules->sign = 1;
		else if (spec[*i] == ' ')
			rules->space = 1;
		else if (spec[*i] == '#')
			rules->hash = 1;
		else if (spec[*i] == '0')
			rules->zero_pad = 1;
		else if (spec[*i] == ' ')
			rules->space = 1;
		(*i)++;
	}
}

void	ft_parser_2(t_flags *rules, char *spec, int *i)
{
	while (ft_isdigit(spec[*i]))
	{
		if (spec[*i] >= '0' && spec[*i] <= '9')
			rules->sp_size = ft_atoi(&spec[*i]);
		while (spec[*i] >= '0' && spec[*i] <= '9')
			(*i)++;
		if (!ft_isdigit(spec[*i]))
			break ;
	}
}

void	ft_parser_3(t_flags *rules, char *spec, int *i)
{
	rules->zero_pad = -1;
	(*i)++;
	while (ft_isdigit(spec[*i]))
	{
		if (spec[*i] >= '0' && spec[*i] <= '9')
			rules->precision = ft_atoi(&spec[*i]);
		while (spec[*i] >= '0' && spec[*i] <= '9')
			(*i)++;
		if (ft_isspecifier(spec[*i]))
			break ;
	}
}

void	ft_parser(t_flags *rules, char *spec)
{
	int	i;

	i = 1;
	ft_parser_1(rules, spec, &i);
	ft_parser_2(rules, spec, &i);
	if (spec[i] == '.')
		ft_parser_3(rules, spec, &i);
	if (rules->left != -1)
		rules->zero_pad = -1;
	if (rules->sign == 1)
		rules->space = -1;
	if (rules->precision != -1)
		rules->zero_pad = -1;
}
