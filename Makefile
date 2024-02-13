#---------------------------------Archive-------------------------------------#
NAME			= so_long
LIBFTNAME		= libft.a

#---------------------------------Flags---------------------------------------#

CC 				= @cc
CFLAGS			= -Wall -Wextra -Werror -Wunreachable-code -Ofast
RM				= @rm -rf

#---------------------------------Directories---------------------------------#

SRC_DIR 		= .
LIBFT_DIR 		= ./libft
OBJ_DIR			= objects
MLX_DIR			= ./lib/MLX42

#---------------------------------MLX-----------------------------------------#

MLX_HEAD		= -I ./includes -I $(MLX_DIR)/include/MLX42/
MLX_A			= $(MLX_DIR)/build/libmlx42.a

ifeq ($(shell uname), Darwin)
	MLX_LIBS	= -L$(MLX_DIR)/build -lmlx42 -L"/Users/$(USER)/.brew/opt/glfw/lib" -lglfw -framework Cocoa -framework OpenGL -framework IOKit
else
	MLX_LIBS	= -L$(MLX_DIR)/build -lmlx42 -L"/Users/$(USER)/.brew/opt/glfw/lib" -lglfw -ldl -pthread -lm
endif

#---------------------------------Source Files--------------------------------#

SRC_FLS 		= 	$(SRC_DIR)/so_long.c $(SRC_DIR)/parse_map.c $(SRC_DIR)/check_map.c $(SRC_DIR)/valid_path.c\
					$(SRC_DIR)/map_check_two.c
#---------------------------------Object Files--------------------------------#

OBJS 			= $(patsubst $(SRC_DIR/)%.c, $(OBJ_DIR)/%.o, $(SRC_FLS))

#---------------------------------Colours-------------------------------------#
RED				= \033[1;91m
YELLOW			= \033[1;33m
GREEN			= \033[1;32m
CYAN			= \033[1;36m
PURPLE			= \033[1;35m
END				= \033[0m

#---------------------------------Rules---------------------------------------#
all: libmlx $(LIBFTNAME) $(NAME)

libmlx:
	@if [ ! -d $(MLX_DIR)/build ]; then\
		cmake $(MLX_DIR) -B $(MLX_DIR)/build && make -C $(MLX_DIR)/build -j4;\
	fi

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o:  $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -g $(CFLAGS) $(MLX_HEAD) -c $< -o $@

$(LIBFTNAME): 
	@make -C $(LIBFT_DIR)

$(NAME): $(OBJS) 

	@echo "${YELLOW}|------------------------>${PURPLE}Compiling so_long${YELLOW}<--------------------|${END}"

	$(CC) $(CFLAGS) $(MLX_HEAD) $(OBJS) -o $@ $(MLX_A) $(MLX_LIBS) $(LIBFT_DIR)/$(LIBFTNAME) 

	@echo "${YELLOW}|---------------->${GREEN}so_long Compiled Successfully${YELLOW}<----------------|${END}"

clean:
	$(RM) $(OBJ_DIR) $(MLX_DIR)/build
	@make clean -C libft/
	@echo "${YELLOW}|------------------------>${RED}so_long Cleaned${YELLOW}<----------------------|${END}"

fclean: clean
	$(RM) $(NAME)
	@rm -f libft/$(LIBFTNAME)

re: fclean all

.PHONY: all clean fclean re libmlx
