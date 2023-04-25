# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agallet <agallet@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/14 14:03:53 by agallet           #+#    #+#              #
#    Updated: 2023/04/21 14:42:14 by agallet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = GCC
FLAGS = -Wall -Werrors -Wextra
INCL = -I ./libft -I ./libft/ft_printf
LIBS = -L ./libft -lft
SRCS = main.c 
SRCS_TEST = test.c
OBJS = $(SRCS:.c=.o)
OBJS_TEST = $(SRCS_TEST:.c=.o)
NAME = echo

%.o: %.c
	$(CC) $(INCL) -c $< -o $@

$(NAME): $(OBJS) ./libft/libft.a
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBS)

./libft/libft.a :
	make -C libft

all: $(NAME)

test : $(NAME) $(OBJS_TEST) ./libft/libft.a
	$(CC) $(FLAGS) -o test $(OBJS_TEST) $(LIBS)

clean :
	make clean -C libft
	rm *.o

fclean : clean
	make fclean -C libft
	rm $(NAME)

re : fclean all

.PHONY : all clean fclean re
