NAME = libftprintf.a
LIBFT = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -I libft/includes

SRCS =\
	parse.c\
	convert_num.c\
	convert_str.c\
	convert_utils.c\
	convert.c\
	linked_buffer.c\
	get_len.c\
	ft_asprintf.c\
	ft_sprintf.c\
	ft_printf.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(LIBFT):
	make -C libft

%.o: %.c $(LIBFT)
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all
