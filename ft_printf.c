/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 01:48:46 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/05 05:11:11 by besaipid         ###   ########.fr       */
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
	char	s;

//	width = ft_def_width(spec);

	s = ft_def_specifier(spec);

	if (s == 'c')
		ft_process_char(va_arg(*argv, int), str, spec);
	if (s == 's')
		ft_process_str(va_arg(*arg, char *), str, spec);

	printf("specifier: %c\n", s);
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
	//printf("%s\n", str);

	*line = str;


}


int		ft_printf(const char *format, ...)
{
	va_list	argv;
	int			i;
	char	*res;
	int			j;
	char		*temp;
	va_start(argv, format);
	i = 0;
	res = NULL;
	while(format[i])
	{
		if (format[i] != '%')
			ft_join(format[i], &res);
		else
		{
			// this part needs to be finished, he result of the ft_process
			// should be inserted to res correctly
			ft_process(&res, (char *)&format[i], &argv);
			j = i + 1;
			while (!ft_isspecifier(format[j]))
				j++;
			i = j;
		}
		i++;
	}
	printf("%s" , res);
	free(res);
	return (1);
}

int	main(int argc, char *argv[])
{
	ft_printf(argv[1], argv[2][0]);
	printf("\nupp\n");
	printf(argv[1], argv[2][0]);
	return (0);
}
