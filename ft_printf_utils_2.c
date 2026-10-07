/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 22:29:10 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/07 02:30:50 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_isspace(char c)
{
	if (c == '-' || c == '%' || (c >= 9 && c <= 13) || c == '#' || c == '+'
			|| c == ' ' || c == '0')
		return (1);
	return (0);
}

int	ft_atoi(char *nptr)
{
	int	res;
	int	i;
	int	sign;

	sign = 1;
	res = 0;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	// if (nptr[i] == '+' || nptr[i] == '-')
	// {
	// 	if (nptr[i] == '-')
	// 		sign = -1;
	// 	i++;
	// }
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return (res *= sign);
}
