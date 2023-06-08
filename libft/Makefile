NAME = libft.a
CC = cc -Wall -Werror -Wextra
RM = rm -rf
CFILE_DIR = ./src/
CFILE = 

SRC = $(addprefix $(CFILE_DIR), $(CFILE))
INCLUDE_DIR = ./include/
INCLUDE_FILE = libft.h
OBJ = $(SRC:.c=.o)

.c.o :
	$(CC) -c $< -o $@

all : $(NAME)
	ar rcs $(NAME) $(OBJ)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re