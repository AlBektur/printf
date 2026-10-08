NAME = run

CC = cc -g

SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils_2.c ft_process_char.c\
		ft_process_str.c ft_process_id.c ft_process_id_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC)  $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

