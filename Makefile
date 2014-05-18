# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jponcele <jponcele@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 12:29:52 by jponcele          #+#    #+#              #
#    Updated: 2014/05/18 15:20:41 by jponcele         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_irc

S_NAME = serveur

S_DIRSRC = ./s_srcs/
S_DIROBJ = ./s_obj/

S_SRC = main.c

S_OBJ = $(S_SRC:.c=.o)

S_DIROBJS = $(addprefix $(S_DIROBJ), $(S_OBJ))

C_NAME = client

C_DIRSRC = ./c_srcs/
C_DIROBJ = ./c_obj/

C_SRC = main.c

C_OBJ = $(C_SRC:.c=.o)

C_DIROBJS = $(addprefix $(C_DIROBJ), $(C_OBJ))

LFT = -L ./libft/ -lft

CC = clang
CFLAGS = -Wall -Werror -Wextra -g -O3

HEAD = -I ./includes -I ./libft/includes/

all: $(NAME)

$(NAME): $(S_NAME) $(C_NAME)

$(S_NAME): $(S_DIROBJS)
	@$(MAKE) -C ./libft
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$(S_NAME)'
	@$(CC) $(CFLAGS) -o $@ $^ $(HEAD) $(LFT)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$(S_NAME)'

$(S_DIROBJ)%.o: $(S_DIRSRC)%.c
	@mkdir -p s_obj
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@

$(C_NAME): $(C_DIROBJS)
	@$(MAKE) -C ./libft
	@printf 'Compiling ./%s binaries : [\033[32mDONE\033[0m]\n' '$(C_NAME)'
	@$(CC) $(CFLAGS) -o $@ $^ $(HEAD) $(LFT)
	@printf 'Compiling ./%s : [\033[32mDONE\033[0m]\n' '$(C_NAME)'

$(C_DIROBJ)%.o: $(C_DIRSRC)%.c
	@mkdir -p c_obj
	@$(CC) $(CFLAGS) -c $^ $(HEAD) -o $@


clean:
	@rm -rf $(S_DIROBJ) $(C_DIROBJ)
	@printf 'Clean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) clean -C ./libft

fclean: clean
	@rm -rf $(S_NAME) $(C_NAME)
	@printf 'Fclean %s : [\033[32mDONE\033[0m]\n' '$(NAME)'
	@$(MAKE) fclean -C ./libft

re : fclean all

.PHONY: all clean fclean re
