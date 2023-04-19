# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agallet <agallet@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 14:03:53 by agallet           #+#    #+#              #
#    Updated: 2023/04/14 14:04:02 by agallet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = GCC
FLAGS = -Wall -Werrors -Wextra
INCL = -I ./libft
LIBS = -L ./libft -lft
SRCS = main.c
OBJS = $(SRCS:.c=.o)
NAME = minishell

%.o: %.c
	$(CC) $(INCL) -c $< - o $@

$(NAME): $(OBJS) libs
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBS)

libs:
	make -C libft

all: $(NAME)

clean :
	make clean -C libft
	rm *.o

fclean : clean
	make fclean -C libft
	rm $(NAME)

re : fclean all

.PHONY : all clean fclean libs re
