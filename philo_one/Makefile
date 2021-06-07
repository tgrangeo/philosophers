HEADER =	philo_one.h

SRCS =	srcs/libft.c srcs/utils.c srcs/threads.c srcs/ft_eat.c srcs/message.c

NAME	=	philo_one

RM		=	rm -f

FLAGS	=	-Wall -Wextra -Werror -ggdb

OBJS	=	${SRCS:.c=.o}

# TODO zerzerazer
COMP = clang # or gcc

.PHONY: clean fclean re

%.o: %.c 
	$(COMP) $(FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(COMP) $(FLAGS) -o $(NAME) srcs/main.c $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all