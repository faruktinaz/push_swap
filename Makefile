SRCS =	./srcs/main.c \
./srcs/rules.c \
./srcs/rules2.c \
./srcs/rules3.c \
./srcs/ftsort.c \
./srcs/ftsort2.c \
./srcs/find_steps.c \
./srcs/calculate_steps.c \
./srcs/check_functions.c \
./srcs/fsort_min.c \
./srcs/fsort_reverse.c \
./srcs/fsort_utils.c \

SRCSB = ./srcs_Bonus/checker.c \
./srcs_Bonus/rules_bonus.c \
./srcs_Bonus/rules_bonus_2.c \
./srcs_Bonus/rules_bonus_3.c \
./srcs_Bonus/check_rules.c \
./srcs_Bonus/split.c \
./srcs_Bonus/take_check_args.c \

NAME = push_swap
BONUS = checker
CC = gcc
CFLAGS =  -Wall -Wextra -Werror
LIBFT = ./library/libft/libft.a
FT_PRINTF = ./library/printf/libftprintf.a
GET_NEXT_LINE = ./srcs_Bonus/get_next_line/get_next_line.c ./srcs_Bonus/get_next_line/get_next_line_utils.c 
RM = rm -rf
LIBC = ar -rcs

all: ${NAME}

$(NAME): $(SRCS) $(FT_PRINTF) $(LIBFT)
	@gcc $(CFLAGS) $(SRCS) $(LIBFT) $(FT_PRINTF) -o $(NAME)
	@echo "-*-*-*-*-OK-*-*-*-*-"

bonus : $(SRCSB) $(FT_PRINTF) $(LIBFT) $(GET_NEXT_LINE)
	@gcc $(CFLAGS) $(SRCSB) $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) -o $(BONUS)
	@echo "-*-*-*-*-OK BONUS-*-*-*-*-"

$(FT_PRINTF):
	@make -C ./library/printf

$(LIBFT):
	@make -C ./library/libft

clean:

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C ./library/printf
	@make fclean -C ./library/libft

re: fclean all

.PHONY: all bonus clean fclean re 