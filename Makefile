NAME = wolfenstein

INCPATH		=	./
MLX_PATH	=	minilibx_linux/
SRCS_PATH	=	sources/
LIBFT		=	./libft/libft.a

INIT		=	init/
HOOK		=	hook/
GAME		=	game/
DRAW		=	drawing_tools/
ANIM		=	animation/

INCLUDES	=	$(MLX_PATH)mlx.h \
				wolfenstein.h

SRC			=	main.c \
				utils.c optimization.c \
				$(INIT)init_project.c $(INIT)init_game_struct.c $(INIT)init_window_struct.c $(INIT)init_map_struct.c $(INIT)init_player_struct.c $(INIT)init_keys_struct.c $(INIT)init_hooks_logics.c $(INIT)init_xpm_images.c $(INIT)init_animation_struct.c \
				$(HOOK)expose_hook.c $(HOOK)key_hook.c $(HOOK)mouse_hook.c \
				$(GAME)update.c $(GAME)handle_keys.c $(GAME)layout_home_screen.c $(GAME)layout_game_screen.c $(GAME)layout_map_screen.c $(GAME)display.c $(GAME)raycast.c $(GAME)minimap.c \
				$(DRAW)draw_rectangle.c \
				$(ANIM)animation_tools.c $(ANIM)animation_utils.c
		
OBJ			=	$(SRC:.c=.o)

CC			=	clang
INCS		=	-I./
LIBS		=	minilibx_linux/libmlx_Linux.a \
				-Lminilibx_linux -lmlx -lXext -lX11 -lm

# Separate flags for compilation and linking
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g $(INCS)
LDFLAGS = -fsanitize=address -g $(LIBS)
# CFLAGS = -Wall -Wextra -Werror $(INCS)
# LDFLAGS = $(LIBS)

all: $(NAME) 

$(NAME): $(OBJ)
	make --no-print-directory all -C libft
	$(CC) $(OBJ) $(LIBFT) -o $@ $(LDFLAGS)
	./$(NAME)

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

clean:
	make --no-print-directory clean -C libft
	rm -f $(OBJ)

fclean:
	make --no-print-directory fclean -C libft/
	rm -f $(OBJ)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
