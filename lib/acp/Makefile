##
## Makefile for misc in /home/arthur/delivery/.misc
##
## Made by Arthur Philippe
## Login   <arthur@epitech.net>
##
## Started on  Mon Nov  7 11:39:45 2016 Arthur Philippe
## Last update Thu May 25 09:15:33 2017 Arthur Philippe
##

CC	=	gcc

RM	=	rm -fv

NAME	=	libacp.a

GREEN	=	\033[0;32m

RESET	=	\033[0m

SRCS	=	src/print/my_printf.c		\
		src/print/disp.c		\
		src/print/disp1.c		\
		src/print/disp2.c		\
		src/print/disp3.c		\
		src/print/utilities.c		\
		src/print/utilities1.c		\
		src/print/flags1.c		\
		src/print/flags2.c		\
		src/print/flags3.c		\
		src/get_next_line.c		\
		src/my_memset.c			\
		src/my_strdup.c			\
		src/my_strcat.c			\
		src/match.c			\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wall -Wextra -Werror

CFLAGS	+=	-I include/

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@echo -e "\n$(GREEN)$(NAME) built$(RESET)!"

clean:
	@echo -en "cleaned " ; $(RM) $(OBJS) | wc -l | tr -d '\n'
	@echo -e " of $(NAME)'s object files"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
