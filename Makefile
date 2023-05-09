all:
	gcc -Wall -Wextra -Werror main.c rules.c ./printf/libftprintf.a ./libft/libft.a -o push_swap
