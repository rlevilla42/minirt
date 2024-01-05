# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rlevilla <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 15:01:27 by rlevilla          #+#    #+#              #
#    Updated: 2024/01/03 20:10:17 by rlevilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c draw_test.c utils.c ft_atod.c parsing.c parsing_scene.c hook.c vect_math.c
OBJS	= ${SRCS:.c=.o}

LIBFT = libft

// MEMEORY_FLAG = -fsanitize=address

CFLAGS	= gcc -Wall -Wextra -Werror

RM	= rm -f

OPTIONS	= -I

NAME	= miniRT

all:	${NAME}

$(NAME): $(OBJS)
	$(MAKE) -C minilibx_macos/
	$(MAKE) -C libft/
	$(CFLAGS) -fsanitize=address $(OBJS) -L./libft/ -lft -L./minilibx_macos -lmlx -framework OpenGL -framework AppKit -o $(NAME)

.c.o:
			${CFLAGS} -I./libft -I./minilibx_macos -c $< -o ${<:.c=.o}

${LIBFT}:
		${MAKE} -C /libft/

clean:
			${MAKE} -C libft/ clean
			${MAKE} -C minilibx_macos/ clean
			${RM} ${OBJS}

fclean:	clean
				${RM} ${NAME}
				${MAKE} -C libft/ fclean
				${MAKE} -C minilibx_macos/ clean
re:	fclean all

.PHONY: clean fclean all re
