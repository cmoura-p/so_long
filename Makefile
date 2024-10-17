NAME		= so_long
MLX 		= ./minilibx-linux/libmlx.a
MLX_DIR 	= ./minilibx-linux
CC			= gcc
FLAGS		= -Wall -Werror -Wextra -g
MLX_FLAGS 	= -L./minilibx-linux -lmlx -lX11 -lXext
RM			= rm -f

LIBFT	= ./libft/libft.a
SRC_DIR	= ./
OBJ_DIR	= obj/

SRCS	=	./main.c

OBJ	= $(patsubst $(SRCS_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:
	@make all

$(LIBFT):
	@make -C ./libft

all:	$(NAME)

$(NAME):$(OBJ) $(LIBFT)
	$(MAKE) -C $(MLX_DIR)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT) $(MLX) $(MLX_FLAGS)

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)
	@make clean -C ./libft

fclean:	clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re:	fclean all

.PHONY:	start all clean fclean re
