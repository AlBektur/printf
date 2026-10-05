/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 00:18:33 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/05 05:12:39 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_defleft(char *spec)
{
	int	i;

	i = 0;
	while (!(spec[i] >= '0' && spec[i] <= '9'))
	{
		if (spec[i] == '-')
			return (i);
		i++;
	}
	return (0);
}

void	ft_process_char(char c, char **line, char *spec)
{
	flags	rules;
	int		len;
	int		i;

	if (ft_defleft(spec))
		rules.left = 1;
	else
		rules.left = 0;
	ft_defleft(spec);
	rules.sp_size = ft_atoi(spec);
	len = 1;
	len += rules.sp_size;
	*line = (char *)malloc(sizeof(char) * (len + 1)); // needs to be added protector

	i = 0;
	if (rules.left)
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

void	ft_process_str(char *str, char **line, char *spec);
