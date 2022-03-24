NAME	= minishell
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror -I/Users/$(USER)/.brew/opt/readline/include -ggdb3 #-fsanitize=address -g3 
LDFLAGS	= -lreadline -L /Users/$(USER)/.brew/opt/readline/lib 
GREEN	= \033[0;32m
RED		= \033[0;31m
RESET	= \033[0m

FUNC	= srcs/main \
		  srcs/builtins/pwd \
		  srcs/builtins/echo \
		  srcs/builtins/env \
		  srcs/builtins/cd \
		  srcs/builtins/export/export \
		  srcs/builtins/export/additions \
		  srcs/builtins/export/additions2 \
		  srcs/builtins/unset \
		  srcs/builtins/exit \
		  srcs/utils/split/split \
		  srcs/utils/split/split_pipe \
		  srcs/utils/split/split_utils \
		  srcs/utils/split/quote/quote_control \
		  srcs/utils/split/quote/additions \
		  srcs/utils/expand \
		  srcs/utils/free  \
		  srcs/utils/ft_fork \
		  srcs/utils/ft_get_path \
		  srcs/utils/ft_builtins \
		  srcs/utils/redirections/ft_redirections \
		  srcs/utils/redirections/ft_helpredis \
		  srcs/utils/redirections/additions \
		  srcs/utils/dup_to

SRC		= $(addsuffix .c, $(FUNC))
OBJ		= $(addsuffix .o, $(FUNC))

all : $(NAME)

.c.o	: $(SRC)
	@$(CC) $(CFLAGS) -c $^ -o $@ 

$(NAME) : $(OBJ)
	@$(MAKE) -s -C srcs/libft
	@mv srcs/libft/libft.a .	
	@$(CC) $(CFLAGS) $(LDFLAGS) $^ libft.a -o $@
	@$(RM) *.dSYM
	@echo "$(GREEN)make done$(RESET)"

clean	:
	@$(RM) $(OBJ) *.dSYM
	@$(RM) .DS_Store */.DS_Store */*/.DS_Store */*/*/.DS_Store
	@$(RM) *.o */*/o */*/*.o */*/*/*.o
	@$(RM) srcs/libft/*.o srcs/libft/ft_printf/extra/*.o srcs/libft/ft_printf/srcs/*.o
	@echo "$(RED)clean done$(RESET)"

fclean	: clean
	@$(RM) $(NAME)
	@$(RM) libft.a
	@echo "$(RED)fclean done$(RESET)"

re		: fclean all

.PHONY	: all clean fclean re
