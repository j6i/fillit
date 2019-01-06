# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschroed <mschroed@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/28 11:44:33 by mschroed          #+#    #+#              #
#    Updated: 2019/01/05 20:34:40 by mschroed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c mino_reader.c new_list.c list_append.c valid_shape.c map.c place.c cuter.c solved.c mino_len.c

$(NAME): $(SRC)
	make -C libft
	clang -o $(NAME) -g $(SRC) -I libft/includes -L libft/ -lft

all: $(NAME)

clean:
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

