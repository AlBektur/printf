/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 01:48:46 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/04 10:56:24 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_handler()
{


}

int		ft_handler()
int		ft_printf(const char *format, ...)
{
	va_list	argv;
	int			i;
	char	*res;

	va_start(argv, format);
	i = 0;
	res = NULL;
	while(format[i])
	{
		if (format[i] != '%')
			res = ft_join(format[i], res);
		i++;
	}
	printf("%s\n" , res);
	return (1);
}

int	main(int argc, char *argv[])
{
	ft_printf(argv[1], 123);
	return (0);
}
