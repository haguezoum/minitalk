# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haguezou <haguezou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 17:33:34 by haguezou          #+#    #+#              #
#    Updated: 2023/02/22 17:49:33 by haguezou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=minitalk.a
CC=gcc
SRC=client.c server.c
CFLAGS=Wall Wextra Werror
OBJ=$(SRC:.c=.o)
HEADER=mnitalk.h

all:
