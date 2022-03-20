# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgainza- <jgainza-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/02 11:46:30 by jgainza-          #+#    #+#              #
#    Updated: 2022/03/18 19:36:59 by jofernan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	ft_isalnum.c ft_isprint.c ft_memcmp.c  ft_putchar_fd.c ft_split.c \
					ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
					ft_itoa.c ft_memcpy.c  ft_putendl_fd.c ft_strchr.c  ft_strlcpy.c \
					ft_strnstr.c ft_tolower.c ft_bzero.c   ft_isascii.c ft_memccpy.c \
					ft_memmove.c ft_putnbr_fd.c  ft_strdup.c  ft_strlen.c  ft_strrchr.c \
					ft_toupper.c ft_calloc.c  ft_isdigit.c ft_memchr.c  ft_memset.c  ft_strstr.c \
					ft_putstr_fd.c  ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_strcmp.c ft_union.c \
					ft_strchrint.c ft_putstr_fd2.c ft_tolower_chr.c ft_strtrim_begin.c \
					ft_printf/extra/ft_pitoa.c \
					ft_printf/extra/ft_putstr_int.c \
					ft_printf/extra/write_nbr.c \
					ft_printf/extra/ft_putchar_int.c \
					ft_printf/extra/ft_hex_itoa.c \
					ft_printf/extra/write_hex_caps.c \
					ft_printf/extra/write_char.c \
					ft_printf/extra/write_pointer.c \
					ft_printf/extra/ft_strupper.c \
					ft_printf/extra/ft_putnbr_base_int.c \
					ft_printf/extra/ft_putnbr_uint.c \
					ft_printf/extra/write_hex.c \
					ft_printf/extra/write_string.c \
					ft_printf/extra/ft_putnbr_int.c \
					ft_printf/extra/write_int.c \
					ft_printf/srcs/ft_printf.c
OBJS			= $(SRCS:.c=.o)

BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c
BONUS_OBJS		= $(BONUS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I. -fsanitize=address -g3

NAME			= libft.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus

