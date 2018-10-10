NAME = libftprintf.a
LIBFT_SRC = libft/srcs
CC = gcc
FLAGS = -Wall -Wextra -Werror -I libft/includes

SRCS =\
	parse_utils.c\
	parse.c\
	linked_buffer.c\
	convert_utils.c\
	set_digits.c\
	convert_num.c\
	convert_str.c\
	convert_percent.c\
	convert.c\
	get_len.c\
	ft_asprintf.c\
	ft_sprintf.c\
	ft_printf.c\
	$(LIBFT_SRC)/ft_atoi.c\
	$(LIBFT_SRC)/ft_isdigit.c\
	$(LIBFT_SRC)/ft_memcpy.c\
	$(LIBFT_SRC)/ft_strchr.c\
	$(LIBFT_SRC)/ft_strcpy.c\
	$(LIBFT_SRC)/ft_strdup.c\
	$(LIBFT_SRC)/ft_strlen.c\
	$(LIBFT_SRC)/ft_strncmp.c\
	$(LIBFT_SRC)/ft_strncpy.c\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
