NAME		= cub3D
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g #-fsanitize=address
RM			= /bin/rm -f

LIBFT_DIR	= libft

INCLUDE_DIR	= inc

MLX_DIR		= mlx
MLX_FLAGS	= -L$(MLX_DIR) -lmlx \
			-framework OpenGL \
			-framework AppKit
INCLUDES 	= -I$(INCLUDE_DIR) \
			-I$(LIBFT_DIR) \
			-I$(PRINTF_DIR) \
			-I$(MLX_DIR)
LIBS		= -L$(LIBFT_DIR) -lft \

BUILD_DIR	= build
SRC_DIR		= ./src
SRCS		=	main.c\
				errors/errors.c\
				graphic/3D_engine.c\
				graphic/utils.c\
				map/map_open.c\
				map/map_validation.c\
				map/player_validation.c\
				map/utils_2.c\
				map/utils.c\
				parser/color_parsing.c\
				parser/initialization.c\
				parser/line_parsing.c\
				parser/parsing.c\
				parser/texture_parsing.c\
				parser/utils.c\
				utils/utils.c\
				keys/keys.c\
				keys/exit.c\
				keys/keys_utils.c\
				graphic/ray_casting.c\
				graphic/ray_casting_part2.c\
				graphic/ray_utils.c\

OBJS =	$(SRCS:%.c=$(BUILD_DIR)/%.o)

all: $(NAME)

restart: cbuild $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(INCLUDES) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(NAME): $(OBJS) libs
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)

$(OBJS): $(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) -g $(CFLAGS) $(INCLUDES) -c $< -o $@

libs:
	@make -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)	

bonus: all

re: fclean all

cbuild:
	-$(RM) -r $(BUILD_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_DIR)
	$(RM) -r $(BUILD_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(MLX_DIR)	
	$(RM) $(NAME)

.PHONY: all clean fclean re
