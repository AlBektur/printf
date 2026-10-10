/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 01:43:44 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/10 14:36:10 by besaipid         ###   ########.fr       */
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

int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

void	ft_process_id(int n, char **line, char *spec)
{
	t_flags	rules = {-1, -1, -1, -1, -1, -1, -1};
	*line = ft_itoa(n);
	int	i;

	i = 1;
	while (isflag(spec[i]))
	{
		if (spec[i] > '0' && spec[i] <= '9')
			break ;
		if (spec[i] == '-')
			rules.left = 1;
		else if(spec[i] == '+')
			rules.sign = 1;
		else if (spec[i] == ' ')
			rules.space = 1;
		else if (spec[i] == '#')
			rules.hash = 1;
		else if(spec[i] == '0')
			rules.zero_pad = 1;
		else if (spec[i] == ' ')
			rules.space = 1;;
		i++;
	}

	// this is sp_size
	while (ft_isdigit(spec[i]))
	{
		if (spec[i] >= '0' && spec[i] <= '9')
			rules.sp_size = ft_atoi(&spec[i]);
		while (spec[i] >= '0' && spec[i] <= '9')
			i++;
		if (!ft_isdigit(spec[i]))
			break ;
	}

	// this is precision
	if (spec[i] == '.')
	{
		i++;
		while (ft_isdigit(spec[i]))
		{
			if (spec[i] > '0' && spec[i] <= '9')
				rules.precision = ft_atoi(&spec[i]);
			while (spec[i] >= '0' && spec[i] <= '9')
				i++;
			if (ft_isspecifier(spec[i]))
				break;
		}
	}

	if (rules.left != -1)
		rules.zero_pad = -1;
	if (rules.space != -1 && rules.sign)
		rules.space = -1;
	if (rules.sign)
		rules.space = -1;
	if (rules.precision != -1)
		rules.zero_pad = -1;
	if (n < 0)
		rules.sign = 1;


	printf("sign: %d\n", rules.sign);
	printf("left %d\n", rules.left);
	printf("sp_size: %d\n", rules.sp_size);
	printf("precision: %d\n", rules.precision);
	printf("zeropad: %d\n", rules.zero_pad);
	printf("space: %d\n", rules.space);

	printf("\n\nraw n: \"%s\"\n",  *line);

	ft_make_precision(line, rules.precision);

	printf("after precision: \"%s\"\n",  *line);

	// // this always if has recision
	// if (rules.sign != -1)
	// 	ft_add_sign(line, n);



	ft_make_id_line(line, rules, n);

	printf("after make_id_line: \"%s\"\n",  *line);

	printf("sizeof total line to print %d\n", ft_strlen(*line));

}
