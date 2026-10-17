# NAME = run
# CFLAGS = -Wall -Wextra -Werror
# CC = cc -g

# SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils_2.c ft_printf_utils_3.c\
# 		ft_process_char.c ft_process_str.c ft_process_id.c ft_process_id_utils.c\
# 		ft_process_u.c ft_process_u_utils.c ft_process_x.c ft_process_p.c
# OBJS = $(SRCS:.c=.o)

# AR = ar
# ARFLAGS = rcs

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) -o $(NAME)

# %.o: %.c
# 	$(CC) -c $< -o $@

# clean:
# 	rm -f $(OBJS)

# fclean: clean
# 	rm -f $(NAME)
# re: fclean all


# NAME = libftprintf.a

# CC = cc
# CFLAGS = -Wall -Wextra -Werror

# AR = ar
# ARFLAGS = rcs
# RM = rm -f

# SRCS = ft_printf.c \
#        ft_printf_utils.c \
#        ft_printf_utils_2.c \
#        ft_printf_utils_3.c \
#        ft_process_char.c \
#        ft_process_str.c \
#        ft_process_id.c \
#        ft_process_id_utils.c \
#        ft_process_u.c \
#        ft_process_u_utils.c \
#        ft_process_x.c \
#        ft_process_p.c

# OBJS = $(SRCS:.c=.o)

# all: $(NAME)

# $(NAME): $(OBJS)
# 	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

# %.o: %.c
# 	$(CC) $(CFLAGS) -c $< -o $@

# clean:
# 	$(RM) $(OBJS)

# fclean: clean
# 	$(RM) $(NAME)

# re: fclean all

# .PHONY: all clean fclean re

NAME      := libftprintf.a
CC        := cc
CFLAGS    := -Wall -Wextra -Werror -g
AR        := ar
RCS       := rcs
RM        := rm -f
SRCS = ft_printf.c \
       ft_printf_utils.c \
       ft_printf_utils_2.c \
       ft_printf_utils_3.c \
       ft_process_char.c \
       ft_process_str.c \
       ft_process_id.c \
       ft_process_id_utils.c \
       ft_process_u.c \
       ft_process_u_utils.c \
       ft_process_x.c \
       ft_process_p.c
OBJS      := $(SRCS:.c=.o)

HEADER    := ft_printf.h

all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(RCS) $@ $^

%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) -c -o $@ $<

bonus : all
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

.PHONY : all clean fclean re
