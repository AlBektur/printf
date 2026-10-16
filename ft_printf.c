/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: besaipid <besaipid@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 01:48:46 by besaipid          #+#    #+#             */
/*   Updated: 2026/10/16 06:29:06 by besaipid         ###   ########.fr       */
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
	int		j;
	char	*res;
	char	*temp;

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

int	ft_printf(const char *format, ...)
{
	va_list		argv;
	char		*res;

	va_start(argv, format);
	res = ft_loop((char *)format, &argv);
	printf("%s", res);
	va_end(argv);
	return (1);
}

int	main(int argc, char *argv[])
{
	ft_printf(argv[1], argv[2]);
	printf("\nupp\n");
	printf(argv[1], argv[2]);
	return (0);
}


// int	main(void) {
// printf("\n===== CHARACTERS =====\n");
// printf("|%c| |%5c| |%-5c| |%05c|\n", 'A', 'A', 'A', 'A');
// ft_printf("|%c| |%5c| |%-5c| |%05c|\n", 'A', 'A', 'A', 'A');
// printf("|%c| |%5c| |%-5c|\n", '\0', '\0', '\0');
// //ft_printf("|%c| |%5c| |%-5c|\n", '\0', '\0', '\0');

// printf("\n===== STRINGS =====\n");
// printf("|%s| |%10s| |%-10s|\n", "Hello", "Hello", "Hello");
// ft_printf("|%s| |%10s| |%-10s|\n", "Hello", "Hello", "Hello");
// printf("|%.0s| |%.3s| |%10.3s| |%-10.3s|\n",
// 	"Hello", "Hello", "Hello", "Hello");
// ft_printf("|%.0s| |%.3s| |%10.3s| |%-10.3s|\n",
// 	"Hello", "Hello", "Hello", "Hello");

// printf("\n===== SIGNED INTEGERS =====\n");
// printf("|%d| |%i| |%+d| |% d|\n", 42, -42, 42, 42);
// ft_printf("|%d| |%i| |%+d| |% d|\n", 42, -42, 42, 42);
// printf("|%05d| |%-5d| |%.5d| |%8.5d|\n", 42, 42, 42, 42);
// ft_printf("|%05d| |%-5d| |%.5d| |%8.5d|\n", 42, 42, 42, 42);
// printf("|%+08d| |% 08d| |%-+8d|\n", 42, 42, 42);
// ft_printf("|%+08d| |% 08d| |%-+8d|\n", 42, 42, 42);
// printf("|%d| |%d|\n", INT_MIN, INT_MAX);
// ft_printf("|%d| |%d|\n", INT_MIN, INT_MAX);
// printf("|%.0d| |%.0d|\n", 0, 42);
// ft_printf("|%.0d| |%.0d|\n", 0, 42);

// printf("\n===== UNSIGNED INTEGERS =====\n");
// printf("|%u| |%010u| |%.5u| |%10.5u|\n",
// 	42u, 42u, 42u, 42u);
// ft_printf("|%u| |%010u| |%.5u| |%10.5u|\n",
// 	42u, 42u, 42u, 42u);
// printf("|%u|\n", UINT_MAX);
// ft_printf("|%u|\n", UINT_MAX);
// printf("|%.0u|\n", 0u);
// ft_printf("|%.0u|\n", 0u);

// printf("\n===== HEXADECIMAL =====\n");
// printf("|%x| |%X| |%#x| |%#X|\n", 255, 255, 255, 255);
// ft_printf("|%x| |%X| |%#x| |%#X|\n", 255, 255, 255, 255);
// printf("|%08x| |%.5x| |%8.5x|\n", 255, 255, 255);
// ft_printf("|%08x| |%.5x| |%8.5x|\n", 255, 255, 255);
// printf("|%#08x| |%#8x| |%#.5x|\n", 255, 255, 255);
// ft_printf("|%#08x| |%#8x| |%#.5x|\n", 255, 255, 255);
// printf("|%#x| |%#.0x|\n", 0, 0);
// ft_printf("|%#x| |%#.0x|\n", 0, 0);

// printf("\n===== POINTERS =====\n");
// int	n = 42;
// printf("|%p| |%p|\n", (void *)&n, (void *)0);
// ft_printf("|%p| |%p|\n", (void *)&n, (void *)0);
// printf("|%20p| |%-20p|\n", (void *)&n, (void *)&n);
// ft_printf("|%20p| |%-20p|\n", (void *)&n, (void *)&n);

// printf("\n===== PERCENT SIGN =====\n");
// printf("100%% complete\n");
// ft_printf("100%% complete\n");
// printf("%% %% %%\n");
// ft_printf("%% %% %%\n");

// printf("\n===== MIXED CONVERSIONS =====\n");
// printf("|%c| |%s| |%p| |%d| |%i| |%u| |%x| |%X| |%%|\n",
// 	'A', "Hello", (void *)&n, -42, 42, 42u, 255, 255);
// ft_printf("|%c| |%s| |%p| |%d| |%i| |%u| |%x| |%X| |%%|\n",
// 	'A', "Hello", (void *)&n, -42, 42, 42u, 255, 255);

// printf("\n===== EDGE CASES =====\n");
// printf("|%d| |%u| |%x| |%X|\n", 0, 0u, 0, 0);
// ft_printf("|%d| |%u| |%x| |%X|\n", 0, 0u, 0, 0);
// printf("|%2d| |%2s|\n", 12345, "Hello");
// ft_printf("|%2d| |%2s|\n", 12345, "Hello");
// printf("|%015d| |%015d| |%015u|\n", INT_MIN, INT_MAX, UINT_MAX);
// ft_printf("|%015d| |%015d| |%015u|\n", INT_MIN, INT_MAX, UINT_MAX);

// printf("\n===== FINAL VISUAL TEST =====\n");
// printf("|%5c| |%-5c| |%05d| |%-8d| |%+08d|\n",
// 	'A', 'B', 42, -42, 42);
// ft_printf("|%5c| |%-5c| |%05d| |%-8d| |%+08d|\n",
// 	'A', 'B', 42, -42, 42);

// printf("|%10s| |%-10s| |%.3s| |%10.3s|\n",
// 	"Hello", "World", "Hello", "Hello");
// ft_printf("|%10s| |%-10s| |%.3s| |%10.3s|\n",
// 	"Hello", "World", "Hello", "Hello");

// printf("|%#x| |%#08x| |%.5x| |%8.5x|\n",
// 	255, 255, 255, 255);
// ft_printf("|%#x| |%#08x| |%.5x| |%8.5x|\n",
// 	255, 255, 255, 255);

// printf("\n===== END =====\n");
// return (0);

// }
