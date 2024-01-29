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
NAME_BONUS	=	miniRT_bonus

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──CMD───✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

CC			=	gcc

MATHFLAG	=	-lm
XFLAGS		=	-g2 -g#-fsanitize=address 
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
LIGHTS_DIR			=	lights/
PARSER_DIR			=	parser/
VECTOR3_DIR			=	vector3/
EVENTS_DIR			=	events_control/
TEST_DIR			=	for_test/

MAN_DIR		=	mandatory/
BONUS_DIR		=	bonus/

SRC_DIR		=	src/
OBJ_DIR		=	obj/

INC_DIR		=	mandatory/inc/ -I libft/inc/
INC_DIR_BONUS	=	bonus/inc/ -I libft/inc/
LIBFT		=	libft/libft.a
LIBFT_DIR	= 	libft/

MLX			=	mlx/libmlx.a
MLX_DIR		= 	mlx/

INC			=	$(INC_DIR)
INC_BONUS	=	$(INC_DIR_BONUS)

INCLUDE			+=	$(addprefix -I , $(INC))
INCLUDE_BONUS	+=	$(addprefix -I , $(INC_BONUS))

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─SORCES─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

SRC_MINIRT		=	main.c initializers.c hsl_to_rgb.c rgb_to_hsl.c \
					def_vector_sense.c
CHECKER			=	init_vars.c checks.c device_check.c geometry_check.c check_syntax.c check_ratios.c
PARSERS			=	device_add.c geometry_add.c adders.c
GEOMETRY		=	geom_lstcreate.c get_int_pt.c def_pixel_vp.c \
					dump_mem_2_scr.c set_pixel_color.c
LIGHTS			=	lights_lstcreate.c lights_clone.c color_mng.c

VECTOR3			=	conv_v_unit.c div_cte_vector.c int_vect_esfera.c \
				modulo_vector.c prod_escalar.c resta_vector.c \
				dist_pto_vector.c int_vect_plano.c prod_cte_vector.c \
				prod_vectorial.c suma_vector.c print_vector.c \
				create_vector.c int_vect_cilind.c solv_eq_ord_2.c is_zero_vect.c \
				init_vp.c rotate_vector.c 
EVENTS_MAC		= key_events_mac.c mouse_events.c close.c disp_rot_zoom.c
EVENTS_LNX		= key_events_lnx.c mouse_events.c close.c disp_rot_zoom.c
#TEST 			= print_pixel_values.c

SRCS			+=	$(addprefix $(MAN_DIR), $(addprefix $(SRC_DIR), $(SRC_MINIRT)))
SRCS			+=	$(addprefix $(MAN_DIR), $(addprefix $(SRC_DIR), $(addprefix $(CHECKER_DIR), $(CHECKER))))
SRCS			+=	$(addprefix $(MAN_DIR), $(addprefix $(SRC_DIR), $(addprefix $(PARSER_DIR), $(PARSERS))))
SRCS			+=	$(addprefix $(MAN_DIR), $(addprefix $(SRC_DIR), $(addprefix $(GEOMETRY_DIR), $(GEOMETRY))))
SRCS			+=	$(addprefix $(MAN_DIR), $(addprefix $(SRC_DIR), $(addprefix $(LIGHTS_DIR), $(LIGHTS))))
SRCS			+=	$(addprefix $(MAN_DIR), $(addprefix $(SRC_DIR), $(addprefix $(VECTOR3_DIR), $(VECTOR3))))
SRCS			+=	$(addprefix $(MAN_DIR), $(addprefix $(SRC_DIR), $(addprefix $(TEST_DIR), $(TEST))))

ifeq ($(filter $(word 1,$(MAKECMDGOALS)),"all_lnx" "re_lnx" "clean_lnx" "fclean_lnx"),)
    SRCS 		+= $(addprefix $(MAN_DIR), $(addprefix $(SRC_DIR), $(addprefix $(EVENTS_DIR), $(EVENTS_MAC))))
else
    SRCS 		+= $(addprefix $(MAN_DIR), $(addprefix $(SRC_DIR), $(addprefix $(EVENTS_DIR), $(EVENTS_LNX))))
endif

#Flags to compile in MAC
all: 		CFLAGS		=	-Wall -Werror -Wextra -D KEY_MAC_H -O3 #-fsanitize=address 
all: 		MLXFLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
all: 		mlx_link libft_link $(NAME)

#Flags to compile in linux
all_lnx:	CFLAGS		=	-Wall -Werror -Wextra -D KEY_LNX_H -O3 # 
all_lnx:	MLXFLAGS 	= 	-L/usr/lib -Imlx -lXext -lX11 -L/usr/lib/X11 -lz 
all_lnx:	mlx_lnx_link libft_link $(NAME)

OBJS			=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
DEPS			+=	$(addsuffix .d, $(basename $(OBJS)))

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅────✧❅✦❅✧─────❅••❅──────✧❅✦❅✧─SORCES BONUS─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧───❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

SRC_MINIRT_BN		=	main_bonus.c initializers_bonus.c hsl_to_rgb_bonus.c rgb_to_hsl_bonus.c \
					def_vector_sense_bonus.c
CHECKER_BN			=	init_vars_bonus.c checks_bonus.c device_check_bonus.c geometry_check_bonus.c check_syntax_bonus.c check_ratios_bonus.c
PARSERS_BN		=	device_add_bonus.c geometry_add_bonus.c adders_bonus.c element_add_bonus.c \
					add_bumpmap_bonus.c get_conus_bonus.c get_cylinder_bonus.c get_plane_bonus.c \
					get_sphere_bonus.c get_triang_bonus.c
GEOMETRY_BN		=	geom_lstcreate_bonus.c get_int_pt_bonus.c def_pixel_vp_bonus.c \
					dump_mem_2_scr_bonus.c set_pixel_color_bonus.c set_pixel_color_chckbd_bonus.c set_pixel_color_bumpmap_bonus.c 
LIGHTS_BN			=	lights_lstcreate_bonus.c lights_clone_bonus.c colors_mng_bonus.c

VECTOR3_BN			=	conv_v_unit_bonus.c div_cte_vector_bonus.c int_vect_esfera_bonus.c \
				modulo_vector_bonus.c prod_escalar_bonus.c resta_vector_bonus.c \
				dist_pto_vector_bonus.c int_vect_plano_bonus.c prod_cte_vector_bonus.c \
				prod_vectorial_bonus.c suma_vector_bonus.c print_vector_bonus.c \
				create_vector_bonus.c int_vect_cilind_bonus.c solv_eq_ord_2_bonus.c is_zero_vect_bonus.c \
				init_vp_bonus.c int_vect_cono_bonus.c rotate_vector_bonus.c int_vect_triang_bonus.c \
				matrix_rot_bonus.c vect_dot_matrix.c cambio_coord_vect_bonus.c vect_unitarios_bonus.c \
				mat_inversa.c
EVENTS_MAC_BN		= key_events_mac_bonus.c mouse_events_bonus.c close_bonus.c disp_rot_zoom_bonus.c
EVENTS_LNX_BN		= key_events_lnx_bonus.c mouse_events_bonus.c close_bonus.c disp_rot_zoom_bonus.c
TEST_BN 			= print_pixel_values_bonus.c

SRCS_BN			+=	$(addprefix $(BONUS_DIR), $(addprefix $(SRC_DIR), $(SRC_MINIRT_BN)))
SRCS_BN			+=	$(addprefix $(BONUS_DIR), $(addprefix $(SRC_DIR), $(addprefix $(CHECKER_DIR), $(CHECKER_BN))))
SRCS_BN			+=	$(addprefix $(BONUS_DIR), $(addprefix $(SRC_DIR), $(addprefix $(PARSER_DIR), $(PARSERS_BN))))
SRCS_BN			+=	$(addprefix $(BONUS_DIR), $(addprefix $(SRC_DIR), $(addprefix $(GEOMETRY_DIR), $(GEOMETRY_BN))))
SRCS_BN			+=	$(addprefix $(BONUS_DIR), $(addprefix $(SRC_DIR), $(addprefix $(LIGHTS_DIR), $(LIGHTS_BN))))
SRCS_BN			+=	$(addprefix $(BONUS_DIR), $(addprefix $(SRC_DIR), $(addprefix $(VECTOR3_DIR), $(VECTOR3_BN))))
SRCS_BN			+=	$(addprefix $(BONUS_DIR), $(addprefix $(SRC_DIR), $(addprefix $(TEST_DIR), $(TEST_BN))))

ifeq ($(filter $(word 1,$(MAKECMDGOALS)),"all_lnx" "re_lnx" "clean_lnx" "fclean_lnx"),)
    SRCS_BN 		+= $(addprefix $(BONUS_DIR), $(addprefix $(SRC_DIR), $(addprefix $(EVENTS_DIR), $(EVENTS_MAC_BN))))
else
    SRCS_BN 		+= $(addprefix $(BONUS_DIR), $(addprefix $(SRC_DIR), $(addprefix $(EVENTS_DIR), $(EVENTS_LNX_BN))))
endif

#Flags to compile in MAC
bonus: 		CFLAGS		=	-Wall -Werror -Wextra -D KEY_MAC_H -O3 #-fsanitize=address
bonus: 		MLXFLAGS	=	-Lmlx -lmlx -framework OpenGL -framework AppKit
bonus: 		mlx_link libft_link $(NAME_BONUS)

#Flags to compile in linux
bonus_lnx:	CFLAGS		=	 -D KEY_LNX_H -O3  -Wall -Wextra # -Werror
bonus_lnx:	MLXFLAGS 	= 	-L/usr/lib -Imlx -lXext -lX11 -L/usr/lib/X11 -lz 
bonus_lnx:	mlx_lnx_link libft_link $(NAME_BONUS)

OBJS_BONUS			=	$(addprefix $(OBJ_DIR), $(SRCS_BN:.c=.o))
DEPS_BONUS			+=	$(addsuffix .d, $(basename $(OBJS_BONUS)))


#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅───OBJECT DEPENDENCY TARGET───❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

$(OBJ_DIR)%.o : %.c Makefile 
	@$(MD) $(dir $@)
	@printf "$(CLEAN_CAR)$(OK_COLOR)[miniRT Compiling]$(BLUE_COLOR) : $(WARN_COLOR)$<$(NO_COLOR) "
	@$(CC) -MT $@ -MMD -MP -c $(CFLAGS) $(XFLAGS) $(INCLUDE) $(INCLUDE_BONUS) -Imlx  $< -o $@

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧──────❅••❅──────✧❅✦❅✧─TARGET─✧❅✦❅✧──────❅••❅──────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

$(NAME):	$(LIBFT) $(MLX) $(OBJS)
			@sleep 0.2
			@echo "$(CLEAN_CAR)$(OK_COLOR)$(NAME) Compiled!$(NO_COLOR)"
			$(CC) $(CFLAGS) $(XFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME) $(MATHFLAG)
			@echo "Use $(BLUE_COLOR)./$(NAME)$(NO_COLOR) to launch the program"

$(NAME_BONUS):	$(LIBFT) $(MLX) $(OBJS_BONUS)
			@echo "$(CLEAN_CAR)$(OK_COLOR)$(NAME_BONUS) Compiled!$(NO_COLOR)"
			$(CC) $(CFLAGS) $(XFLAGS) $(OBJS_BONUS) $(LIBFT) $(MLX) $(MLXFLAGS) -o $(NAME_BONUS) $(MATHFLAG)
			@echo "Use $(BLUE_COLOR)./$(NAME_BONUS)$(NO_COLOR) to launch the program"

clean:
			@make clean -sC mlx
			@make clean -sC libft
			@$(RM) -r $(OBJ_DIR)
			@echo "$(ERROR_COLOR)Dependencies and objects removed$(NO_COLOR)"

fclean:		clean
			@make fclean -smC libft
			@$(RM) $(NAME) $(NAME_BONUS)
			@echo "$(ERROR_COLOR)Programs removed$(NO_COLOR)"

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅──────✧❅✦❅✧─────❅••❅───✧❅✦❅✧─TARGET FOR MAC─✧❅✦❅✧───❅••❅─────✧❅✦❅✧──────❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
re:			fclean all

libft_link:	
			@make -sC $(LIBFT_DIR)

mlx_link:	
			@make -sC $(MLX_DIR)

re_lnx:		fclean_lnx all_lnx

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
#•❅───✧❅✦❅✧────❅••❅───✧❅✦❅✧──TARGET  LINUX UBUNTU──✧❅✦❅✧───❅••❅────✧❅✦❅✧───❅•#
#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#
mlx_lnx_link:
			@make -f Makefile_2.gen -sC $(MLX_DIR)
clean_lnx:
			@make clean -f Makefile_2.gen -sC mlx
			@make clean -sC libft
			@$(RM) -r $(OBJ_DIR)
			@echo "$(ERROR_COLOR)Dependencies and objects removed$(NO_COLOR)"
fclean_lnx:		clean_lnx
			@make fclean -smC libft
			@$(RM) $(NAME) $(NAME_BONUS)
			@echo "$(ERROR_COLOR)Programs removed$(NO_COLOR)"

-include $(DEPS)
-include $(DEPS_BONUS)

#●○●○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○IGNORE○●○●○●○●○●○●○●○●●○●○●○●○●○●○●○●○●○●#

.PHONY: all clean fclean re bonus libft_link mlx_link re_lnx mlx_lnx_link clean_lnx fclean_lnx bonus_lnx
