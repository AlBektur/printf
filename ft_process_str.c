/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/05 21:09:14 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/06 05:55:27 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_def_precision(char *s)
{
	int	i;
	int	precision;

	i = 0;
	while (s[i])
	{
		if (s[i] == '.')
			break;
		i++;
	}
	i++;
	precision = ft_atoi(&s[i]);
	// printf("%c\n", s[i]);
	// printf("precision: %d\n", precision);
	return (precision);
}
void	ft_process_str(char *str, char **line, char *spec)
{
	flags	rules;
	int		len;
	int		i;
	int		str_size;
	int		j;

//	printf("the str: %s\n", str);

// definig if it has left aligning

	if (ft_defleft(spec) != -1)
		rules.left = 1;
	else
		rules.left = 0;


	// defing if it must be added space before or after argument
	rules.sp_size = ft_atoi(spec);
	len = 0;
	len += rules.sp_size;



	rules.precision = ft_def_precision(spec);
// definig size, this should be changed acording to precision.

	str_size = ft_strlen(str);


	if (str_size > rules.precision && rules.precision != 0 || str_size < rules.precision)
		str_size = rules.precision;


	if (rules.precision == 0)
		len = 0;
	if (rules.sp_size < str_size)
		len = str_size;
	else if (rules.sp_size == 0 && rules.precision > 0)
		len = rules.precision;
	else
		len = rules.sp_size;

	// printf("str_size %d\n", str_size);
	// printf("sp_size %d\n", rules.sp_size);
	// printf("precision: %d\n", rules.precision);
	// printf("len for malloc for %d\n", len);
	// printf("is aligned left? %d\n", rules.left);



	// needs to be added protector
	*line = malloc(sizeof(char) * (len + 1));

	i = 0;


	if (rules.left)
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
	printf("%s", *line);
//	printf("len %d\n", ft_strlen(*line));
}
