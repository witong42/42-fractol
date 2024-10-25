NAME = fractol

SRC_PATH = srcs/
SRC = main.c utils.c init.c render.c events.c clean.c
SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJS = $(SRCS:%.c=%.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

MLX = minilibx-linux
LIBS = -L$(MLX) -lmlx_Linux -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS) -I$(MLX) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
