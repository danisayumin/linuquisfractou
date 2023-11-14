NAME	=	fractoys


CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -O3
DEBUG	=	-g3 -fsanitize=address -DDEBUG_FLAG=1 #-fsanitize=address
RM		=	rm -f

SRC		=	main.c \
			controls.c \
			fractol.c \
			mandelbrot.c

COLOR_INFO = \033[1;36m
COLOR_SUCCESS = \033[1;32m
COLOR_RESET = \033[0m

EMOJI_INFO = 🌈
EMOJI_SUCCESS = 🎉
EMOJI_CLEAN = 🧹
EMOJI_RUN = 🚀

SRC		:=	$(SRC:%=src/%)
OBJ		=	$(SRC:%.c=%.o)

INC_DIR	=	-Isrc

LIBFLAGS 	+=	-L.


LIBFLAGS	+= -lmlx42
MLX42		=	libmlx42.a
MLX42_DIR	=	MLX42
LIBRARYS	+=	MLX42.lib
INC_DIR		+=	-I$(MLX42_DIR)/include/MLX42
ifeq ($(shell uname), Darwin)
#LIBFLAGS	+= -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
LIBFLAGS	+= -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/"
else
LIBFLAGS	+= -ldl -lglfw -pthread -lm
endif


# libs: $(COMPILE) $(LIBRARYS)
# 	$(MAKE) $(NAME)

all: $(NAME)

# debug: 
# 	$(MAKE) DEBUG_FLAG=1 libs

# $(LIBRARYS): %.lib:
# 	@echo "00000000000$($*_DIR)"
# 	cmake -C $($*_DIR) $(LIB_DEBUG_FLAG)
# 	@cp -p $($*_DIR)/$($*) .

$(NAME): $(OBJ)
	@printf "$(COLOR_INFO)$(EMOJI_INFO)  Compiling $(NAME)...$(COLOR_RESET)\t"
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFLAGS) $(INC_DIR)
	@sleep 0.25
	@printf "✅\n"

$(MLX):
	@printf "$(COLOR_INFO)$(EMOJI_INFO)  Initializing submodules...$(COLOR_RESET)\t"
	@git submodule update --init --recursive
	@sleep 0.25
	@printf "✅\n"
	@printf "$(COLOR_INFO)$(EMOJI_INFO)  Building MLX42...$(COLOR_RESET)\t\t"
	@cmake -S MLX42 -B MLX42/build -DGLFW_FETCH=1
	@cmake --build MLX42/build --parallel
	@sleep 0.25
	@printf "✅\n"

norm:
	@norminette $(SRCS) incl/fractol.h libft

$(OBJ): %.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< $(INC_DIR)

clean:
	$(RM) $(OBJ)

fclean: clean $(LIBRARYS:%=%.clean)
	$(RM) $($(LIBRARYS:%.lib=%))
	$(RM) $(NAME)

$(LIBRARYS:%=%.clean): %.lib.clean:
	$(RM) $($*)
	@$(MAKE) -C $($*_DIR) fclean
	$(RM) $*.lib

re: fclean
	$(MAKE) libs

.PHONY: all clean fclean re