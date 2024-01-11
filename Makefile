# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stribuzi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/04 11:30:57 by stribuzi          #+#    #+#              #
#    Updated: 2021/06/04 11:30:59 by stribuzi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS			=	ft_split.c \
					ft_strjoin.c \
					ft_strncmp.c \
					ft_lstadd_back.c \
					ft_lstnew.c \
					ft_lstlast.c \
					index.c \
					libft_1.c \
					commands.c \
					pipe.c \
					free_all.c \
					bonus.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

NAME			= pipex

%.o : %.c
	$(CC)  -c -o $@ $<

all:			$(NAME)

$(NAME):		 $(OBJS)
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re
