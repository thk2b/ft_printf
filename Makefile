NAME = libftprintf.a
LIBFT = libft/libft.a

CC = gcc
FLAGS = -Wall -Wextra -Werror -I libft/includes

SRCS =\
	parse.c\
	convert_num.c\
	convert_utils.c\
	convert.c\
	linked_buffer.c\
	get_len.c\
	ft_printf.c\
	ft_vsnprintf.c\
	# convert_str.c\

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
