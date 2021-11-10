NAME = fractol
CC = clang
CFLAGS = -Wall -Wextra -Werror
APP = ./apps
LIB_PATH = ./libft
LIBFT = libft.a
MI_PATH = ./minilibx
OBJDIR = ./obj
SRCDIR = ./src
INCLUDE = ./include
REMOVE = rm -rf
MLX_FLAGS = -lXext -lX11

SRC_FILE += ft_mandelbrot.c ft_mouse_hook.c ft_burningship.c
SRC_FILE += ft_color.c ft_display_usage.c ft_init.c ft_julia.c
SRC_FILE += ft_parameter_julia.c
OBJFILE = $(SRC_FILE:.c=.o)
OBJECTS = $(addprefix $(OBJDIR)/, $(OBJFILE))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIB_PATH)
	$(MAKE) -C $(MI_PATH)
	$(CC) $(APP)/ft_main.c -o $(NAME) $(OBJECTS) $(LIB_PATH)/$(LIBFT) \
	$(MI_PATH)/libmlx.a -lm $(MLX_FLAGS)
#	-fsanitize=address
#	./bin/fractol

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -I $(INCLUDE) -o $@

bonus: all

clean:
	$(MAKE) clean -C $(LIB_PATH)
	$(MAKE) clean -C $(MI_PATH)

fclean: clean
	$(REMOVE) $(OBJDIR)
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: bonus clean fclean re
