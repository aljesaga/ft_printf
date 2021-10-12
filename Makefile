NAME  = libftprintf.a

SRC	= ft_unsig_itoa.c ft_hex.c ft_printf.c \
	ft_change.c ft_putchar.c ft_strlen.c \
	ft_putstr.c ft_itoa.c

OBJS = $(SRC:.c=.o)

CC	= gcc

RM 	= rm -f

CFLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJS)
	@ar -rcs $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

clean:	
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

PHONY.:clean all fclean re 