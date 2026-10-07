/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 21:08:04 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/07 04:17:21 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_defleft(char *spec)
{
	int	i;

	i = 1;
	while (!(spec[i] >= '0' && spec[i] <= '9') && (!ft_isspecifier(spec[i])))
	{
		if (spec[i] == '-')
			return (1);
		i++;
	}
	return (-1);
}

void	ft_process_char(char c, char **line, char *spec)
{
	flags	rules;
	int		len;
	int		i;

	if (ft_defleft(spec) != -1)
		rules.left = 1;
	else
		rules.left = 0;

	rules.sp_size = ft_atoi(spec);
	len = 0;
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


