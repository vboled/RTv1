

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

#GCC = gcc -Wall -Wextra -Werror

GCC = gcc
NAME = RTv1
SRCS = main.c \
	   get_next_line.c \
	   fill_scene.c\
	   add_obj.c\
	   window_work.c\
	   tracer.c\
	   add_light.c\
	   vec_operation.c\
	   intersection.c

HEAD = -I$(INCDIR)

ifeq ($(OS),Windows_NT)
	detected_OS := Windows
else
	detected_OS := $(shell uname)
endif
ifeq ($(detected_OS),Linux)
	MAKES := ./libs/libft/libft.a  libs/minilibx/libmlx.a
	LIBMAKE := libs/minilibx
	LIB :=  -L libs/libft -lft -L libs/minilibx -lmlx_Linux -lXext -lX11 -lm
	HEAD += -I./libs/minilibx/
endif
ifeq ($(detected_OS),Darwin) 
	MAKES = ./libs/libft/libft.a ./libs/minilibx_macos/libmlx.a
	LIBMAKE := libs/minilibx_macos
	LIB := -L libs/libft -lft -L libs/minilibx_macos -lmlx -framework OpenGL -framework Appkit
	HEAD += -I./libs/minilibx_macos/
endif

OBJS = $(addprefix $(OBJDIR), $(SRCS:.c=.o))
DEPENDS = $(addprefix $(OBJDIR), $(SRCS:.c=.d))

.PHONY: clean fclean re
all: $(NAME) 

$(OBJDIR)%.o: $(SRCDIR)%.c
	mkdir -p $(OBJDIR)
	$(GCC) -MD -o $@ -c $(HEAD) $<

$(MAKES):
	make -C  libs/libft
	make -sC  $(LIBMAKE)

-include $(DEPENDS)

$(NAME): $(MAKES) $(OBJS)
	$(GCC) $(OBJS) $(LIB) $(HEAD) -o $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(DEPENDS)
	make -C libs/libft clean

fclean: clean
	rm -f $(NAME)
	make -C libs/libft fclean
	make -C $(LIBMAKE) clean

re: fclean all
