/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_id.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 01:43:44 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/07 04:15:33 by besaipid         ###   ########.fr       */
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

int	ft_defsign(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] > '0' && str[i] <= '9'))
	{
		if (str[i] == '+')
			return (1);
		i++;
	}
	return (-1);
}

int	ft_defzeropad(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] > '0' && str[i] <= '9'))
	{
		if (str[i] == '0')
			return (1);
		i++;
	}
	return (-1);
}
void	ft_process_id(int n, char **line, char *spec)
{
	char	*nb;
	flags	rules;
	int		nb_size;


	nb = ft_itoa(n);



	nb_size = ft_strlen(nb);
	rules.sp_size = ft_atoi(spec);
	rules.sign = ft_defsign(spec);
	rules.precision = ft_def_precision(spec);
	rules.zero_pad = ft_defzeropad(spec);
	rules.left = ft_defleft(spec);

	printf("raw nb: \"%s\"\n\n", nb);
	printf("sign: %d\n", rules.sign);
	printf("left %d\n", rules.left);
	printf("sp_size: %d\n", rules.sp_size);
	printf("precision: %d\n", rules.precision);
	printf("zeropad: %d\n", rules.zero_pad);
	printf("nb size: %d\n", nb_size);



	//printf("%s", res);
}
