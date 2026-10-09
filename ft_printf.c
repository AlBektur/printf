/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 01:48:46 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/09 04:47:14 by besaipid         ###   ########.fr       */
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


	s = ft_def_specifier(spec);
	printf("specifier: %c\n", s);

	if (s == 'c')
		ft_process_char(va_arg(*argv, int), str, spec);
	if (s == 's')
		ft_process_str(va_arg(*argv, char *), str, spec);
	if (s == 'i' || s == 'd')
		ft_process_id(va_arg(*argv, int), str, spec);


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
	printf("\nfrm part: %s\n", spec);
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
	while(format[i])
	{
		if (format[i] != '%')
		{
			ft_join(format[i], &res);
			printf("%c", format[i]);
		}
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
//	printf("%s" , res);
	return (1);
}

int	main(int argc, char *argv[])
{
	ft_printf(argv[1], atoi(argv[2]));
	printf("\nupp\n");
	printf(argv[1], atoi(argv[2]));
	return (0);
}

// #include <stdio.h>

// int	ft_printf(const char *format, ...);

// void	test(const char *format, const char *str)
// {
// 	int	ret1;
// 	int	ret2;

// 	printf("\n");
// 	printf("FORMAT:    [%s]\n", format);
// 	printf("STRING:    [%s]\n", str);

// 	printf("printf:    [");
// 	ret1 = printf(format, str);
// 	printf("]\n");

// 	printf("ft_printf: [");
// 	ret2 = ft_printf(format, str);
// 	printf("]\n");


// 	printf("----------------------------------------\n");
// }

// int	main(void)
// {
// 	/*
// 	 * ========================================
// 	 * BASIC %s
// 	 * ========================================
// 	 */

// 	test("%s", "hello");
// 	test("%s", "Hello World");
// 	test("%s", "42");
// 	test("%s", "abc");
// 	test("%s", "abcdefghijklmnopqrstuvwxyz");
// 	test("%s", "");
// 	test("%s", " ");
// 	test("%s", "123456789");


// 	/*
// 	 * ========================================
// 	 * WIDTH
// 	 * ========================================
// 	 */

// 	test("%1s", "hello");
// 	test("%2s", "hello");
// 	test("%3s", "hello");
// 	test("%4s", "hello");
// 	test("%5s", "hello");
// 	test("%6s", "hello");
// 	test("%7s", "hello");
// 	test("%8s", "hello");
// 	test("%9s", "hello");
// 	test("%10s", "hello");
// 	test("%15s", "hello");
// 	test("%20s", "hello");

// 	/*
// 	 * Width smaller than string
// 	 */

// 	test("%1s", "hello world");
// 	test("%2s", "hello world");
// 	test("%3s", "hello world");
// 	test("%5s", "hello world");
// 	test("%10s", "hello world");
// 	test("%20s", "hello world");


// 	/*
// 	 * ========================================
// 	 * LEFT ALIGNMENT -
// 	 * ========================================
// 	 */

// 	test("%-1s", "hello");
// 	test("%-2s", "hello");
// 	test("%-3s", "hello");
// 	test("%-4s", "hello");
// 	test("%-5s", "hello");
// 	test("%-6s", "hello");
// 	test("%-7s", "hello");
// 	test("%-10s", "hello");
// 	test("%-15s", "hello");
// 	test("%-20s", "hello");

// 	/*
// 	 * - with different strings
// 	 */

// 	test("%-10s", "a");
// 	test("%-10s", "ab");
// 	test("%-10s", "abc");
// 	test("%-10s", "abcdefghij");
// 	test("%-10s", "abcdefghijk");
// 	test("%-10s", "hello world");


// 	/*
// 	 * ========================================
// 	 * PRECISION
// 	 * ========================================
// 	 */

// 	test("%.0s", "hello");
// 	test("%.1s", "hello");
// 	test("%.2s", "hello");
// 	test("%.3s", "hello");
// 	test("%.4s", "hello");
// 	test("%.5s", "hello");
// 	test("%.6s", "hello");
// 	test("%.10s", "hello");
// 	test("%.20s", "hello");

// 	/*
// 	 * Precision smaller than string
// 	 */

// 	test("%.1s", "hello world");
// 	test("%.2s", "hello world");
// 	test("%.3s", "hello world");
// 	test("%.4s", "hello world");
// 	test("%.5s", "hello world");

// 	/*
// 	 * Precision larger than string
// 	 */

// 	test("%.10s", "hi");
// 	test("%.20s", "hi");
// 	test("%.50s", "hi");

// 	/*
// 	 * Precision with empty string
// 	 */

// 	test("%.0s", "");
// 	test("%.1s", "");
// 	test("%.5s", "");


// 	/*
// 	 * ========================================
// 	 * WIDTH + PRECISION
// 	 * ========================================
// 	 */

// 	test("%5.0s", "hello");
// 	test("%5.1s", "hello");
// 	test("%5.2s", "hello");
// 	test("%5.3s", "hello");
// 	test("%5.4s", "hello");
// 	test("%5.5s", "hello");

// 	test("%10.0s", "hello");
// 	test("%10.1s", "hello");
// 	test("%10.2s", "hello");
// 	test("%10.3s", "hello");
// 	test("%10.4s", "hello");
// 	test("%10.5s", "hello");
// 	test("%10.10s", "hello");

// 	test("%20.3s", "hello");
// 	test("%20.5s", "hello");
// 	test("%20.10s", "hello");


// 	/*
// 	 * ========================================
// 	 * - + WIDTH
// 	 * ========================================
// 	 */

// 	test("%-5s", "hello");
// 	test("%-10s", "hello");
// 	test("%-15s", "hello");
// 	test("%-20s", "hello");

// 	/*
// 	 * - + PRECISION
// 	 */

// 	test("%-5.0s", "hello");
// 	test("%-5.1s", "hello");
// 	test("%-5.2s", "hello");
// 	test("%-5.3s", "hello");
// 	test("%-5.4s", "hello");
// 	test("%-5.5s", "hello");

// 	test("%-10.1s", "hello");
// 	test("%-10.3s", "hello");
// 	test("%-10.5s", "hello");
// 	test("%-10.10s", "hello");

// 	/*
// 	 * ========================================
// 	 * 0 FLAG
// 	 * ========================================
// 	 */

// 	test("%0s", "hello");
// 	test("%05s", "hello");
// 	test("%010s", "hello");
// 	test("%015s", "hello");
// 	test("%020s", "hello");

// 	test("%05.3s", "hello");
// 	test("%010.3s", "hello");
// 	test("%010.5s", "hello");


// 	/*
// 	 * ========================================
// 	 * + FLAG
// 	 * ========================================
// 	 */

// 	test("%+s", "hello");
// 	test("%+5s", "hello");
// 	test("%+10s", "hello");
// 	test("%+20s", "hello");

// 	test("%+.3s", "hello");
// 	test("%+10.3s", "hello");


// 	/*
// 	 * ========================================
// 	 * # FLAG
// 	 * ========================================
// 	 */

// 	test("%#s", "hello");
// 	test("%#5s", "hello");
// 	test("%#10s", "hello");
// 	test("%#20s", "hello");

// 	test("%#.3s", "hello");
// 	test("%#10.3s", "hello");


// 	/*
// 	 * ========================================
// 	 * SPACE FLAG
// 	 * ========================================
// 	 */

// 	test("% s", "hello");
// 	test("% 5s", "hello");
// 	test("% 10s", "hello");
// 	test("% 20s", "hello");

// 	test("% .3s", "hello");
// 	test("% 10.3s", "hello");


// 	/*
// 	 * ========================================
// 	 * - + 0 COMBINATIONS
// 	 * ========================================
// 	 */

// 	test("%-05s", "hello");
// 	test("%-010s", "hello");
// 	test("%-015s", "hello");

// 	test("%-05.3s", "hello");
// 	test("%-010.3s", "hello");
// 	test("%-010.5s", "hello");


// 	/*
// 	 * ========================================
// 	 * + 0 COMBINATIONS
// 	 * ========================================
// 	 */

// 	test("%+05s", "hello");
// 	test("%+010s", "hello");
// 	test("%+015s", "hello");

// 	test("%+05.3s", "hello");
// 	test("%+010.3s", "hello");


// 	/*
// 	 * ========================================
// 	 * # 0 COMBINATIONS
// 	 * ========================================
// 	 */

// 	test("%#05s", "hello");
// 	test("%#010s", "hello");
// 	test("%#015s", "hello");

// 	test("%#05.3s", "hello");
// 	test("%#010.3s", "hello");


// 	/*
// 	 * ========================================
// 	 * + # COMBINATIONS
// 	 * ========================================
// 	 */

// 	test("%+#s", "hello");
// 	test("%+#5s", "hello");
// 	test("%+#10s", "hello");

// 	test("%+#.3s", "hello");
// 	test("%+#10.3s", "hello");


// 	/*
// 	 * ========================================
// 	 * - # COMBINATIONS
// 	 * ========================================
// 	 */

// 	test("%-#s", "hello");
// 	test("%-#5s", "hello");
// 	test("%-#10s", "hello");

// 	test("%-#.3s", "hello");
// 	test("%-#10.3s", "hello");


// 	/*
// 	 * ========================================
// 	 * - + COMBINATIONS
// 	 * ========================================
// 	 */

// 	test("%-+s", "hello");
// 	test("%-+5s", "hello");
// 	test("%-+10s", "hello");

// 	test("%-+.3s", "hello");
// 	test("%-+10.3s", "hello");


// 	/*
// 	 * ========================================
// 	 * - 0 # COMBINATIONS
// 	 * ========================================
// 	 */

// 	test("%-0s", "hello");
// 	test("%-05s", "hello");
// 	test("%-010s", "hello");

// 	test("%-0#5s", "hello");
// 	test("%-0#10s", "hello");

// 	test("%-0#5.3s", "hello");
// 	test("%-0#10.3s", "hello");


// 	/*
// 	 * ========================================
// 	 * - 0 + COMBINATIONS
// 	 * ========================================
// 	 */

// 	test("%-0+s", "hello");
// 	test("%-0+5s", "hello");
// 	test("%-0+10s", "hello");

// 	test("%-0+5.3s", "hello");
// 	test("%-0+10.3s", "hello");


// 	/*
// 	 * ========================================
// 	 * ALL FLAGS
// 	 * ========================================
// 	 */

// 	test("%-0+#s", "hello");
// 	test("%-0+#5s", "hello");
// 	test("%-0+#10s", "hello");
// 	test("%-0+#20s", "hello");

// 	test("%-0+#5.0s", "hello");
// 	test("%-0+#5.1s", "hello");
// 	test("%-0+#5.3s", "hello");
// 	test("%-0+#5.5s", "hello");

// 	test("%-0+#10.3s", "hello");
// 	test("%-0+#10.5s", "hello");


// 	/*
// 	 * ========================================
// 	 * DIFFERENT STRING LENGTHS
// 	 * ========================================
// 	 */

// 	test("%10s", "a");
// 	test("%10s", "ab");
// 	test("%10s", "abc");
// 	test("%10s", "abcd");
// 	test("%10s", "abcde");
// 	test("%10s", "abcdef");
// 	test("%10s", "abcdefg");
// 	test("%10s", "abcdefgh");
// 	test("%10s", "abcdefghi");
// 	test("%10s", "abcdefghij");
// 	test("%10s", "abcdefghijk");
// 	test("%10s", "abcdefghijkl");
// 	test("%10s", "abcdefghijklmnop");


// 	/*
// 	 * ========================================
// 	 * PRECISION WITH DIFFERENT LENGTHS
// 	 * ========================================
// 	 */

// 	test("%.1s", "a");
// 	test("%.1s", "abcdef");

// 	test("%.3s", "a");
// 	test("%.3s", "abc");
// 	test("%.3s", "abcdef");

// 	test("%.5s", "abc");
// 	test("%.5s", "abcde");
// 	test("%.5s", "abcdefghij");


// 	/*
// 	 * ========================================
// 	 * WIDTH < PRECISION
// 	 * ========================================
// 	 */

// 	test("%2.5s", "hello");
// 	test("%3.10s", "hello");
// 	test("%5.10s", "hello");
// 	test("%5.20s", "hello");

// 	test("%-2.5s", "hello");
// 	test("%-3.10s", "hello");
// 	test("%-5.10s", "hello");


// 	/*
// 	 * ========================================
// 	 * WIDTH == PRECISION
// 	 * ========================================
// 	 */

// 	test("%5.5s", "hello");
// 	test("%10.10s", "hello");

// 	test("%-5.5s", "hello");
// 	test("%-10.10s", "hello");


// 	/*
// 	 * ========================================
// 	 * WIDTH > PRECISION
// 	 * ========================================
// 	 */

// 	test("%10.1s", "hello");
// 	test("%10.3s", "hello");
// 	test("%10.5s", "hello");

// 	test("%-10.1s", "hello");
// 	test("%-10.3s", "hello");
// 	test("%-10.5s", "hello");


// 	/*
// 	 * ========================================
// 	 * EMPTY STRING + EVERYTHING
// 	 * ========================================
// 	 */

// 	test("%5s", "");
// 	test("%-5s", "");
// 	test("%.5s", "");
// 	test("%5.3s", "");
// 	test("%-5.3s", "");

// 	test("%05s", "");
// 	test("%+5s", "");
// 	test("%#5s", "");
// 	test("% 5s", "");

// 	test("%-05s", "");
// 	test("%-+5s", "");
// 	test("%-#5s", "");
// 	test("%- 5s", "");

// 	test("%-0+#5.3s", "");


// 	/*
// 	 * ========================================
// 	 * FINAL MIX
// 	 * ========================================
// 	 */

// 	test("%-10.5s", "hello world");
// 	test("%-20.10s", "hello world");
// 	test("%10.5s", "hello world");
// 	test("%20.10s", "hello world");

// 	test("%-010.5s", "hello world");
// 	test("%-020.10s", "hello world");

// 	test("%+010.5s", "hello world");
// 	test("%#010.5s", "hello world");

// 	return (0);
// }


