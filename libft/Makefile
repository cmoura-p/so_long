# Standard
NAME			= libft.a

# Compiling and Flags
CC				= gcc
FLAGS			= -Wall -Wextra -Werror
RM				= rm -f
AR				= ar rcs

# Source Files
C_SOURCE = 	ft_atol.c ft_bzero.c ft_calloc.c ft_memset.c ft_strlen.c \
			get_next_line.c get_next_line_utils.c

OBJ = $(C_SOURCE:.c=.o)

# Build rules
all: 		$(NAME)

$(NAME): 	$(OBJ)
			@$(AR) $(NAME) $(OBJ)

%.o: %.c
			@$(CC) $(FLAGS) -c $< -o $@

clean:
				@$(RM) -r $(OBJ)
				@$(RM) .cache_exists

fclean: 		clean
				@$(RM) $(NAME)

re: 			fclean all

.PHONY: 		all clean fclean re

