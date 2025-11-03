CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
INC = ft_print.h

SRCS = \

	ft_tohexdec.c \
	ft_putstring.c \
	ft_printf.c \
	ft_writebutbetter.c \
	ft_itoa_write.c \
	ft_printunsigned.c \
	ft_calloc.c \
	ft_bzero.c \

OBJECTS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

%.o:%.c $(INC)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJECTS)

bonus: $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

fclean: clean;
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re