SRCS = srcs/instruction.c srcs/instructions_rotates.c srcs/initialisation.c srcs/algorithme.c srcs/error_managing.c srcs/utils.c srcs/main.c

SRCS_BONUS	= srcs_bonus/main.c srcs_bonus/initialisation.c srcs_bonus/utils.c srcs_bonus/instruction.c srcs_bonus/instructions_rotates.c \
srcs_bonus/error_managing.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -Iincludes
NAME = push_swap
NAME_BONUS = checker
RM = rm -f
LIBS = -Llibft -lft

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS)
			make -C libft
			$(CC) -o $(NAME) $(OBJS) $(LIBS)
			
bonus: $(NAME_BONUS)

$(NAME_BONUS):	$(OBJS_BONUS)
		make -C libft
		$(CC) -o $(NAME_BONUS) $(OBJS_BONUS) $(LIBS)

debug: CFLAGS+=-g
debug: re

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)
		make clean -C libft

fclean: clean
		$(RM) $(NAME) $(NAME_BONUS)
		make fclean -C libft

re: fclean all

.PHONY: all fclean clean re debug bonus
