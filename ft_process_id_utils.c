/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_id_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 16:13:36 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/17 02:52:49 by besaipid         ###   ########.fr       */
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

void	ft_make_precision_1(char **nb, char *temp, int precision, int nb_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (nb_len - ft_strlen(*nb)))
	{
		temp[i] = '0';
		i++;
	}
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

void	ft_make_precision(char **nb, int precision)
{
	char		*temp;
	int			nb_len;
	int			j;

	if (precision > ft_strlen(*nb))
		nb_len = precision;
	else
		nb_len = ft_strlen(*nb);
	temp = malloc(sizeof(char) * (nb_len + 1));
	ft_make_precision_1(nb, temp, precision, nb_len);
}

void	ft_add_sign_1(char **nb, char *temp, int len, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while ((*nb)[i])
	{
		if (ft_isdigit((*nb)[i]) == 1 || (*nb)[i] != ' ')
			break ;
		temp[i] = (*nb)[i];
		i++;
	}
	j = i;
	temp[i] = c;
	i++;
	while ((*nb)[j])
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

void	ft_add_sign(char **nb, int n, t_flags *rules)
{
	int		len;
	char	c;
	char	*temp;

	if (n < 0)
		c = '-';
	else
		c = '+';
	if (rules->space == 1)
		c = ' ';
	len = ft_strlen(*nb) + 1;
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		*nb = NULL;
	ft_add_sign_1(nb, temp, len, c);
}

void	ft_make_id_line_3(char **nb, char *temp, t_flags *rules, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (rules->sp_size - ft_strlen(*nb)))
	{
		temp[i] = c;
		i++;
	}
	while (i < rules->sp_size)
	{
		temp[i] = (*nb)[j];
		j++;
		i++;
	}
	temp[i] = '\0';
}

void	ft_make_id_line_2(char **nb, char *temp, t_flags *rules)
{
	int	i;

	i = 0;
	while (i < ft_strlen(*nb))
	{
		temp[i] = (*nb)[i];
		i++;
	}
	while (i < rules->sp_size)
	{
		temp[i] = ' ';
		i++;
	}
	temp[i] = '\0';
}

void	ft_make_id_line_1(char **nb, t_flags *rules, char c, int n)
{
	char	*temp;

	if (rules->sign != -1 || rules->space != -1)
		rules->sp_size--;
	if (rules->hash != -1)
		rules->sp_size -= 2;
	temp = malloc(sizeof(char) * (rules->sp_size + 1));
	if (!temp)
		return ;
	if (rules->left == 1)
		ft_make_id_line_2(nb, temp, rules);
	else if (rules->left != 1)
		ft_make_id_line_3(nb, temp, rules, c);
	if (rules->sign == 1 || rules->space == 1)
		ft_add_sign(&temp, n, rules);
	free(*nb);
	*nb = temp;
	temp = NULL;
}

void	ft_make_id_line(char **nb, t_flags *rules, int n)
{
	char	c;

	if (rules->zero_pad == 1)
		c = '0';
	else
		c = ' ';
	if (rules->sp_size > (ft_strlen(*nb) + rules->sign))
		ft_make_id_line_1(nb, rules, c, n);
	else
	{
		if (rules->sign == 1 || rules->space == 1)
			ft_add_sign(nb, n, rules);
	}
}
