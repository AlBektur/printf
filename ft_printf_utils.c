/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 01:48:22 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/04 10:46:52 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

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

char	*ft_join(char c, char *line)
{
	char	*temp;
	size_t	len;

	if (line == NULL)
	{
		line = malloc(sizeof(char) + 1);
		if (!line)
			return (NULL);
		line[0] = c;
		line[1] = '\0';
	}
	else
	{
		len = ft_strlen(line);
		temp = malloc((sizeof(char) * len) + 1);

		ft_strcpy(temp, line);
		temp[len] = c;
		temp[++len] = '\0';
		free(line);
		line = temp;
		temp = NULL;
	}

	return (line);
}
