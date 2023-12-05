#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#	 __  __    __    _  _  ____  ____  ____  __    ____ 		    	 	 #
#	(  \/  )  /__\  ( )/ )( ___)( ___)(_  _)(  )  ( ___)		   		     #
#	 )    (  /(__)\  )  (  )__)  )__)  _)(_  )(__  )__) 		     		 #
#	(_/\/\_)(__)(__)(_)\_)(____)(__)  (____)(____)(____) 𝕓𝕪 𝕁𝕠𝕤𝕖𝕡𝕙 ℂ𝕙𝕖𝕖𝕝     #									
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──NAME──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

NAME		=	miniRT

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──CMD───✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

CC			=	gcc
#Flags to compile in MAC
all :	CFLAGS	=	-Wall -Werror -Wextra -D KEY_MAC_H
all :	MLXFLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
all :		mlx_link libft_link $(NAME)

#Flags to compile in linux
all_lnx:	CFLAGS		=	-Wall -Werror -Wextra -D KEY_LNX_H
all_lnx:	MLXFLAGS 	= 	-L/usr/lib -Imlx -lXext -lX11 -L/usr/lib/X11 -lm -lz 
all_lnx:	mlx_link libft_link $(NAME)

#XFLAGS		=	-fsanitize=address -g2 -g
CLEAN_CAR	=	\033[2K\r

AR			=	ar rcs
RM			=	rm -f
MD			=	mkdir -p
CP			=	cp -f

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅DIRECTORIES✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

PATH_DIR		=	PATH/
PATH_DIR		=	PATH/

SRC_DIR		=	src/
OBJ_DIR		=	obj/

INC_DIR		=	inc/

LIBFT		=	libft/libft.a
LIBFT_DIR	= 	libft/

MLX			=	mlx/libmlx.a
MLX_DIR		= 	mlx/

INC			=	$(addprefix $(MDT_DIR), $(INC_DIR))

INCLUDE		+= -I $(INC)

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─SORCES─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

PARSERS		= main.c init_vars.c dist_pto_vector.c int_vect_esfera.c  \
			modulo_vector.c prod_cte_vector.c prod_escalar.c prod_vectorial.c \
			resta_vector.c suma_vector.c
GRAPHICS	=

SRCS			+=	$(addprefix $(MDT_DIR), $(addprefix $(SRC_DIR), $(PARSERS)))

OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

DEPS			+=	$(addsuffix .d, $(basename $(OBJS)))

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅───OBJECT DEPENDENCY TARGET───❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

$(OBJ_DIR)%.o : %.c Makefile 
	@$(MD) $(dir $@)
	@printf "$(CLEAN_CAR)$(OK_COLOR)[miniRT Compiling]$(BLUE_COLOR) : $(WARN_COLOR)$<$(NO_COLOR)"
	@$(CC) -MT $@ -MMD -MP -c $(CFLAGS) $(INCLUDE) -Imlx  $< -o $@ 
#-I ./mlx/mlx.h
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─TARGET─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

$(NAME):	$(LIBFT) $(MLX) $(OBJS)
			$(CC) $(CFLAGS) $(MLXFLAGS) $(XFLAGS) $(OBJS) $(LIBFT) $(LNXMLXFLAGSS) -o $(NAME)
			@echo "$(CLEAN_CAR)$(OK_COLOR)$(NAME) Compiled!$(NO_COLOR)"
			@echo "Use $(BLUE_COLOR)./$(NAME)$(NO_COLOR) to launch the program"
clean:
			@make clean -sC mlx
			@make clean -sC libft
			@$(RM) -r $(OBJ_DIR)
			@echo "$(ERROR_COLOR)Dependencies and objects removed$(NO_COLOR)"

fclean:		clean
			@make fclean -sC libft
			@$(RM) $(NAME) $(NAME_BONUS)
			@echo "$(ERROR_COLOR)Programs removed$(NO_COLOR)"

re:			fclean all

libft_link:	
			@make -sC $(LIBFT_DIR)

mlx_link:	
			@make -sC $(MLX_DIR)

-include $(DEPS)
-include $(DEPS_BONUS)

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○IGNORE○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

.PHONY: all clean fclean re 

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─COLOR──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

NO_COLOR		=	\x1b[0m
OK_COLOR		=	\x1b[32;01m
ERROR_COLOR		=	\x1b[31;01m
WARN_COLOR		=	\x1b[33;01m
BLUE_COLOR		=	\x1b[34;01m

OK_STRING		=	$(OK_COLOR)[OK]$(NO_COLOR)
ERROR_STRING	=	$(ERROR_COLOR)[ERRORS]$(NO_COLOR)
WARN_STRING		=	$(WARN_COLOR)[WARNINGS]$(NO_COLOR)


