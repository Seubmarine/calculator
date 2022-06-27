NAME = calculator

CC = gcc

CFLAGS = -g3 -Wall -Werror -Wextra

SRCS = $(wildcard src/*.c)

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

MLX = minilibx-linux/libmlx.a

#LIBS = -L minilibx-linux/ -lmlx -lXext -lX11 -L ft_3d/ -lft_3d -L libft/ -lft -lm
LIBS = 

INCLUDES = 

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	-rm -f $(OBJS)

fclean: clean
	-rm -f $(NAME)

re: fclean all
