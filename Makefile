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
all: 		CFLAGS		=	-Wall -Werror -Wextra -D KEY_MAC_H  -O3 -fsanitize=address
all: 		MLXFLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
all: 		mlx_link libft_link $(NAME)

#Flags to compile in linux
all_lnx:	CFLAGS		=	-D KEY_LNX_H -O3 #-Wall -Werror -Wextra 
all_lnx:	MLXFLAGS 	= 	-L/usr/lib -Imlx -lXext -lX11 -L/usr/lib/X11 -lz 
all_lnx:	mlx_link libft_link $(NAME)

MATHFLAG	=	-lm
#XFLAGS		=	-fsanitize=address -g2 -g
CLEAN_CAR	=	\033[2K\r

AR			=	ar rcs
RM			=	rm -f
MD			=	mkdir -p
CP			=	cp -f

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─COLOR──✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

	NO_COLOR		=	\033[1;97m
	OK_COLOR		=	\033[1;92m
	ERROR_COLOR		=	\033[1;91m
	WARN_COLOR		=	\033[1;93m
	BLUE_COLOR		=	\033[1;94m

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅DIRECTORIES✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

CHECKER_DIR			=	checker/
GEOMETRY_DIR		=	geometry/
PARSER_DIR			=	parser/
VECTOR3_DIR			=	vector3/

SRC_DIR		=	src/
OBJ_DIR		=	obj/

INC_DIR		=	inc/

LIBFT		=	libft/libft.a
LIBFT_DIR	= 	libft/

MLX			=	mlx/libmlx.a
MLX_DIR		= 	mlx/

INC			=	$(INC_DIR)

INCLUDE		+= -I $(INC)

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─SORCES─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

SRC_MINIRT		=	main.c initializers.c close.c
CHECKER			=	init_vars.c
PARSERS			=	device_add.c geometry_add.c adders.c
GEOMETRY		=	geom_lstcreate.c geom_lstprint.c ft_check_calculations.c \
					set_pict_colors.c #geom_lstutils.c
VECTOR3			=	conv_vect_unit.c div_cte_vector.c int_vect_esfera.c  \
				modulo_vector.c prod_escalar.c resta_vector.c \
				dist_pto_vector.c int_vect_plano.c prod_cte_vector.c \
				prod_vectorial.c suma_vector.c print_vector.c \
				create_vector.c int_vect_cilind.c solv_eq_ord_2.c is_zero_vect.c

GRAPHICS		=

SRCS			+=	$(addprefix $(SRC_DIR), $(SRC_MINIRT))
SRCS			+=	$(addprefix $(SRC_DIR), $(addprefix $(CHECKER_DIR), $(CHECKER)))
SRCS			+=	$(addprefix $(SRC_DIR), $(addprefix $(PARSER_DIR), $(PARSERS)))
SRCS			+=	$(addprefix $(SRC_DIR), $(addprefix $(GEOMETRY_DIR), $(GEOMETRY)))
SRCS			+=	$(addprefix $(SRC_DIR), $(addprefix $(VECTOR3_DIR), $(VECTOR3)))

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
			$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME) $(MATHFLAG)
			@echo ""
			@echo "$(CLEAN_CAR)$(OK_COLOR)$(NAME) Compiled!$(NO_COLOR)"
			@echo "Use $(BLUE_COLOR)./$(NAME)$(NO_COLOR) to launch the program"
clean:
			@make clean -sC mlx
			@make clean -sC libft
			@$(RM) -r $(OBJ_DIR)
			@echo "$(ERROR_COLOR)Dependencies and objects removed$(NO_COLOR)"

## QUE QUIERE DECIR en -smC la "-m"??
fclean:		clean
			@make fclean -smC libft
			@$(RM) $(NAME) $(NAME_BONUS)
			@echo "$(ERROR_COLOR)Programs removed$(NO_COLOR)"

re:			fclean all
re_lnx:		fclean all_lnx

libft_link:	
			@make -sC $(LIBFT_DIR)

mlx_link:	
			@make -sC $(MLX_DIR)

-include $(DEPS)
-include $(DEPS_BONUS)

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○IGNORE○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

.PHONY: all clean fclean re
