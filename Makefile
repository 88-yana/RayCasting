NAME = cub3D
CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -MP -O2
SRCDIR = src
OBJDIR = obj
SRC = \
	src/main.c \
	src/check_arg.c \
	src/input_file/check_map_size.c \
	src/input_file/check_map_surrounded.c \
	src/input_file/get_map.c \
	src/input_file/get_map_info.c \
	src/input_file/input_file.c \
	src/input_file/is_valid_map.c \
	src/input_file/is_valid_map_info.c \
	src/input_file/is_valid_rgb_number.c \
	src/input_file/set_map_info.c \
	src/init_game/hooks.c \
	src/init_game/init.c \
	src/init_game/load_images.c \
	src/init_game/load_player.c \
	src/calculation/calc.c \
	src/calculation/dir_to_angle.c \
	src/calculation/get_wall_height.c \
	src/calculation/is_out_of.c \
	src/calculation/measure_distance_to_wall.c \
	src/calculation/raycasting.c \
	src/calculation/walk_to_wall.c \
	src/calculation/walk_to_wall_utils.c \
	src/render/render.c \
	src/render/draw_back.c \
	src/render/draw_lines.c \
	src/render/draw_minimap.c \
	src/render/draw_player_on_minimap.c \
	src/render/draw_rays_on_minimap.c \
	src/render/draw_rays_on_screen.c \
	src/operation/collision.c \
	src/operation/collision_utils.c \
	src/operation/exit.c \
	src/operation/mouse.c \
	src/operation/keys.c \
	src/utils/gnl_wrapper.c \
	src/utils/handle_error.c \
	src/debug/print_game_iinfo.c \
	src/debug/print_input.c

OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LIBFTDIR = ./lib/libft
LIBFT_A = $(LIBFTDIR)/libft.a

MINILIBXDIR = ./lib/minilibx
MINILIBX = libmlx.dylib

MAPS = $(shell find map/normal/ -type f)
TEST_MAPS = $(shell find map/error/ -type f)

INCLUDE = -I ./include/ -I $(LIBFTDIR)/incs/ -I $(MINILIBXDIR)/

DEPS := ${addprefix ${OBJDIR}/, ${SRC:.c=.d}}
-include ${DEPS}

#: Print variables
PRINTF := printf
DEFAULT := \033[0;39m
BLUE := \033[0;94m
GREEN := \033[0;92m
RED := \033[0;91m
DEL := \033[2K
MOVE := \033[1F
CR := \033[1G

#: Make executable file.
all: $(OBJDIR) $(NAME)

$(NAME): $(OBJ) $(LIBFT_A) $(MINILIBX)
	$(CC) $(OBJ) $(LIBFT_A) $(MINILIBX) -o $(NAME)

$(OBJDIR):
	mkdir $(shell find $(SRCDIR) -type d | sed 's/^$(SRCDIR)/$(OBJDIR)/g')

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $<

$(LIBFT_A):
	$(MAKE) -C $(LIBFTDIR)

$(MINILIBX):
	$(MAKE) -C $(MINILIBXDIR)
	cp $(MINILIBXDIR)/$(MINILIBX) ./

#: Remove all object files.
clean:
	$(RM) -rf $(OBJDIR)
	$(RM) $(MINILIBX)
	$(MAKE) fclean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MINILIBXDIR)

#: Remove all object and executable files.
fclean: clean
	$(RM) $(NAME)

#: Remove and recompile all.
re: fclean all

#: Open error maps.
t: all
	@for map in ${TEST_MAPS} ; \
	do echo $$map ; ./${NAME} $$map ; echo "$?"; done
	@echo "${GREEN}----finish----${DEFAULT}"

#: Open normal maps.
p: all
	@for map in ${MAPS} ; \
	do echo $$map ; ./${NAME} $$map ; echo "$?"; done
	@echo "${GREEN}----finish----${DEFAULT}"

#: Check norminette.
norm:
	@${PRINTF} "${RED}\nChecking norm for ${NAME}...${DEFAULT}\n "
	@norminette ${SRCDIR} include/ lib/libft

# Check approved functions.
nm: $(NAME)
	@nm -u $(NAME) | grep -v -e 'mlx_' -e 'ft_' -e ' __' -e ' X'

#: Display all commands.
help:
	@grep -A1 -E "^#:" Makefile \
	| grep -v -- -- \
	| sed 'N;s/\n/###/' \
	| sed -n 's/^#: \(.*\)###\(.*\):.*/\2###\1/p' \
	| sed -e 's/^/make /' \
	| column -t -s '###'

.PHONY : all clean fclean re t p norm nm help