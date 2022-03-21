# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgainza- <jgainza-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 11:46:30 by jgainza-          #+#    #+#              #
#    Updated: 2022/03/20 17:57:58 by jofernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a
CC		= gcc
RM		= rm -f
CFLAGS	= -Wall -Wextra -Werror -I. #-fsanitize=address -g3

FILES	=	ft_isalnum ft_isprint ft_memcmp  ft_putchar_fd ft_split \
			ft_strlcat ft_strncmp ft_substr ft_atoi ft_isalpha \
			ft_itoa ft_memcpy  ft_putendl_fd ft_strchr  ft_strlcpy \
			ft_strnstr ft_tolower ft_bzero   ft_isascii ft_memccpy \
			ft_memmove ft_putnbr_fd  ft_strdup  ft_strlen  ft_strrchr \
			ft_toupper ft_calloc  ft_isdigit ft_memchr  ft_memset  ft_strstr \
			ft_putstr_fd  ft_strjoin ft_strmapi ft_strtrim ft_strcmp ft_union \
			ft_strchrint ft_putstr_fd2 ft_tolower_chr ft_strtrim_begin \
			ft_printf/extra/ft_pitoa \
			ft_printf/extra/ft_putstr_int \
			ft_printf/extra/write_nbr \
			ft_printf/extra/ft_putchar_int \
			ft_printf/extra/ft_hex_itoa \
			ft_printf/extra/write_hex_caps \
			ft_printf/extra/write_char \
			ft_printf/extra/write_pointer \
			ft_printf/extra/ft_strupper \
			ft_printf/extra/ft_putnbr_base_int \
			ft_printf/extra/ft_putnbr_uint \
			ft_printf/extra/write_hex \
			ft_printf/extra/write_string \
			ft_printf/extra/ft_putnbr_int \
			ft_printf/extra/write_int \
			ft_printf/srcs/ft_printf \
			ft_lstadd_back ft_lstadd_front ft_lstclear \
			ft_lstdelone ft_lstiter ft_lstlast \
			ft_lstmap ft_lstnew ft_lstsize

SRCS = $(addsuffix .c, $(FILES))
OBJS = $(addsuffix .o, $(FILES))

all:	$(NAME)

.c.o:	$(SRCS)
		$(CC) $(CFLAGS) -c $^ -o $@

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS) $(BONUS_OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:			all clean fclean re

