NAME = libftprintf.a
LIBFT = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -I libft/includes

SRCS =\
	ft_dvprintf.c\
	ft_dprintf.c\
	ft_printf.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar rc $(NAME) $(OBJS)

$(LIBFT):
	make -C libft

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
