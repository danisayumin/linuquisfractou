# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 20:22:35 by dsayumi-          #+#    #+#              #
#    Updated: 2023/10/19 22:12:18 by dsayumi-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = fractol
LIBMLX    = MLX42
FRACTOL    = fractol.h
CFLAGS    = -Wextra -Wall -Werror -Wunreachable-code -Ofast -I$(FRACTOL)

HEADERS    = -I $(LIBMLX)/include -I ./libft
LIBS    = $(LIBMLX)/fractol/libmlx42.a -ldl -lglfw -pthread -lm
LIBFT    = ./libft
SRCS    = fractol.c
OBJS    = ${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/fractol && make -C $(LIBMLX)/fractol -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

$(NAME): $(OBJS)
	@make -C $(LIBFT) --silent
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) ./libft/libft.a -o $(NAME)

clean:
	@make clean -C $(LIBFT) --silent
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/fractol

fclean: clean
	@make fclean -C $(LIBFT) --silent
	@rm -rf $(NAME)

re: clean all