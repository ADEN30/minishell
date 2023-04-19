# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agallet <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 15:26:53 by agallet           #+#    #+#              #
#    Updated: 2023/03/13 15:53:16 by agallet          ###   ########.fr        #
#                                                                              #
# ****************************************************************************  
CFLAGS = -Wall -Werror -Wextra
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_printf/ft_printf_variable.c ft_printf/ft_printf.c ft_printf/ft_printfstr.c ft_printf/ft_printf_nb.c ft_printf/ft_printf_p.c ft_printf/ft_putnbr_base.c ft_printf/ft_putunbr_base.c ft_strlen2d.c 
HEADERS = -I ./ft_printf
OBJETS = $(SRCS:.c=.o) 
NAME = libft.a

%.o : %.c 
	$(CC) $(HEADERS) -c $< -o $@

all : $(NAME)

$(NAME) : $(OBJETS)
	ar cr $(NAME) $(OBJETS)

clean :
	rm -f $(OBJETS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re
