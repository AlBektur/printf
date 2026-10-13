/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 01:48:46 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/13 04:51:26 by besaipid         ###   ########.fr       */
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
	if (c == 'u')
		return (4);
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
	//printf("specifier: %c\n", s);

	if (s == 'c')
		ft_process_char(va_arg(*argv, int), str, spec);
	if (s == 's')
		ft_process_str(va_arg(*argv, char *), str, spec);
	if (s == 'i' || s == 'd')
		ft_process_id(va_arg(*argv, int), str, spec);
	if (s == 'u')
		ft_process_u(va_arg(*argv, unsigned int), str, spec);
	if (s == 'x')
		ft_process_x(va_arg(*argv, unsigned int), 1, str, spec);


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
	ft_process(&res, (char *)format, &argv);

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

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// #include <stdio.h>

// #include <limits.h>

// int ft_printf(const char *format, ...);

// void test(const char *format, int n) { int ret1; int ret2;

// printf("\n"); printf("FORMAT: [%s]\n", format); printf("INTEGER: [%d]\n", n);

// printf("["); ret1 = printf(format, n); printf("]\n");
// ft_printf(format, n);
// printf("\n\n");
// }

// int main(void) { /*

// ========================================
// BASIC %d
// ========================================

// */

// test("%d", 0); test("%d", 1); test("%d", 42); test("%d", 123); test("%d", 12345); test("%d", -1); test("%d", -42); test("%d", -123); test("%d", -12345);

// /*

// ========================================
// BASIC %i
// ========================================

// */

// test("%i", 0); test("%i", 1); test("%i", 42); test("%i", 123); test("%i", 12345); test("%i", -1); test("%i", -42); test("%i", -123); test("%i", -12345);

// /*

// ========================================
// INT LIMITS
// ========================================

// */

// test("%d", INT_MAX); test("%d", INT_MIN); test("%i", INT_MAX); test("%i", INT_MIN);

// /*

// ========================================
// WIDTH
// ========================================

// */

// test("%1d", 42); test("%2d", 42); test("%3d", 42); test("%4d", 42); test("%5d", 42); test("%10d", 42); test("%20d", 42);

// test("%1d", -42); test("%2d", -42); test("%3d", -42); test("%4d", -42); test("%5d", -42); test("%10d", -42);

// test("%1i", 12345); test("%3i", 12345); test("%5i", 12345); test("%10i", 12345);

// /*

// ========================================
// LEFT ALIGNMENT -
// ========================================

// */

// test("%-1d", 42); test("%-2d", 42); test("%-3d", 42); test("%-5d", 42); test("%-10d", 42);

// test("%-1d", -42); test("%-3d", -42); test("%-5d", -42); test("%-10d", -42);

// test("%-5i", 123); test("%-10i", -123);

// /*

// ========================================
// ZERO PADDING
// ========================================

// */

// test("%01d", 42); test("%02d", 42); test("%03d", 42); test("%05d", 42); test("%010d", 42);

// test("%03d", -42); test("%05d", -42); test("%010d", -42);

// test("%05i", 123); test("%05i", -123);

// /*

// ========================================
// PLUS FLAG +
// ========================================

// */

// test("%+d", 42); test("%+d", 0); test("%+d", -42);

// test("%+i", 42); test("%+i", 0); test("%+i", -42);

// test("%+5d", 42); test("%+5d", -42); test("%+05d", 42); test("%+05d", -42);

// /*

// ========================================
// SPACE FLAG
// ========================================

// */

// test("% d", 42); test("% d", 0); test("% d", -42);

// test("% i", 42); test("% i", 0); test("% i", -42);

// test("% 5d", 42); test("% 5d", -42); test("% 05d", 42);

// /*

// ========================================
// PRECISION
// ========================================

// */

// test("%.0d", 0); test("%.0d", 42); test("%.0d", -42);

// test("%.1d", 0); test("%.1d", 7); test("%.2d", 7); test("%.3d", 7); test("%.5d", 42); test("%.10d", 42);

// test("%.1d", -7); test("%.3d", -7); test("%.5d", -42);

// test("%.0i", 0); test("%.0i", 42); test("%.3i", 7); test("%.5i", -42);

// /*

// ========================================
// WIDTH + PRECISION
// ========================================

// */

// test("%5.2d", 42); test("%5.3d", 42); test("%5.5d", 42); test("%10.5d", 42);

// test("%5.2d", -42); test("%8.5d", -42);

// test("%5.3i", 7); test("%10.5i", -42);

// /*

// ========================================
// PRECISION + ZERO FLAG
// ========================================

// */

// test("%05.3d", 42); test("%05.5d", 42); test("%08.5d", -42);

// /*

// The precision overrides the zero flag.

// */

// test("%05.3i", 7); test("%08.5i", -42);

// /*

// ========================================
// COMBINED FLAGS
// ========================================

// */

// test("%-+8d", 42); test("%-+8d", -42); test("%- 8d", 42); test("%-08d", 42); test("%-08d", -42);

// test("%+08i", 42); test("%+08i", -42); test("%-+8i", 42);

// return (0); }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////


// void	test(const char *format, unsigned int n)
// {
// 	int	ret1;
// 	int	ret2;

// 	printf("\n");
// 	printf("FORMAT:    [%s]\n", format);
// 	printf("NUMBER:    [%u]\n", n);

// 	printf("printf:    [");
// 	ret1 = printf(format, n);
// 	printf("]\n");

// 	printf("ft_printf: [");
// 	ret2 = ft_printf(format, n);
// 	printf("]\n");

// 	printf("----------------------------------------\n");
// }

// int	main(void)
// {
// 	/*
// 	 * ========================================
// 	 * FLAG -
// 	 * ========================================
// 	 */
// 	test("%-u", 42);
// 	test("%-5u", 42);
// 	test("%-10u", 123);
// 	test("%-5u", 0);

// 	/*
// 	 * ========================================
// 	 * FLAG 0
// 	 * ========================================
// 	 */
// 	test("%0u", 42);
// 	test("%05u", 42);
// 	test("%010u", 123);
// 	test("%05u", 0);

// 	/*
// 	 * ========================================
// 	 * FLAG .
// 	 * PRECISION
// 	 * ========================================
// 	 */
// 	test("%.u", 0);
// 	test("%.0u", 0);
// 	test("%.1u", 0);
// 	test("%.3u", 42);
// 	test("%.5u", 42);
// 	test("%.5u", 12345);
// 	test("%.10u", 42);

// 	/*
// 	 * ========================================
// 	 * FLAG # (NO EFFECT ON %u)
// 	 * ========================================
// 	 */
// 	test("%#u", 42);
// 	test("%#u", 0);
// 	test("%#10u", 42);
// 	test("%#010u", 42);

// 	/*
// 	 * ========================================
// 	 * FLAG SPACE (NO EFFECT ON %u)
// 	 * ========================================
// 	 */
// 	test("% u", 42);
// 	test("% u", 0);
// 	test("% 10u", 42);
// 	test("% 010u", 42);

// 	/*
// 	 * ========================================
// 	 * FLAG + (NO EFFECT ON %u)
// 	 * ========================================
// 	 */
// 	test("%+u", 42);
// 	test("%+u", 0);
// 	test("%+10u", 42);
// 	test("%+010u", 42);

// 	/*
// 	 * ========================================
// 	 * COMBINED FLAGS
// 	 * ========================================
// 	 */
// 	test("%-05u", 42);
// 	test("%-10.5u", 42);
// 	test("%010.5u", 42);
// 	test("%-#10u", 42);
// 	test("%+010u", 42);
// 	test("% 010u", 42);
// 	test("%-+10u", 42);
// 	test("%- 10u", 42);
// 	test("%-#010u", 42);

// 	/*
// 	 * ========================================
// 	 * EDGE CASES
// 	 * ========================================
// 	 */
// 	test("%u", 0);
// 	test("%5u", 0);
// 	test("%05u", 0);
// 	test("%.0u", 0);
// 	test("%8.0u", 0);
// 	test("%u", UINT_MAX);
// 	test("%15u", UINT_MAX);
// 	test("%020u", UINT_MAX);

// 	return (0);
// }
