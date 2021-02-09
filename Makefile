# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stnineta <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 13:12:23 by stnineta          #+#    #+#              #
#    Updated: 2021/02/08 11:10:54 by stnineta         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ${wildcard ./srcs/*.c}
OBJS	= ${SRCS:.c=.o}
INCL	= include
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= BSQ

.c.o :	
			${CC} -I ${INCL} ${CFLAGS} -c $< -o ${<:.c=.o}

all :		${OBJS}
			${CC} -o ${NAME} ${OBJS}

${NAME} :	all

clean :
			rm -f ${OBJS}

fclean :	clean
			rm -f ${NAME}

re :		fclean all
	
.PHONY :	all ${NAME} clean fclean re