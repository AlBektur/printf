/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 01:48:46 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/15 06:06:44 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// if this returns false, spec should be printed
int	ft_format_validator(char *spec);

int	ft_isspecifier(char c)
{
//	cspdiuxX%
	if (c == 'c')
		return (1);
	if (c == 's')
		return (2);
	if (c == 'i' || c == 'd')
		return (3);
	if (c == 'u')
		return (4);
	if (c == 'x')
		return (16);
	if (c == 'X')
		return (16);
	// if (c == '%')
	// 	return (6);
	if (c == 'p')
		return (7);
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

int	ft_isflag(char c)
{
	int		i;
	char	*flags;

	flags = "-0.# +";
	i = 0;

	if (ft_isdigit(c))
		return (1);
	while(flags[i])
	{
		if (flags[i] == c)
			return (1);
		i++;
	}
	return (0);
}
void	ft_process_argv(char *spec, va_list *argv, char **str)
{
	char	s;


	s = ft_def_specifier(spec);
	//printf("specifier: %c\n", s);

	if (s == 'c')
		ft_process_char(va_arg(*argv, int), str, spec);
	else if (s == 's')
		ft_process_str(va_arg(*argv, char *), str, spec);
	else if (s == 'i' || s == 'd')
		ft_process_id(va_arg(*argv, int), str, spec);
	else if (s == 'u')
		ft_process_u(va_arg(*argv, unsigned int), str, spec);
	else if (s == 'x')
		ft_process_x(va_arg(*argv, unsigned int), 1, str, spec);
	else if (s == 'X')
		ft_process_x(va_arg(*argv, unsigned int), 0, str, spec);
	else if (s =='p')
		ft_process_p(va_arg(*argv, void *), str, spec);



}

void	ft_process(char **line, char *fmt, va_list *argv)
{
	// here i start to define what type of argv is and concatonate
	// with the **line.

	//[flags] [width] [precision] [length] conversion

	// flags -0.# +
	char	*str; // this is the result of the processor.
	char	*spec; // this string is cut specifier str full, to be able to process


	spec = ft_substr(fmt);
	//printf("\nfrm part: %s\n", spec);
	// validator needs to be added!!!

	ft_process_argv(spec, argv, &str);
	// printf("%s", str);

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

	//ft_process(&res, (char *)format, &argv);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_strjoin(&res, NULL, format[i]);
			i += 2;
			continue ;
		}

		if (format[i] == '%' && format[i + 1] != '\0')
		{
			j = i + 1;
			while (ft_isflag(format[j]))
				j++;
			if (ft_isspecifier(format[j]))
			{
				ft_process(&temp, (char *)&format[i], &argv);
				ft_strjoin(&res, temp, (char)format[i]);
				i = j + 1;
			}
		}
		if (format[i] != '\0' && format[i] != '%')
		{
			ft_strjoin(&res, NULL, format[i]);
			i++;
		}
	}
	printf("%s\n", res);


	va_end(argv);
	return (1);
}

// int	main(int argc, char *argv[])
// {
// 	ft_printf(argv[1], argv[2]);
// 	printf("\nupp\n");
// 	printf(argv[1], argv[2]);
// 	return (0);
// }
