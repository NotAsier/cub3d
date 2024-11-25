# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aarranz- <aarranz-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/09 11:33:45 by aarranz-          #+#    #+#              #
#    Updated: 2024/11/25 13:48:32 by aarranz-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	cub3d
SRC_PATH	:=	src
OBJ_DIR		:=	obj
SOURCES		:=	main.c map_checker.c map_checker2.c map_checker3.c free_leaks.c
OBJS		:=	$(SOURCES:%.c=$(OBJ_DIR)/%.o)
CC			:=	gcc
CFLAGS		:=	-Wall -Wextra -Werror -I./include -g3 #-fsanitize=address

LIBFT = libs/libft/
GNL = libs/get_next_line/

PAPYRUS=\033[38;5;223m
END=\033[0m

define CUB3D
$(PAPYRUS)
                        .="=.
                      _/.-.-.\_     _
                     ( ( o o ) )    ))
                      |/  "  \|    //
      .--------.       \'---'/    //
     _|Benancio|_      /`"""`\\  ((
   =(_|________|_)=   / /_,_\ \\  \\\\
     |:::::::::|      \_\\_'__/ \  ))
     |:::::::[]|       /`  /`~\  |//
     |o=======.|      /   /    \  /
      `"""""""""`  ,--`,--'\/\    /
                   '-- "--'  '--'
$(END)
endef
export CUB3d

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT)
	$(MAKE) -C $(GNL)
	mv $(LIBFT)libft.a ./
	mv $(GNL)get_next_line.a ./
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) libft.a get_next_line.a
	@echo "$$CUB3D"

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_PATH)/%.c $(OBJ_DIR)
	@$(CC) -c $(CFLAGS) $< -o $@

clean:
	@rm -fr $(OBJ_DIR)
	$(MAKE) -C $(LIBFT) clean
	$(MAKE) -C $(GNL) clean

fclean:
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(GNL) fclean
	@rm -fr $(OBJ_DIR)
	@rm -f $(NAME) libft.a get_next_line.a

re: fclean all

.PHONY: all clean fclean re