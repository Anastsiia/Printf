#include "ft_printf.h"

int	ft_print_i (char **str, int res, va_list args)
{
	int	a;
	int	i;

	a = 0;
	i = va_arg(args, int);
	ft_putnbr(i, &res);
	a++;
	while (str[0][a] && str[0][a] != '%')
	{
		res = ft_putchar_new((*str)[a], res);
		a++;
	}
	*str = *str + a;
	return (res);
}

int	ft_print_u (char **str, int res, va_list args)
{
	unsigned int	u;
	int				i;

	i = 0;
	u = (unsigned int)va_arg(args, int);
	ft_putnbr_ui(u, &res);
	i++;
	while (str[0][i] && str[0][i] != '%')
	{
		res = ft_putchar_new((*str)[i], res);
		i++;
	}
	*str = *str + i;
	return (res);
}

int	ft_print_x (char **str, int res, va_list args)
{
	unsigned int	x;
	int				i;

	i = 0;
	x = va_arg(args, unsigned int);
	ft_print_sixteen_x(x, &res);
	i++;
	while (str[0][i] && str[0][i] != '%')
	{
		res = ft_putchar_new((*str)[i], res);
		i++;
	}
	*str = *str + i;
	return (res);
}

int	ft_print_X (char **str, int res, va_list args)
{
	unsigned int	X;
	int				i;

	i = 0;
	X = va_arg(args, unsigned int);
	ft_print_sixteen_X(X, &res);
	i++;
	while (str[0][i] && str[0][i] != '%')
	{
		res = ft_putchar_new((*str)[i], res);
		i++;
	}
	*str = *str + i;
	return (res);
}

int	ft_print_p (char **str, int res, va_list args)
{
	unsigned long	p;
	int				i;

	i = 0;
	p = (unsigned long)va_arg(args, void *);
	write(1, "0x", 2);
	res = res + 2;
	ft_print_sixteen_x(p, &res);
	i++;
	while (str[0][i] && str[0][i] != '%')
	{
		res = ft_putchar_new((*str)[i], res);
		i++;
	}
	*str = *str + i;
	return (res);
}
