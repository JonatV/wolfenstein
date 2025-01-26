NAME = wolfenstein

INCPATH		=	./
MLX_PATH	=	minilibx_linux/
SRCS_PATH	=	sources/
LIBFT		=	./libft/libft.a

INIT		=	init/
HOOK		=	hook/
GAME		=	game/
KEYS		=	keys/
DRAW		=	drawing_tools/
PARS		=	parsing/
GNL			=	gnl/
ANIM		=	animation/
TOOL		=	tools/

INCLUDES	=	$(MLX_PATH)mlx.h \
				wolfenstein.h

SRC			=	main.c \
				optimization.c \
				$(INIT)init_project.c $(INIT)init_game_struct.c $(INIT)init_window_struct.c $(INIT)init_map_struct.c $(INIT)init_player_struct.c $(INIT)init_keys_struct.c $(INIT)init_hooks_logics.c $(INIT)init_xpm_images.c $(INIT)init_animation_struct.c $(INIT)init_pars_struct.c $(INIT)init_animation_minimap_struct.c $(INIT)init_animation_hand_struct.c \
				$(HOOK)expose_hook.c $(HOOK)key_hook.c $(HOOK)mouse_hook.c \
				$(KEYS)handle_keys.c $(KEYS)key_tab.c $(KEYS)key_space.c $(KEYS)key_m.c $(KEYS)key_left.c $(KEYS)key_right.c $(KEYS)key_w.c $(KEYS)key_s.c $(KEYS)key_a.c $(KEYS)key_d.c $(KEYS)key_e.c $(KEYS)key_esc.c $(KEYS)key_enter.c \
				$(GAME)update.c $(GAME)layout_home_screen.c $(GAME)layout_game_screen.c $(GAME)layout_map_screen.c $(GAME)display.c $(GAME)raycast.c $(GAME)minimap.c \
				$(DRAW)draw_rectangle.c \
				$(ANIM)animation_tools.c $(ANIM)animation_utils.c $(ANIM)animation_player_hand.c \
				$(TOOL)close.c $(TOOL)fps.c $(TOOL)image_helper.c $(TOOL)colors.c \
				$(PARS)parser.c $(PARS)pars_colours.c $(PARS)pars_errors.c $(PARS)pars_utils.c $(PARS)pars_map.c $(PARS)pars_texture.c \
				$(GNL)get_next_line.c $(GNL)get_next_line_utils.c

OBJ = $(SRC:.c=.o)

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
	./$(NAME) map.cub

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
