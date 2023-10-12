NAME = so_long
CC = cc -Wall -Wextra -Werror 
RM = rm -rf
SRC_PATH = ./src/
SRC_FILE = so_long.c\
			map_checker.c\
			map_checker_tools.c\
			tools.c\
			free.c\
			param_check.c\
			game_init.c\
			move.c\
			set_struct.c




SRC = $(addprefix $(SRC_PATH), $(SRC_FILE))
OBJ_PATH = ./obj/
OBJ_FILE = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILE))

INCLUDE_PATH = ./includes/
INCLUDE_FILE = so_long.h
INC = $(addprefix $(INCLUDE_PATH), $(INCLUDE_FILE))

LIBFT_PATH = ./libft/
LIBFT_FILE = libft.a
LIBFT_LIB = $(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

MLX_PATH = ./mlx_linux/
MLX_FILE = libmlx.a
MLX_LIB = $(addprefix $(MLX_PATH), $(MLX_FILE))
MLX_FLAGS = -lX11 -lXext
MLX_EX = $(MLX_LIB) $(MLX_FLAGS)

all : lib mlx $(NAME) 

$(NAME) : $(OBJ_PATH) $(OBJ)
	$(CC) $(OBJ) $(LIBFT_LIB) $(MLX_EX) -o $(NAME)

$(OBJ_PATH)%.o : %.c $(INC)
	mkdir -p $(shell dirname $@)
	$(CC) -c $< -o $@

${OBJ_PATH} :
	mkdir $(OBJ_PATH)

lib : 
	make -C $(LIBFT_PATH)

mlx :
	make -C $(MLX_PATH)

clean :
	make clean -C $(MLX_PATH)
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJ_PATH)

fclean : clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_PATH)

re : fclean all

.PHONY : all clean fclean re