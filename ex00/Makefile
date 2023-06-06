# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afavre <afavre@student.42lausanne.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/21 18:57:20 by afavre            #+#    #+#              #
#    Updated: 2023/05/21 18:57:20 by afavre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= Fixed
INCLUDE			= ./include
SRC_DIR			= src/
OBJ_DIR			= obj/
CC				= g++
FLAGS			= -Wall -Werror -Wextra -std=c++98
RM				= rm -rf

GREEN = \033[0;92m
YELLOW = \033[0;93m
ENDCOLOR = \033[0;39m

SRC_FILES	=	Main \
				Fixed


SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .cpp, $(SRC_FILES)))
OBJ			= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF		=	.cache_exists

all:		$(NAME)


$(NAME):	$(OBJ)
			@$(CC) -o $(NAME) $(OBJ)
			@echo "$(GREEN) Et voila le travail ! $(ENDCOLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp | $(OBJF)
			@$(CC) -I $(INCLUDE) $(FLAGS) -c $< -o $@

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@$(RM) $(OBJ_DIR)
			@$(RM) *.duc


fclean:		clean
			@$(RM) $(NAME)
			@echo "$(YELLOW) Merci pour ce merveilleux repas ! \n\t signé Le dévoreur de code. $(ENDCOLOR)"

re:			fclean all

leaks: re
			leaks --atExit -- ./$(NAME) infile quoi arnaud

.PHONY:		all clean fclean re
