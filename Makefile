MINILIB = -L lib/minilibx/ -lmlx -lXext -lX11 -lm

LIBFT = -L lib/libft/ -lft

SRC = color.c draw_line.c fdf.c map_manager.c parsing.c pixeler.c point.c pos.c spl_int_tab.c utils.c

OBJ= $(SRC:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = fdf

$(NAME):
	make -C ./lib/libft
	$(CC) -o $(NAME) $(FLAGS) $(addprefix src/, $(SRC)) $(LIBFT) $(MINILIB) -g

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C ./lib/libft

fclean: clean
	rm -f $(NAME)
	make fclean -C ./lib/libft
	
re: fclean all