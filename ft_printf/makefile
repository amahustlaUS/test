# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dchantse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 12:38:10 by dchantse          #+#    #+#              #
#    Updated: 2019/01/05 17:17:16 by anerus           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf

all: $(NAME)

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@clang -I libft/ -o analysis.o -c analysis.c -g
	@clang -I libft/ -o else.o -c else.c -g
	@clang -I libft/ -o ft_printf.o -c ft_printf.c -g
	@clang -I libft/ -o main.o -c main.c -g
	@clang -I libft/ -o handle_sign.o -c handle_sign.c -g
	@clang -o ft_printf handle_sign.o ft_printf.o analysis.o else.o main.o -I libft/ -L libft/ -lft -g
clean:
	@rm -rf ft_printf.o main.o analysis
	@make -C libft/ clean
fclean: clean
	@rm -rf ft_printf
	@make -C libft/ fclean
re: fclean all
