NAME = libfractol.a
CC = clang
CFLAGS = -Wall -Wextra -Werror -c
LIB_PATH = ./libft
MI_PATH = ./minilibx
OBJDIR = ./obj
SRCDIR = ./src
BINDIR = ./bin
INCLUDE = ./include
LIB = ./lib
LIBFT = libft.a
REMOVE = rm -rf
MLX_FLAGS = -L. -lXext -L. -lX11

SRC_FILE += ft_picture.c ft_map.c ft_mandelbrot.c ft_cal_loop.c ft_mouse_hook.c
SRC_FILE += ft_color.c ft_julia.c
OBJFILE = $(SRC_FILE:.c=.o)
OBJECTS = $(addprefix $(OBJDIR)/, $(OBJFILE))

all: $(NAME)

$(NAME): $(OBJECTS)
	$(MAKE) -C $(LIB_PATH)
	$(MAKE) -C $(MI_PATH)
	cp $(LIB_PATH)/$(LIBFT) $(LIB)/$(NAME)
	ar rcs $(LIB)/$(NAME) $(OBJECTS)
	gcc ./apps/ft_main.c ./lib/libfractol.a ./minilibx/libmlx.a -L. -lXext -L. -lX11 -lm -o ./bin/fractol
#	-fsanitize=address
#	./bin/fractol

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(LIB) $(OBJDIR) $(BINDIR)
	$(CC) -g -c $< -I $(INCLUDE) -o $@

clean:
	$(REMOVE) $(OBJDIR)
	$(REMOVE) $(BINDIR)
	$(MAKE) clean -C $(LIB_PATH)
	$(MAKE) clean -C $(MI_PATH)

fclean: clean
	$(REMOVE) $(LIB)

re: fclean all
