/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 01:48:46 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/05 00:07:12 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isspecifier(char c)
{
//	cspdiuxX%
	if (c == 'c')
		return (1);
	if (c == 's')
		return (2);
	if (c == 'd')
		return (3);
	if (c == 'i' || c == 'd')
		return (3);
	if (c == 'x')
		return (16);
	if (c == 'X')
		return (16);
	if (c == '%')
		return (6);
	return (0);
}

char	ft_def_specifier(char *spec)
{
	int	i;

	i = 1;
	while(spec[i])
	{
		if (ft_isspecifier(spec[i]) != 0)
			break ;
		i++;
	}
	return (spec[i]);
}

void	ft_process_argv(char *spec, va_list *argv, char **str)
{
	int	width;
	char	c;

//	width = ft_def_width(spec);

	c = ft_def_specifier(spec);

	printf("specifier: %c\n", c);
}

void	ft_process(char **line, char *fmt, va_list *argv)
{
	// here i start to define what type of argv is and concatonate
	// with the **line.

	//[flags] [width] [precision] [length] conversion

	// flags -0# +
	char	*str; // this is the result of the processor.
	char	*spec; // this string is cut specifier str full, to be able to process


	spec = ft_substr(fmt);
	printf("frm part: %s\n", spec);


	ft_process_argv(spec, argv, &str);




}
int		ft_printf(const char *format, ...)
{
	va_list	argv;
	int			i;
	char	*res;
	int			j;

	va_start(argv, format);
	i = 0;
	res = NULL;
	while(format[i])
	{
		if (format[i] != '%')
			ft_join(format[i], &res);
		else
		{
			ft_process(&res, (char *)&format[i], &argv);
			j = i + 1;
			while (!ft_isspecifier(format[j]))
				j++;
			i = j;
		}
		i++;
	}
	printf("%s\n" , res);
	free(res);
	return (1);
}

int	main(int argc, char *argv[])
{
	ft_printf(argv[1], 123);

	printf(argv[1], 123);
	return (0);
}
