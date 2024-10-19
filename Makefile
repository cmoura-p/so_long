NAME		= so_long
LIBFT		= ./libft/libft.a
LIBFT_DIR	= ./libft
MLX 		= ./minilibx-linux/libmlx.a
MLX_DIR 	= ./minilibx-linux
CC			= cc
FLAGS		= -Wall -Werror -Wextra -g
MLX_FLAGS 	= -L./minilibx-linux -lmlx -lX11 -lXext
SRCS		= ./main.c starting.c valid_board.c utils.c checking.c \
				ending.c loading_map.c play_game.c
OBJ_DIR		= ./obj
OBJS 		= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
RM			= rm -f

all:	$(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	$(MAKE) -C $(MLX_DIR)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) -r $(OBJ_DIR)

fclean:	clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	$(MAKE) clean -C $(MLX_DIR)
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	start all clean fclean re
