NAME 			= so_long

CC	 			= cc

FLAGS 			= -Wall -Wextra -Werror -g

RM				= rm -rf

HEADER			= so_long.h

LINKING			= -I/usr/include -Imlx

MLX_FLAGS		= -Lmlx -lmlx -lXext -lX11

# MAIN

DIR_MAIN	 	= ./
SRC_MAIN	 	= so_long.c
PATH_MAIN		= $(addprefix $(DIR_MAIN), $(SRC_MAIN))

# UTILS

DIR_UTILS		= utils/
SRCS_UTILS		= check_map.c create_map.c flood_fill.c get_next_line.c get_next_line_utils.c make_move.c utils_1.c utils_2.c
PATH_UTILS		= $(addprefix $(DIR_UTILS), $(SRCS_UTILS))

# OBJECTS

OBJ_DIR			= objects
OBJ_MAIN		= $(addprefix $(OBJ_DIR)/, $(PATH_MAIN:.c=.o))
OBJ_UTILS		= $(addprefix $(OBJ_DIR)/, $(PATH_UTILS:.c=.o))

# COMMANDS

$(OBJ_DIR)/%.o: %.c 	$(HEADER) Makefile
							@mkdir -p $(dir $@)
							@${CC} ${FLAGS} -c $< -o $@

$(NAME):	$(OBJ_UTILS) $(OBJ_MAIN)
							@$(CC) $(OBJ_UTILS) $(OBJ_MAIN) -o $(NAME) $(MLX_FLAGS)

all:		$(NAME)

clean:
							@$(RM)	$(OBJ_DIR)

fclean:		clean
							@$(RM) $(NAME)

re:							fclean all

.PHONY: 	all clean fclean re
