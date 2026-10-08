/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_id_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 16:13:36 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/08 18:08:44 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	counter(long n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_reverse(char *str)
{
	size_t		start;
	size_t		end;
	size_t		len;
	char		temp;

	len = ft_strlen(str);
	len--;
	end = len;
	start = 0;
	while (start <= (len / 2))
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		end--;
		start++;
	}
}

static void	ft_fill(char *res, long n, int i, long sign)
{
	if (n < 0)
		n *= -1;
	while (n > 9)
	{
		res[i] = n % 10 + '0';
		n = n / 10;
		i++;
	}
	res[i] = n % 10 + '0';
	res[++i] = '\0';
}

char	*ft_itoa(int n)
{
	char		*res;
	int			i;
	long		sign;
	long		nb;

	i = 0;
	nb = (long)n;
	sign = nb;
	res = malloc(sizeof(int) * (counter(nb) + 1));
	if (res == NULL)
		return (NULL);
	ft_fill(res, nb, i, sign);
	ft_reverse(res);
	return (res);
}


void	ft_make_precision(char **nb, int precision, int sign, int n)
{
	char	*temp;
	int		nb_len;
	int			i;
	int			j;
	char		c;

	if (precision > ft_strlen(*nb))
		nb_len = precision;
	else
		nb_len = ft_strlen(*nb);

	if (sign && n < 0)
		c = '-';
	else if (sign && n >= 0)
		c = '+';

	if (sign)
		nb_len++;

	printf("nb_len: %d\n",nb_len);
	// protector need to be added
	temp = malloc(sizeof(char) * (nb_len + 1));

	i = 0;
	if (c == '+' || c == '-')
		temp[i++] = c;
	while(i < (nb_len - ft_strlen(*nb)))
	{
		temp[i] = '0';
		i++;
	}
	j = 0;

	while (i < nb_len)
	{
		temp[i] = (*nb)[j];
		i++;
		j++;
	}
	temp[i] = '\0';
	free(*nb);
	*nb = temp;
	temp = NULL;
}
