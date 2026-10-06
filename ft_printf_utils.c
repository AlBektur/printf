/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 01:48:22 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/06 00:34:10 by besaipid         ###   ########.fr       */
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

static void	ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
}

void	ft_join(char c, char **line)
{
	char	*temp;
	size_t	len;

	if (*line == NULL)
	{
		*line = malloc(2);
		if (!*line)
		{
			line = NULL;
			return ;
		}
		(*line)[0] = c;
		(*line)[1] = '\0';
	}
	else
	{
		len = ft_strlen(*line);
		temp = malloc((sizeof(char) * len) + 2);

		ft_strcpy(temp, *line);
		temp[len] = c;
		temp[++len] = '\0';
		free(*line);
		*line = temp;
		temp = NULL;
	}
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
