/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 01:43:44 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/09 05:51:00 by besaipid         ###   ########.fr       */
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
	// char	*nb;
	// flags	rules;
	// int		nb_size;


	// nb = ft_itoa(n);



	// nb_size = ft_strlen(nb);
	// rules.sp_size = ft_atoi(spec);

	// rules.sign = ft_defsign(spec, n);

	// rules.precision = ft_def_precision(spec);

	// rules.zero_pad = ft_defzeropad(spec);
	// rules.left = ft_def_left(spec);

	// if (rules.left == 1 || rules.precision >= 0)
	// 	rules.zero_pad = 0;


	// printf("raw nb: \"%s\"\n\n", nb);
	// printf("sign: %d\n", rules.sign);
	// printf("left %d\n", rules.left);
	// printf("sp_size: %d\n", rules.sp_size);
	// printf("precision: %d\n", rules.precision);
	// printf("zeropad: %d\n", rules.zero_pad);
	// printf("nb size: %d\n", nb_size);


	// first i have to make a line according to precision, if nb_size < rules.precision, shoud be added 00.
	// else, nb stays as it was.

	// it adds + - signs if needed.
	// if (rules.precision != -1 && rules.precision > nb_size)
	// 	ft_make_precision(&nb, rules.precision, rules.sign, n);
	// printf("after correcting by precision: %s\n", nb);

	// make precision needs put sign to number if the format has precision point.

	/*everything with thinking if it is aligned or no.*/


	// then i have to check the sp_size, if sp_size > nb_size i have to add zeros if rules.zero_pad activated.
	// else fill it with spaces.


    ///"%.6d" "42"
	//here i should check if rules.sign activated, if it is the sign should be added.



	//printf("%s", res);




	t_flags	rules = {-1, -1, -1, -1, -1, -1, -1};
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


	printf("sign: %d\n", rules.sign);
	printf("left %d\n", rules.left);
	printf("sp_size: %d\n", rules.sp_size);
	printf("precision: %d\n", rules.precision);
	printf("zeropad: %d\n", rules.zero_pad);
//	printf("nb size: %d\n", nb_size);

}
