NAME = so_long
HEAD = so_long.h
MLX_PATH = mlx_linux/
MLX_LIB = 
SRC = 
OBJ_DIR = obj/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
CC = cc -Wall -Wextra -Werror


$(OBJ_DIR)%.o: %.c
	mkdir -p $(shell dirname $@)
	$(CC) -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)


all : $(NAME)

%.o : %.c $(HEAD)

${OBJ_DIR} :
	mkdir $(OBJ_DIR)

clean :
	rm -rf $(OBJ_DIR)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re