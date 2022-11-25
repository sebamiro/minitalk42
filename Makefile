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

BONUS_CLIENT	=	client_bonus
BONUS_SERVER	=	server_bonus

BONUS_CLIENT_SRC	=	client_bonus.c
BONUS_SERVER_SRC	=	server_bonus.c

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

bonus:
	@$(MAKE) -sC $(Lib_DIR)
	@$(MAKE) -sC $(Printf_DIR)
	@$(MAKE) $(BONUS_CLIENT)
	@$(MAKE) $(BONUS_SERVER)

$(BONUS_CLIENT): $(BONUS_CLIENT_SRC)
	@$(CC) $(CFLAGS) $(BONUS_CLIENT_SRC) $(Lib) $(Printf) -o $(BONUS_CLIENT)

$(BONUS_SERVER): $(BONUS_SERVER_SRC)
	@$(CC) $(CFLAGS) $(BONUS_SERVER_SRC) $(Lib) $(Printf) -o $(BONUS_SERVER)

clean:
	@$(MAKE) clean -sC $(Lib_DIR)
	@$(MAKE) clean -sC $(Printf_DIR)

fclean:
	@$(MAKE) clean
	@$(RM) $(CLIENT) $(SERVER) $(BONUS_CLIENT) $(BONUS_SERVER)

re:
	@$(MAKE) fclean
	@$(MAKE)

.PHONY: all clean flclean re bonus
