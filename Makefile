SRCS = srcs/instruction.c srcs/instructions_rotates.c

SRCS_BONUS	= 
CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -Iincludes
NAME = push_swap
NAME_BONUS = push_swap_bonus
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

bonus:	$(OBJS_BONUS)
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
