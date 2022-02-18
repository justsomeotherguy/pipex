# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwilliam <jwilliam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/19 14:18:22 by jwilliam          #+#    #+#              #
#    Updated: 2022/02/16 12:09:35 by jwilliam         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc

FLAGS = -Wall -Werror -Wextra

RM = rm -rf

MAIN = srcs/main.c

FILES =	srcs/error.c \
		srcs/get_path.c \
		srcs/access_path.c \
		srcs/main_process.c \
		srcs/sub_process.c \

OBJS = $(FILES:.c=.o)

.c.o:
	@$(CC) -c $(FLAGS) -I includes $< -o $(<:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		@$(MAKE) re -C ./libft
		@cp libft/libft.a ./$(NAME).a
		@ar rcs $(NAME).a $(OBJS)
		@$(CC) $(FLAGS) $(NAME).a $(MAIN) -o $(NAME) -I includes/
		@echo ":) pipex created :)"

clean:
		@$(MAKE) clean -C ./libft
		@$(RM) $(OBJS)
		@echo ":) cleaned pipex obj files :)"

fclean:	clean
		@$(RM) $(NAME)
		@$(RM) $(NAME).a
		@$(MAKE) fclean -C ./libft
		@echo ":) cleaned pipex file :)"

re: fclean all

.PHONY: clean fclean all re
