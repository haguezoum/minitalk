# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 17:33:34 by haguezou          #+#    #+#              #
#    Updated: 2023/03/01 17:09:03 by haguezou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = client server 
CLIENT = client
SERVER = server
CC = gcc
CFLAGS = -Wall -Wextra -Werror
rm = rm -rf

SRC_S = server.c
SRC_C = client.c 
HEADER = mnitalk.h
UTILITY = utility.c

all:$(NAME)

$(CLIENT): $(SRC_C)
	$(CC) $(CFLAGS) $(SRC_C) $(UTILITY) -o client
$(SERVER): $(SRC_S)
	$(CC) $(CFLAGS) $(SRC_S) $(UTILITY) -o server

clean:
	rm -rf *.o
fclean:
	rm -rf $(CLIENT) $(SERVER)
re: fclean all
