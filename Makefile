NAME = precision

CC = cc -g

SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils_2.c ft_printf_utils_3.c\
		ft_process_char.c ft_process_str.c ft_process_id.c ft_process_id_utils.c\
		ft_process_u.c ft_process_u_utils.c ft_process_x.c ft_process_p.c
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
