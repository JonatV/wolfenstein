# Wolfenstein Makefile

# Compiler Settings
NAME = wolfenstein
SHELL := /bin/zsh

# Paths
INCPATH		=	./
MLX_PATH	=	minilibx_linux/
SRCS_PATH	=	sources/
LIBFT_PATH	=	./libft/
LIBFT		=	$(LIBFT_PATH)libft.a

# Source Directories
INIT		=	init/
HOOK		=	hook/
GAME		=	game/
KEYS		=	keys/
DRAW		=	drawing_tools/
PARS		=	parsing/
GNL			=	gnl/
ANIM		=	animation/
TOOL		=	tools/

# Color Definitions
GREEN   = \033[0;32m
BLUE    = \033[0;34m
YELLOW  = \033[0;33m
MAGENTA = \033[0;35m
CYAN    = \033[0;36m
RESET   = \033[0m

# Compilation Flags
CC			=	clang
CFLAGS 		= -Wall -Wextra -Werror -fsanitize=address -g $(INCS)
LDFLAGS 	= -fsanitize=address -g $(LIBS)

# Include Paths
INCLUDES	=	$(MLX_PATH)mlx.h \
				wolfenstein.h

INCS		=	-I./ -I$(LIBFT_PATH)includes
LIBS		=	$(LIBFT) \
				minilibx_linux/libmlx_Linux.a \
				-Lminilibx_linux -lmlx -lXext -lX11 -lm

# Source Files
SRC			=	main.c \
				optimization.c \
				$(INIT)init_project.c $(INIT)init_game_struct.c $(INIT)init_window_struct.c $(INIT)init_map_struct.c $(INIT)init_player_struct.c $(INIT)init_keys_struct.c $(INIT)init_hooks_logics.c $(INIT)init_xpm_images.c $(INIT)init_animation_struct.c $(INIT)init_pars_struct.c $(INIT)init_animation_minimap_struct.c $(INIT)init_animation_hand_struct.c \
				$(HOOK)expose_hook.c $(HOOK)key_hook.c $(HOOK)mouse_hook.c \
				$(KEYS)handle_keys.c $(KEYS)key_tab.c $(KEYS)key_space.c $(KEYS)key_m.c $(KEYS)key_left.c $(KEYS)key_right.c $(KEYS)key_w.c $(KEYS)key_s.c $(KEYS)key_a.c $(KEYS)key_d.c $(KEYS)key_e.c $(KEYS)key_esc.c $(KEYS)key_enter.c \
				$(GAME)update.c $(GAME)layout_home_screen.c $(GAME)layout_game_screen.c $(GAME)layout_map_screen.c $(GAME)display.c $(GAME)raycast.c $(GAME)minimap.c \
				$(DRAW)draw_rectangle.c \
				$(ANIM)animation_tools.c $(ANIM)animation_utils.c \
				$(TOOL)close.c $(TOOL)fps.c $(TOOL)image_helper.c $(TOOL)colors.c \
				$(PARS)parser.c $(PARS)pars_colours.c $(PARS)pars_errors.c $(PARS)pars_utils.c $(PARS)pars_map.c $(PARS)pars_texture.c \
				$(GNL)get_next_line.c $(GNL)get_next_line_utils.c

OBJ = $(SRC:.c=.o)

# Default target
all: libft_compile $(NAME)

# Libft compilation
libft_compile:
	@$(MAKE) -C $(LIBFT_PATH)

# Create Progress Script
define PROGRESS_SCRIPT
#!/bin/zsh

# Improved Cube Frames with Better Animation
cube_frames=(
    "    +------+.
    |\\`.    | \\`.
    |  \\`+--+---+ 
    |   |  |   |
    +---+--+.  |
     \\`. |    \\`.|
       \\`+------+"
    
    "    +------+
    |\\     |\\ 
    | +----+-+ 
    | |    | |
    +-+----+ |
     \\|     \\|
      +------+"
    
    "    +------+
    |      |
    +------+
    |      |
    +------+
    |      |
    +------+"
    
    "      +------+
     /|     /|
    +-+----+ |
    | |    | |
    | +----+-+
    |/     |/ 
    +------+"

    "       .+------+
     .' |    .'|
    +---+--+'  |
    |   |  |   |
    |  .+--+---+
    |.'    | .'
    +------+'"

    "      +------+
     /|     /|
    +-+----+ |
    | |    | |
    | +----+-+
    |/     |/ 
    +------+"

    "    +------+
    |      |
    +------+
    |      |
    +------+
    |      |
    +------+"

    "    +------+
    |\\     |\\ 
    | +----+-+ 
    | |    | |
    +-+----+ |
     \\|     \\|
      +------+"

      "    +------+.
    |\\`.    | \\`.
    |  \\`+--+---+ 
    |   |  |   |
    +---+--+.  |
     \\`. |    \\`.|
       \\`+------+"
)

# Input parameters
OBJ_FILES=("$$@")
total=$${#OBJ_FILES[@]}

# Color definitions
YELLOW='\033[0;33m'
GREEN='\033[0;32m'
RESET='\033[0m'

# Compilation function
compile_with_progress() {
    for ((count=0; count<total; count++)); do
        file="$${OBJ_FILES[count]}"
        percent=$$((100 * (count + 1) / total))
        frame=$$((count % 9))
        
        # Create progress bar
        bar=$$(printf "%0.s#" $$(seq 1 $$((percent / 2))))
        spaces=$$(printf "%0.s " $$(seq 1 $$((50 - percent / 2))))
        
        # Clear screen and print cube with progress
        printf "\033c"
        printf "$${YELLOW}Wolfenstein Compilation:$${RESET} [%-50s] %d%%\n\n%s\n" "$$bar" "$$percent" "$${cube_frames[frame]}"
        
        # Actual compilation
        $(CC) $(CFLAGS) -c $$(echo "$$file" | sed "s/\.o$$/.c/") -o "$$file"
        
        # Small delay to make animation visible
        sleep 0.05
    done
    
    printf "\n$${GREEN}✅ Compilation Complete!$${RESET}\n"
}

# Run compilation with progress
compile_with_progress "$$@"
endef


# Export the script creation
export PROGRESS_SCRIPT

# Build project with cube progress
$(NAME): libft_compile $(OBJ)
	@echo "$$PROGRESS_SCRIPT" > cube-progress.sh
	@chmod +x cube-progress.sh
	@./cube-progress.sh $(OBJ)
	@$(CC) $(OBJ) $(LIBFT) -o $@ $(LDFLAGS)
	@printf "$(MAGENTA)🚀 Wolfenstein 3D Ready!$(RESET)\n"
	@rm cube-progress.sh

# Compile object files
%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean operations
clean:
	@$(MAKE) --no-print-directory clean -C $(LIBFT_PATH)
	@rm -f $(OBJ)
	@printf "$(YELLOW)🧹 Cleaned object files$(RESET)\n"

fclean: clean
	@$(MAKE) --no-print-directory fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)
	@printf "$(YELLOW)🗑️  Removed executable$(RESET)\n"

re: fclean all

# Phony targets
.PHONY: all clean fclean re libft_compile