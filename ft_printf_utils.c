/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 01:48:22 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/15 17:07:54 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_strjoin_2(char **line, char *s2)
{
	char	*res;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(*line) + ft_strlen(s2);
	res = malloc(sizeof(char) * (size + 1));
	i = 0;
	j = 0;
	while ((*line)[i])
	{
		res[i] = (*line)[i];
		i++;
	}
	while (s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	res[i] = '\0';
	*line = res;
	res = NULL;
}

void	ft_strjoin_3(char **line, char c)
{
	char	*res;
	int		size;
	int		i;
	int		j;

	if (*line)
		size = ft_strlen(*line) + 1;
	else
		size = 1;
	res = (char *)malloc(sizeof(char) * size + 1);
	i = 0;
	if (*line != NULL)
	{
		while ((*line)[i])
		{
			res[i] = (*line)[i];
			i++;
		}
	}
	res[i] = c;
	i++;
	res[i] = '\0';
	*line = res;
}

void	ft_strjoin(char **line, char *s2, char c)
{
	if (s2 != NULL)
	{
		if (!*line)
		{
			*line = ft_strdup(s2);
			return ;
		}
		ft_strjoin_2(line, s2);
	}
	else
		ft_strjoin_3(line, c);
}

char	*ft_substr(char *s)
{
	char	*res;
	int		len;
	int		i;

	len = 1;
	while (!ft_isspecifier(s[len]))
		len++;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
