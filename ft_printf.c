#include "ft_printf.h"

int	ft_print_per (char **str, int res)
{
	int	i;

	i = 0;
	res = ft_putchar_new('%', res);
	i++;
	while (str[0][i] && str[0][i] != '%')
	{
		res = ft_putchar_new((*str)[i], res);
		i++;
	}
	*str = *str + i;
	return (res);
}

int	ft_print_c (char **str, int res, va_list args)
{
	int				i;
	unsigned char	a;

	i = 0;
	a = (unsigned char)va_arg(args, int);
	res = ft_putchar_new(a, res);
	i++;
	while (str[0][i] && str[0][i] != '%')
	{
		res = ft_putchar_new((*str)[i], res);
		i++;
	}
	*str = *str + i;
	return (res);
}

int	ft_print_s (char **str, int res, va_list args)
{
	char	*cp;
	int		j;
	int		i;

	i = 0;
	j = 0;
	cp = va_arg(args, char *);
	if (cp == NULL)
		cp = "(null)\0";
	while (cp[j])
	{
		res = ft_putchar_new(cp[j], res);
		j++;
	}
	i++;
	while (str[0][i] && str[0][i] != '%')
	{
		res = ft_putchar_new((*str)[i], res);
		i++;
	}
	*str = *str + i;
	return (res);
}

int	ft_check_next(char *str, int res, va_list args)
{
	while (*str == '%')
	{
		str++;
		if (*str == '%')
			res = ft_print_per(&str, res);
		if (*str == 'd' || *str == 'i')
			res = ft_print_i(&str, res, args);
		if (*str == 'u')
			res = ft_print_u(&str, res, args);
		if (*str == 'c')
			res = ft_print_c(&str, res, args);
		if (*str == 's')
			res = ft_print_s(&str, res, args);
		if (*str == 'x')
			res = ft_print_x(&str, res, args);
		if (*str == 'X')
			res = ft_print_X(&str, res, args);
		if (*str == 'p')
			res = ft_print_p(&str, res, args);
	}
	return (res);
}

int	ft_printf (const char *format, ...)
{
	char	*str;
	int		res;
	va_list	args;

	res = 0;
	str = (char *)format;
	va_start(args, format);
	while (*str && *str != '%')
	{
		res = ft_putchar_new(*str, res);
		str++;
	}
	res = ft_check_next(str, res, args);
	va_end(args);
	return (res);
}
