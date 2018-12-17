# ************************************************************************** #
#                                                          LE - /            #
#                                                              /             #
#   Makefile                                         .::    .:/ .      .::   #
#                                                 +:+:+   +:    +:  +:+:+    #
#   By: fablin <fablin@student.42.fr>              +:+   +:    +:    +:+     #
#                                                 #+#   #+    #+    #+#      #
#   Created: 2018/12/14 17:52:22 by fablin       #+#   ##    ##    #+#       #
#   Updated: 2018/12/17 16:42:35 by fablin      ###    #+. /#+    ###.fr     #
#                                                         /                  #
#                                                        /                   #
# ************************************************************************** #

FLAGS =		-Wall -Wextra -Werror

INC_DIR =	./inc/

ASM = ./asm

COREWAR = ./corewar

all : libft
	@make -C ./src/asm/
	@make -C ./src/corewar/

libft :
	@make -C ./lib/libft/

$(ASM) :
	@make -C ./src/asm/

$(COREWAR) :
	@make -C ./src/corewar/

clean :
	@make clean -C ./lib/libft/
	@make clean -C ./src/asm/
	@make clean -C ./src/corewar/

fclean :
	@make fclean -C ./lib/libft/
	@make fclean -C ./src/asm/
	@make fclean -C ./src/corewar/

re :
	@make re -C ./lib/libft/
	@make re -C ./src/asm/
	@make re -C ./src/corewar/

debug_asm : libft
	make debug -C ./src/asm/

debug_corewar : libft
	make debug -C ./src/corewar/

install :
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install npm
	brew install soket.io

remove_cor :
	find ./ -type f -name "*.cor" -delete

.PHONY: all clean fclean re libft corewar asm