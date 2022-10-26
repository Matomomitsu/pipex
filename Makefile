# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 21:49:45 by mtomomit          #+#    #+#              #
#    Updated: 2022/09/29 20:37:01 by mtomomit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC		= pipex
NAME		= ./bin/pipex
NAME_BONUS	= ./bin/pipex_bonus
LIBFT		= libft.a
PIPEX		= ./incs/pipex.a
PIPEX_BONUS	= ./incs/pipex_bonus.a
BIN			= ./bin
LIBFT_PATH  = $(PIPEX_PATH)/libft
PIPEX_PATH	= $(shell pwd)

SRC 		= ./srcs/pipex.c \
				./srcs/exec.c \
				./srcs/init_cmds.c \
				./srcs/error.c \
				./srcs/argument_parser.c \
				./srcs/argument_parser2.c \

SRC_BONUS	= ./srcs_bonus/pipex_bonus.c \
				./srcs_bonus/exec_bonus.c \
				./srcs_bonus/error_bonus.c \
				./srcs_bonus/init_cmds_bonus.c \
				./srcs_bonus/argument_parser_bonus.c \
				./srcs_bonus/argument_parser2_bonus.c \
				./srcs_bonus/init_here_doc_bonus.c \
				./srcs_bonus/exec_here_doc_bonus.c \

OBJS = ${SRC:.c=.o}
OBJS_BONUS = ${SRC_BONUS:.c=.o}

HEADER = ./incs/pipex.h
HEADER = ./incs/pipex_bonus.h

LIB_FLAGS = ar -rcs

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

.c.o:
			${CC} ${CFLAGS} -I/libft -I/incs -c $< -o ${<:.c=.o}

all: $(NAME)

$(BIN):
		mkdir $(BIN)

$(PIPEX):	$(OBJS) $(HEADER)
		$(LIB_FLAGS) $(PIPEX) $(OBJS)

$(NAME): $(BIN) $(OBJS) $(HEADER) $(PIPEX)
		make -C $(LIBFT_PATH)
		$(CC) ${CFLAGS} -o $(NAME) $(PIPEX) $(LIBFT_PATH)/$(LIBFT)
		cp $(NAME) $(EXEC)

bonus: $(NAME_BONUS)

$(PIPEX_BONUS):	$(OBJS_BONUS) $(HEADER_BONUS)
		$(LIB_FLAGS) $(PIPEX_BONUS) $(OBJS_BONUS)

$(NAME_BONUS): $(BIN) $(OBJS_BONUS) $(HEADER_BONUS) $(PIPEX_BONUS)
		make -C $(LIBFT_PATH)
		$(CC) ${CFLAGS} -o $(NAME_BONUS) $(PIPEX_BONUS) $(LIBFT_PATH)/$(LIBFT)
		cp $(NAME_BONUS) $(EXEC)

clean:
	rm -f $(OBJS_BONUS)
	rm -f $(PIPEX_BONUS)
	rm -f $(OBJS)
	rm -f ./libft/$(LIBFT)
	rm -f $(PIPEX)
	make clean -C $(LIBFT_PATH)

fclean:	clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)
	rm -f $(EXEC)

re: fclean all

rebonus: fclean bonus
