#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf (const char *format, ...);
int		ft_check_next(char *str, int res, va_list args);
int		ft_print_s (char **str, int res, va_list args);
int		ft_print_c (char **str, int res, va_list args);
int		ft_print_per (char **str, int res);
int		ft_print_i (char **str, int res, va_list args);
int		ft_print_u (char **str, int res, va_list args);
int		ft_print_x (char **str, int res, va_list args);
int		ft_print_X (char **str, int res, va_list args);
int		ft_print_p (char **str, int res, va_list args);
int		ft_print_sixteen_X(unsigned long x, int *res);
int		ft_print_sixteen_x(unsigned long x, int *res);
void	ft_putnbr_ui (unsigned int n, int *res);
void	ft_putnbr (int n, int *res);
int		ft_putchar_new(char c, int res);

#endif
