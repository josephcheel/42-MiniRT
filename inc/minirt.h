/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:19:31 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/13 12:45:46 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"
//# include "geometry.h"
# include "../inc/colors.h"
# include <math.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <math.h>

/// #include<limits.h>
# ifdef KEY_LNX_H
#	include "../inc/key_mouse_cod_lnx.h"
# endif
# ifdef KEY_MAC_H
# 	include "../inc/key_mouse_cod_mac.h"
# endif
# define WIN_NAME "miniRT"
# define WIN_X 1000
# define WIN_Y 500
# define FRAME 50

# define PIXEL 0.0000054
enum e_type_geo
{
	SPHERE,
	CYLINDER,
	PLANE,
	CONUS,
	MAX_GEOM
};

enum e_type_device
{
	C,
	L,
	A,
	MAX_DEVICES
};


# define GEO_IDENT "sp pl cy cn"
# define DEV_IDENT "C L A"

# define CAMERA 'C'
# define LIGHT 'L'
# define AMBNT_LGHT 'A'
typedef struct s_indexes
{
	int i;
	int j;
	int k;
} t_indexes;
typedef struct s_img_buff
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}t_img_buff;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}t_color;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}t_vec3;

typedef struct s_vec2
{
	double	x;
	double	y;
}t_vec2;

typedef struct s_vec_pos
{
	t_vec3	pt;
	t_vec3	v;
	t_color	c;
}t_vec_pos;

typedef struct s_geom
{
	enum e_type_geo	type;
	t_vec_pos	vp; 
	t_color		color;
	double		r;
	double		height;
	void		*next;
}t_geom;

typedef struct s_axis
{
	t_vec3		pos;
	t_vec3		vx;
	t_vec3		vy;
	t_vec3		vz;
}	t_axis;


typedef struct s_camera
{
	t_axis		center;
	t_vec3		observer;
	t_vec_pos	*field_vp;
	t_vec_pos	*int_vp;
	int			fov;
}t_camera;

typedef struct s_light
{
	t_vec3	pos;
	t_color	color;
	float	ratio;
	int		fov;
	void	*next;
}t_light;

typedef struct s_mouse_pos
{
	int	x;
	int	y;
}t_mouse_pos;

typedef struct s_ambient
{
	t_color	color;
	float	ratio;
}t_ambient;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		frame;
	int		size_x;
	int		size_y;
} t_mlx;

typedef struct s_ray
{
	t_vec3	*point;
	t_vec3	*dir;	
}t_ray;

typedef struct s_field
{
	t_geom		*geom;
	t_color		bck_col; // is this like ambient light?
	t_ambient	ambient;
	t_camera	camera;
	t_light		*light;
	t_mlx		mlx;
}t_field;

// funciones publicas
//initvars
//Initializers
t_field 	*initializer(char *av);
t_field		*init_field(void);
void 		init_mlx(t_field *field);

//Closers
int			ft_close_red_cross(t_mlx *mlx);
int			ft_close(int keycode, t_mlx *mlx);


int			read_file(char *filename, t_field *field);
void		free_field(t_field *field);


//algebra vectorial
t_vec3		create_vect(double x, double y, double z);
t_vec3		suma_vector(t_vec3 a, t_vec3 b);
t_vec3		resta_vector(t_vec3 a, t_vec3 b);
t_vec3		prod_vectorial(t_vec3 a, t_vec3 b);
double		modulo_vector(t_vec3 a);
double		prod_escalar(t_vec3 a, t_vec3 b);
t_vec_pos	*int_vect_esfera(t_vec_pos vp1,	t_vec3 pr, double r);
t_vec_pos	*int_vect_cilind(t_vec_pos vp1, t_vec_pos vpc, double r);
t_vec_pos	*int_vect_plano(t_vec_pos pi, t_vec_pos pl);
t_vec3		prod_cte_vector(double a, t_vec3 b);
t_vec3		div_cte_vector(double a, t_vec3 b);
double		dist_pto_vector(t_vec3 p1, t_vec3 p2, t_vec3 v);
void		get_devices(t_field *field, char *line);
void		get_geom(t_field *field, char *line);
double		*solv_eq_ord_2(double *p);
t_vec3		conv_v_unit(t_vec3 v);
int			is_zero_vec(t_vec3 v);

// Adders
t_vec3		add_vec3(char *vector3);
t_color		add_color(char *color);

// GEOMETRY LIST UTILS
void		ft_geomadd_back(t_geom **lst, t_geom *new_node);
t_geom		*ft_geomlast(t_geom *lst);
void		ft_geom_size(t_geom *head);
void		ft_free_geometry(t_geom **head);
void		create_field_vectors(t_field *field);
void		def_pixel_vp(t_field *field, t_indexes in, t_indexes lim);
t_vec_pos	get_int_pt(t_vec_pos vps, t_geom *geom);
void		set_point_int(t_field *field);
int			dump_mem_2_scr(t_field *field);

// JUST FOR DEBUGGING
void		ft_print_geometry_node(t_geom *node);
void		ft_print_geometry_full(t_geom *head);
void		ft_print_camera(t_field *field);
void		ft_print_light(t_field *field);
void		ft_print_ambient(t_field *field);
void		ft_check_calculations(void);
void		ft_print_vector(char *s, t_vec_pos v);


void		ft_print_vec3(t_vec3 vec);



int	rgb_to_hex(t_color color);

#endif
