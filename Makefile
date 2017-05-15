##
## Makefile for misc in /home/arthur/delivery/.misc
##
## Made by Arthur Philippe
## Login   <arthur@epitech.net>
##
## Started on  Mon Nov  7 11:39:45 2016 Arthur Philippe
## Last update Mon May 15 22:11:27 2017 Arthur Philippe
##

CC	=	gcc

RM	=	rm -fv

NAME	=	raytracer2

SRCS	=	src/main.c				\
		src/launchers/bootstrap_import.c	\
		src/launchers/bootstrap_engine.c	\
		src/launchers/bootstrap_threads.c	\
		src/launchers/maintain_engine.c		\
		src/data_nuke.c				\
		src/light.c				\
		src/str.c				\
		src/open_window.c			\
		src/render_export.c			\
		src/get_opt.c				\
		src/helper.c				\
		src/data_gathering/fd_errors.c		\
		src/data_gathering/get_next_line.c	\
		src/data_gathering/list.c		\
		src/data_gathering/load_data.c		\
		src/data_gathering/match.c		\
		src/data_gathering/objects_creation.c	\
		src/data_gathering/objects_limit.c	\
		src/data_gathering/objects_brightness.c	\
		src/vectors/rotate.c			\
		src/vectors/translate.c			\
		src/vectors/normalize.c			\
		src/vectors/dot_product.c		\
		src/objects/cone.c			\
		src/objects/cylinder.c			\
		src/objects/limited.c			\
		src/objects/plane.c			\
		src/objects/sphere.c			\
		src/objects/utils.c			\
		src/objects/default_colors.c		\
		src/data_gathering/objs_types.c		\
		src/render/calc_dir_vector.c		\
		src/render/get_intersection.c		\
		src/render/my_put_pixel.c		\
		src/render/colored_light_effect.c	\
		src/render/obj_fctn_shunter.c		\
		src/render/raytrace.c			\
		src/render/progress.c			\
		src/render/std_effects.c		\
		src/render/set_brightness.c		\
		src/render/reflect.c			\
		src/render/refract.c			\
		src/procedural_texturing/chess_board.c	\

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Wextra -Wall

##CFLAGS	+=	-Werror

CFLAGS	+=	-I include/

LDFLAGS	=	-L./lib/acp -lacp -lc_graph_prog -lm -lpthread

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C lib/acp
	@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo -e "\nprogram assembled !"

libacp.a:
	$(MAKE) -C lib/acp

clean:
	@$(RM) $(OBJS)
	@$(MAKE) clean -C lib/acp

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C lib/acp

re: fclean all

.PHONY: all clean fclean re libacp.a
