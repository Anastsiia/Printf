NAME = libftprintf.a

SRC = ft_printf.c	ft_printf_iuxXp.c	ft_printf_lib.c

OBJS = $(SRC:.c=.o)

CC = gcc

WWW = -Wall -Werror -Wextra

%.o:	%.c
	$(CC) $(WWW) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all 

.PHONY	:	all clean fclean re bonus
