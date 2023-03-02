# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 17:33:34 by haguezou          #+#    #+#              #
#    Updated: 2023/03/02 12:30:30 by haguezou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client server 
CLIENT = client
SERVER = server
CLIENT_BONUS = client_bonus
SERVER_BONUS = server_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
rm = rm -rf

SRC_S = server.c
SRC_C = client.c 
SRC_B_S = server_bonus.c
SRC_B_C = client_bonus.c
HEADER = mnitalk.h
UTILITY = utility.c utility_helper.c

all:$(NAME)

$(CLIENT): $(SRC_C)
	$(CC) $(CFLAGS) $(SRC_C) $(UTILITY) -o client

$(SERVER): $(SRC_S)
	$(CC) $(CFLAGS) $(SRC_S) $(UTILITY) -o server

bonus: $(CLIENT_BONUS) $(SERVER_BONUS)

$(CLIENT_BONUS):
	$(CC) $(CFLAGS) $(SRC_B_C) $(UTILITY) -o client_bonus
$(SERVER_BONUS):
	$(CC) $(CFLAGS) $(SRC_B_S) $(UTILITY) -o server_bonus

clean:
	rm -rf $(NAME) $(CLIENT_BONUS) $(SERVER__BONUS)
fclean:
	rm -rf $(NAME) $(CLIENT_BONUS) $(SERVER_BONUS)
re: fclean all
