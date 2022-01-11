NAME = libftprintf.a

SRC = srcs/ft_printf.c \
						srcs/ft_hex.c \
						srcs/ft_num.c \
						srcs/ft_charstr.c

OBJS = $(SRC:.c=.o)

FLAGS = -Werror -Wextra -Wall

%.o: %.c
		gcc -c $(CFLAGS) -I includes $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(MAKE) bonus -C ./libft
		cp libft/libft.a $(NAME)
		ar -rcs $(NAME) $(OBJS)

clean:
		$(MAKE) clean -C ./libft
		rm -f $(OBJS)

fclean:
		$(MAKE) clean -C ./libft
		rm -f $(NAME) $(OBJS)

re: fclean all

.PHONY: all clean fclean re