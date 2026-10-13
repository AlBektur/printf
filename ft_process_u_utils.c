/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_u_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/13 01:08:13 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/13 02:22:25 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsaipidi <bsaipidi@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:22:20 by bsaipidi          #+#    #+#             */
/*   Updated: 2025/10/25 20:49:36 by bsaipidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		len_s;
	int		i;

	len_s = ft_strlen((char *)s);
	res = malloc(len_s + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

int	ft_counter(unsigned int n)
{
	int	size;

	size = 1;
	while (n >= 10)
	{
		size++;
		n /= 10;
	}
	return (size);
}

char	*ft_utoa(unsigned int n)
{
	char	*res;
	int		size;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_counter(n);
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	res[size] = '\0';
	while (n > 0)
	{
		res[--size] = n % 10 + '0';
		n /= 10;
	}
	return (res);
}
