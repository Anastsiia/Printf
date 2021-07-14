#include "ft_printf.h"

int	ft_putchar_new(char c, int res)
{
	write(1, &c, 1);
	res = res + 1;
	return (res);
}

void	ft_putnbr (int n, int *res)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		*res = *res + 11;
	}
	else if (n < 10 && n >= 0)
		*res = ft_putchar_new((n + '0'), *res);
	else if (n > 9)
	{
		ft_putnbr(n / 10, res);
		ft_putnbr(n % 10, res);
	}
	else
	{
		n = -n;
		*res = ft_putchar_new('-', *res);
		ft_putnbr(n, res);
	}
}

void	ft_putnbr_ui (unsigned int n, int *res)
{
	if (n >= 4294967295)
	{
		write(1, "4294967295", 10);
		*res = *res + 10;
	}
	else if (n < 10 && n >= 0)
		*res = ft_putchar_new((n + '0'), *res);
	else if (n > 9)
	{
		ft_putnbr_ui(n / 10, res);
		ft_putnbr_ui(n % 10, res);
	}
}

int	ft_print_sixteen_x(unsigned long x, int *res)
{
	if (x > 15)
		ft_print_sixteen_x(x / 16, res);
	if ((x % 16) >= 0 && (x % 16) <= 9)
		*res = ft_putchar_new(((x % 16) + '0'), *res);
	if ((x % 16) == 10)
		*res = ft_putchar_new('a', *res);
	if ((x % 16) == 11)
		*res = ft_putchar_new('b', *res);
	if ((x % 16) == 12)
		*res = ft_putchar_new('c', *res);
	if ((x % 16) == 13)
		*res = ft_putchar_new('d', *res);
	if ((x % 16) == 14)
		*res = ft_putchar_new('e', *res);
	if ((x % 16) == 15)
		*res = ft_putchar_new('f', *res);
	return (*res);
}

int	ft_print_sixteen_X(unsigned long x, int *res)
{
	if (x > 15)
		ft_print_sixteen_X(x / 16, res);
	if ((x % 16) >= 0 && (x % 16) <= 9)
		*res = ft_putchar_new((x % 16) + '0', *res);
	if ((x % 16) == 10)
		*res = ft_putchar_new('A', *res);
	if ((x % 16) == 11)
		*res = ft_putchar_new('B', *res);
	if ((x % 16) == 12)
		*res = ft_putchar_new('C', *res);
	if ((x % 16) == 13)
		*res = ft_putchar_new('D', *res);
	if ((x % 16) == 14)
		*res = ft_putchar_new('E', *res);
	if ((x % 16) == 15)
		*res = ft_putchar_new('F', *res);
	return (*res);
}
