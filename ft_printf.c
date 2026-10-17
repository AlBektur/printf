/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 01:48:46 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/17 06:08:41 by besaipid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isspecifier(char c)
{
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
	if (c == 'p')
		return (7);
	return (0);
}

char	ft_def_specifier(char *spec)
{
	int	i;

	i = 1;
	while (spec[i])
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
	while (flags[i])
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
	else if (s == 'p')
		ft_process_p(va_arg(*argv, void *), str, spec);
}

void	ft_process(char **line, char *fmt, va_list *argv)
{
	char	*str;
	char	*spec;

	spec = ft_substr(fmt);
	ft_process_argv(spec, argv, &str);
	*line = str;
}

void	ft_loop_2(char *format, va_list *argv, char **res, int *i)
{
	char	*temp;
	int		j;

	j = *i + 1;
	while (ft_isflag(format[j]))
		j++;
	if (ft_isspecifier(format[j]))
	{
		ft_process(&temp, (char *)&format[*i], argv);
		ft_strjoin(res, temp, (char)format[*i]);
		*i = j + 1;
	}
}

char	*ft_loop(char *format, va_list *argv)
{
	int		i;
	char	*res;

	res = NULL;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] == '%')
		{
			ft_strjoin(&res, NULL, format[i]);
			i += 2;
			continue ;
		}
		if (format[i] == '%' && format[i + 1] != '\0')
			ft_loop_2(format, argv, &res, &i);
		if (format[i] != '\0' && format[i] != '%')
		{
			ft_strjoin(&res, NULL, format[i]);
			i++;
		}
	}
	return (res);
}

int	ft_putstr(char *res)
{
	int	i;

	i = 0;
	if (!res)
		return (0);
	while (res[i])
	{
		if (write(1, &res[i], 1))
			i++;
		else
			return (-1);
	}
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list		argv;
	char		*res;

	va_start(argv, format);
	res = ft_loop((char *)format, &argv);
	//printf("%s", res);
	va_end(argv);
	return (ft_putstr(res));
}

// int	main(int argc, char *argv[])
// {
// 	ft_printf(argv[1], atoi(argv[2]));
// 	printf("\nupp\n");
// 	printf(argv[1], atoi(argv[2]));
// 	return (0);
// }




// #define TEST(name, ...) do { \
//     int real_ret; \
//     int ft_ret; \
//     printf("\n--- %s ---\n", name); \
//     printf("printf:    "); \
//     real_ret = printf(__VA_ARGS__); \
//     printf("\nReturn: %d\n", real_ret); \
//     printf("ft_printf: "); \
//     ft_ret = ft_printf(__VA_ARGS__); \
//     printf("\nReturn: %d\n", ft_ret); \
//     printf("Match: %s\n", real_ret == ft_ret ? "OK" : "KO"); \
// } while (0)

// int main(void)
// {
//     char *str = "Hello, 42!";
//     char *null_str = NULL;
//     int n = 42;
//     int *ptr = &n;

//     /* 1. Basic conversions */
//     TEST("Character", "Char: %c", 'A');
//     TEST("String", "String: %s", str);
//     TEST("Integer", "Integer: %d", 42);
//     TEST("Integer i", "Integer: %i", -42);
//     TEST("Unsigned", "Unsigned: %u", 4294967295u);
//     TEST("Hex lowercase", "Hex: %x", 255);
//     TEST("Hex uppercase", "Hex: %X", 255);
//     TEST("Pointer", "Pointer: %p", (void *)ptr);
//     TEST("Percent", "Percent: %%");

//     /* 2. Multiple conversions */
//     TEST("Mixed",
//         "c=%c s=%s d=%d i=%i u=%u x=%x X=%X %%\n",
//         'Z', "42", -123, 456, 789u, 255u, 255u);

//     /* 3. Integer boundaries */
//     TEST("INT_MAX", "%d", INT_MAX);
//     TEST("INT_MIN", "%d", INT_MIN);
//     TEST("Zero", "%d", 0);
//     TEST("Unsigned zero", "%u", 0u);
//     TEST("Unsigned max", "%u", UINT_MAX);
//     TEST("Hex zero", "%x", 0);
//     TEST("Hex max", "%x", UINT_MAX);

//     /* 4. NULL values */
//     TEST("NULL string", "%s", null_str);
//     TEST("NULL pointer", "%p", (void *)NULL);

//     /* 5. Different formats */
//     TEST("Empty string", "%s", "");
//     TEST("Only percent", "%%");
//     TEST("Several percents", "%%%%%%");
//     TEST("Adjacent conversions", "%d%d%d", 1, 2, 3);
//     TEST("No conversions", "Hello, world!");

//     /* 6. Return value with no output */
//     TEST("Empty format", "");

//     return 0;
// }



// #include <stdio.h>
// #include <limits.h>
// #include <stdint.h>
// #include "ft_printf.h"

// #define TEST(name, ...) do { \
//     int real_ret; \
//     int ft_ret; \
//     printf("\n\n========== %s ==========\n", name); \
//     printf("printf:    "); \
//     fflush(stdout); \
//     real_ret = printf(__VA_ARGS__); \
//     printf("\nReturn: %d\n", real_ret); \
//     printf("ft_printf: "); \
//     fflush(stdout); \
//     ft_ret = ft_printf(__VA_ARGS__); \
//     printf("\nReturn: %d\n", ft_ret); \
//     printf("Return value: %s\n", \
//         real_ret == ft_ret ? "OK" : "KO"); \
// } while (0)

// int main(void)
// {
//     char *str = "42 School";
//     char *empty = "";
//     char *null_str = NULL;
//     int n = 42;
//     int *ptr = &n;

//     /* =========================================
//        1. MANDATORY CONVERSIONS
//        ========================================= */
//     TEST("Character", "%c", 'A');
//     TEST("String", "%s", str);
//     TEST("Empty string", "%s", empty);
//     TEST("NULL string", "%s", null_str);
//     TEST("Pointer", "%p", (void *)ptr);
//     TEST("NULL pointer", "%p", (void *)NULL);
//     TEST("Decimal", "%d", -42);
//     TEST("Integer", "%i", 42);
//     TEST("Unsigned", "%u", UINT_MAX);
//     TEST("Hex lowercase", "%x", 255);
//     TEST("Hex uppercase", "%X", 255);
//     TEST("Percent", "%%");

//     /* =========================================
//        2. INTEGER EDGE CASES
//        ========================================= */
//     TEST("INT_MAX", "%d", INT_MAX);
//     TEST("INT_MIN", "%d", INT_MIN);
//     TEST("Zero decimal", "%d", 0);
//     TEST("Zero unsigned", "%u", 0u);
//     TEST("UINT_MAX", "%u", UINT_MAX);
//     TEST("Hex zero", "%x", 0);
//     TEST("Hex max", "%x", UINT_MAX);

//     /* =========================================
//        3. WIDTH
//        ========================================= */
//     TEST("Width decimal", "%10d", 42);
//     TEST("Width string", "%10s", "hello");
//     TEST("Width char", "%5c", 'A');
//     TEST("Width hex", "%8x", 255);
//     TEST("Width pointer", "%20p", (void *)ptr);
//     TEST("Width percent", "%5%", 0);

//     /* =========================================
//        4. LEFT ALIGNMENT (-)
//        ========================================= */
//     TEST("Left decimal", "%-10d", 42);
//     TEST("Left string", "%-10s", "hello");
//     TEST("Left char", "%-5c", 'A');
//     TEST("Left hex", "%-8x", 255);
//     TEST("Left zero", "%-5d", 0);

//     /* =========================================
//        5. ZERO PADDING (0)
//        ========================================= */
//     TEST("Zero padding", "%010d", 42);
//     TEST("Zero negative", "%010d", -42);
//     TEST("Zero hex", "%08x", 255);
//     TEST("Zero unsigned", "%010u", 42u);

//     /* =========================================
//        6. PRECISION (.)
//        ========================================= */
//     TEST("Precision decimal", "%.5d", 42);
//     TEST("Precision zero", "%.0d", 0);
//     TEST("Precision integer", "%.5i", -42);
//     TEST("Precision unsigned", "%.8u", 42u);
//     TEST("Precision hex", "%.6x", 255);
//     TEST("Precision string", "%.3s", "42 School");
//     TEST("Precision empty", "%.0s", "hello");
//     TEST("Precision empty string", "%.5s", "");

//     /* =========================================
//        7. WIDTH + PRECISION
//        ========================================= */
//     TEST("Width + precision", "%8.5d", 42);
//     TEST("Width + precision zero", "%8.5d", 0);
//     TEST("Width + precision negative", "%8.5d", -42);
//     TEST("String width precision", "%10.3s", "42 School");
//     TEST("Left width precision", "%-10.3s", "42 School");
//     TEST("Hex width precision", "%8.4x", 255);
//     TEST("Unsigned width precision", "%10.6u", 42u);

//     /* =========================================
//        8. ALTERNATE FORM (#)
//        ========================================= */
//     TEST("Alternate hex", "%#x", 255);
//     TEST("Alternate HEX", "%#X", 255);
//     TEST("Alternate hex zero", "%#x", 0);
//     TEST("Alternate HEX zero", "%#X", 0);
//     TEST("Alternate width", "%#10x", 255);
//     TEST("Alternate precision", "%#.8x", 255);

//     /* =========================================
//        9. SIGN FLAGS (+ AND SPACE)
//        ========================================= */
//     TEST("Plus positive", "%+d", 42);
//     TEST("Plus negative", "%+d", -42);
//     TEST("Plus zero", "%+d", 0);
//     TEST("Space positive", "% d", 42);
//     TEST("Space negative", "% d", -42);
//     TEST("Space zero", "% d", 0);
//     TEST("Plus width", "%+10d", 42);
//     TEST("Space width", "% 10d", 42);

//     /* =========================================
//        10. FLAG COMBINATIONS
//        ========================================= */
//     TEST("Minus and zero", "%-010d", 42);
//     TEST("Zero and precision", "%010.5d", 42);
//     TEST("Plus and zero", "%+010d", 42);
//     TEST("Space and zero", "% 010d", 42);
//     TEST("Alternate zero padding", "%#08x", 255);
//     TEST("Alternate left align", "%-#8x", 255);
//     TEST("Plus precision width", "%+8.5d", 42);
//     TEST("All integer flags", "%-+#10.5x", 255);
//     TEST("Space precision width", "% 10.5d", 42);

//     /* =========================================
//        11. MIXED CONVERSIONS
//        ========================================= */
//     TEST("Mixed conversions",
//         "c=%c s=%s d=%d i=%i u=%u x=%x X=%X %%\n",
//         'A', "42", -42, 42, 42u, 255u, 255u);

//     TEST("Empty format", "");
//     TEST("Plain text", "Hello, 42!");
//     TEST("Several percents", "%%%%%%");
//     TEST("Adjacent conversions", "%d%d%d", 1, 2, 3);

//     return (0);
// }
