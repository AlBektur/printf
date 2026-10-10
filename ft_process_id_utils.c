/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_id_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 16:13:36 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/10 15:17:11 by besaipid         ###   ########.fr       */
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


void	ft_make_precision(char **nb, int precision)
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

	// printf("nb_len: %d\n",nb_len);
	// protector need to be added
	temp = malloc(sizeof(char) * (nb_len + 1));

	i = 0;
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


void	ft_add_sign(char **nb, int n)
{
	int		len;
	char	c;
	int		i;
	char	*temp;
	int		j;

	if (n < 0)
		c = '-';
	else
		c = '+';

	len = ft_strlen(*nb) + 1;

	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		*nb = NULL;

	i = 1;
	temp[0] = c;
	j = 0;
	while((*nb)[j])
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

void	ft_make_id_line(char **nb, t_flags rules, int n)
{
	int		i;
	char	*temp;
	char	pad;
	char	c;
	int		j;



	if (rules.zero_pad != -1 && rules.left == -1)
		c = '0';
	else if (rules.left != -1)

//"%+10.5d" "-10"
	if (rules.sp_size != -1 && rules.sp_size > (ft_strlen(*nb) + rules.sign))
	{
		i = 0;
		j = 0;
		// protector need to be added
		temp = malloc(sizeof(char) * (rules.sp_size + 1));

		if (rules.left == -1)
		{
			if (rules.sign != -1)
				ft_add_sign(nb, n);
			printf("after adding sign: \"%s\"\n",  *nb);
			while (i < (rules.sp_size - ft_strlen(*nb)))
			{
				temp[i] = c;
				i++;
			}
			while (i < rules.sp_size)
			{
				temp[i] = *nb[j];
				i++;
				j++;
			}
			temp[i] = '\0';
		}
		else
		{

			while (i < ft_strlen(*nb))
			{
				temp[i] = (*nb)[i];
				i++;
			}
			while (i < rules.sp_size)
			{
				temp[i] = (*nb)[j];
				j++;
				i++;
			}
			temp[i] = '\0';
			if (rules.sign != -1)
				ft_add_sign(temp, n);
			printf("after adding signs: \"%s\"\n",  &temp);
		}
		free(*nb);
		*nb = temp;
		temp = NULL;
	}
}
