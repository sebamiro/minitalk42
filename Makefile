# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smiro <smiro@student.42barcelona>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 09:41:32 by smiro             #+#    #+#              #
#    Updated: 2022/11/10 11:01:21 by smiro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT			=	client
SERVER			=	server

CLIENT_SRC		=	client.c
SERVER_SRC		=	server.c

Lib_DIR			=	includes/libft
Lib				=	$(Lib_DIR)/libft.a
Printf_DIR		=	includes/printf
Printf			=	$(Printf_DIR)/libftprintf.a

RM				=	rm -f
CFALGS			=	-Wall -Wextra -Werror -I /includes

all:
	@$(MAKE) -sC $(Lib_DIR)
	@$(MAKE) -sC $(Printf_DIR)
	@$(MAKE) $(CLIENT)
	@$(MAKE) $(SERVER)

$(CLIENT): $(CLIENT_SRC)
	@$(CC) $(CFLAGS) $(CLIENT_SRC) $(Lib) $(Printf) -o $(CLIENT)

$(SERVER): $(SERVER_SRC)
	@$(CC) $(CFLAGS) $(SERVER_SRC) $(Lib) $(Printf) -o $(SERVER)

clean:
	@$(MAKE) clean -sC $(Lib_DIR)
	@$(MAKE) clean -sC $(Printf_DIR)

fclean:
	@$(MAKE) clean
	@$(RM) $(CLIENT) $(SERVER)

re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY: all clean flclean re bonus
