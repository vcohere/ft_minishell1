INC_PATH = ./includes/

LIB_PATH = ./libft/
LIB_NAME = libft.a
LIB_TOTAL = $(addprefix $(LIB_PATH),$(LIB_NAME))

SRC_PATH = ./src/
SRC_NAME =	get_next_line.c\
			main.c\
			cmd_div.c\
			path_worker.c\
			ft_utiles.c\
			ft_misc.c\
			cmd_next.c

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

NAME = ft_minishell1

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -L,$(LIB_PATH))
INC = $(addprefix -I,$(INC_PATH))

all: success

success: $(NAME)
	@echo "Project compilated."

$(NAME): $(LIB_TOTAL) $(OBJ)
	@$(CC) $(CFLAGS) $(LIB) $(INC) -o $(NAME) $(LIB_TOTAL) $(OBJ)

$(LIB_TOTAL):
	cd $(LIB_PATH) ; $(MAKE) -f Makefile

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null
	@$(CC) $(CFLAGS) $(LIB) $(INC) -o $@ -c $<

clean:
	@echo "Deleted files :"
	@rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || echo "" > /dev/null

fclean: clean
	@echo "Deleted files :"
	@rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
