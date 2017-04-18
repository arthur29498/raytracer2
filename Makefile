##
## Makefile for misc in /home/arthur/delivery/.misc
##
## Made by Arthur Philippe
## Login   <arthur@epitech.net>
##
## Started on  Mon Nov  7 11:39:45 2016 Arthur Philippe
## Last update Tue Apr 11 17:37:50 2017 etienne.filliat
##

CC	=	gcc

RM	=	rm -f

NAME	=	raytracer2

SRCS	=	src/main.c				\
		src/data_nuke.c				\
		src/light.c				\
		src/str.c				\
		src/open_window.c			\
		src/data_gathering/fd_errors.c		\
		src/data_gathering/get_next_line.c	\
		src/data_gathering/list.c		\
		src/data_gathering/load_data.c		\
		src/data_gathering/match.c		\
		src/data_gathering/objects_creation.c	\
		src/moves/rotate.c			\
		src/moves/translate.c			\
		src/objects/cone.c			\
		src/objects/cylinder.c			\
		src/objects/plane.c			\
		src/objects/sphere.c			\
 		src/objects/utils.c			\
		src/objects/default_colors.c		\
		src/render/calc_dir_vector.c		\
		src/render/get_intersection.c		\
		src/render/my_put_pixel.c		\
		src/render/obj_fctn_shunter.c		\
		src/render/raytrace.c			\
		src/render/progress.c			\
		src/render/std_effects.c		\
		src/procedural_texturing/chest_board.c	\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wextra -Wall

##CFLAGS	+=	-Werror

CFLAGS	+=	-I include/

LDFLAGS	=	-L./lib/acp -lacp -lc_graph_prog -lm

all: make_acp_print $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

make_acp_print:
	$(MAKE) -C lib/acp

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C lib/acp

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C lib/acp

re: fclean all

.PHONY: all clean fclean re make_acp_print
