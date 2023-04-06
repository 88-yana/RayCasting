CC = cc
CFLAGS = -Wall -Werror -Wextra -MMD -MP
INCLUDE = -I ./include/ -I $(LIBFTDIR)/incs/ -I $(MINILIBXDIR)/

SRCDIR = src
OBJDIR = obj
SRC = $(shell find $(SRCDIR) -type f -name *.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

LIBFTDIR = ./lib/libft
LIBFT_A = $(LIBFTDIR)/libft.a

MINILIBXDIR = ./lib/minilibx
MINILIBX = libmlx.dylib

TEST_MAPS = $(shell find test)
DEFAULT := \033[0;39m
BLUE := \033[0;94m
GREEN := \033[0;92m

NAME = cub3D

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

clean:
	$(RM) -rf $(OBJDIR)
	$(RM) $(MINILIBX)
	$(MAKE) fclean -C $(LIBFTDIR)
	$(MAKE) clean -C $(MINILIBXDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

t: all
	@for map in ${TEST_MAPS} ; \
	do echo $$map ; ./${NAME} $$map ; echo "$?"; done
	@echo "${GREEN}----finish----${DEFAULT}"

.PHONY : all clean fclean re t test