/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:19:31 by eavedill          #+#    #+#             */
/*   Updated: 2024/01/20 23:32:56 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H
# include "../../mlx/mlx.h"
# include "../../libft/inc/libft.h"
# include "colors_bonus.h"
# include <math.h>
# include <limits.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <math.h>
# ifdef KEY_LNX_H
#  include "../inc/key_mouse_cod_lnx_bonus.h"
# endif
# ifdef KEY_MAC_H
#  include "../inc/key_mouse_cod_mac_bonus.h"
# endif
# define WIN_NAME "miniRT"
# define WIN_X 540
# define WIN_Y 540
# define FRAME 0

//# define PIXEL 0.0000054
# define PIXEL 0.5
# define GEO_IDENT "sp cy pl cn"
# define DEV_IDENT "C L A CHECKBOARD"

# define CAMERA 'C'
# define LIGHT 'L'
# define AMBNT_LGHT 'A'

// eventslist
// Key	Event	 	Key	Event	 	Key	Event
# define EVENT_KEY_PRESS 02
# define EVENT_KEY_RELEASE 03
# define EVENT_BUTTON_PRESS 04
# define EVENT_BUTTON_RELEASE 05
# define EVENT_MOTION_NOTIFY 06
# define EVENT_DESTROY_NOTIFY 17
// Key	Event	 	Key	Event	 	Key	Event
# define MASK_KEY_PRESS 0
# define MASK_KEY_RELEASE 1
# define MASK_BUTTON_PRESS 2
# define MASK_BUTTON_RELEASE 3
# define MASK_MOTION_NOTIFY 6
# define MASK_DESTROY_NOTIFY 17
//Buttno definition
# define MOUSE_BTN_LEFT 1
# define MOUSE_BTN_RIGHT 3
# define MOUSE_BTN_MIDDLE 2
# define MOUSE_BTN_ROT_UP 4
# define MOUSE_BTN_ROT_DW 5
//Parametros ara el movimiento de rotacion
# define ROT_SPH 200

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
	CHECKBOARD,
	MAX_DEVICES
};

typedef struct s_indexes
{
	int	i;
	int	j;
	int	k;

}	t_indexes;

typedef struct s_img_buff
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
}	t_img_buff;

typedef struct s_color
{
	int		r;
	int		g;
	int		b;
	int		a;
	double	h;
	double	s;
	double	l;
}	t_color;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_vec_pos
{
	t_vec3	pt;
	t_vec3	v;
	t_color	c;
}	t_vec_pos;

typedef struct s_geom
{
	enum e_type_geo	type;
	t_vec_pos		vp;
	t_color			color;
	double			r;
	double			height;
	int				sense;
	void			*next;
}	t_geom;

typedef struct s_axis
{
	t_vec3		pos;
	t_vec3		vx;
	t_vec3		vy;
	t_vec3		vz;
}	t_axis;

typedef struct s_int_pts
{
	t_vec_pos	pt;
	void		*geom;
}	t_int_pts;

typedef struct s_camera
{
	t_axis		center;
	t_vec3		observer;
	t_vec_pos	*field_vp;
	t_int_pts	*int_vp;
	int			fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	pos;
	t_color	color;
	float	ratio;
	int		fov;
	void	*next;
}	t_light;

typedef struct s_event
{
	int		key_ctrl_press;
	int		key_alt_press;
	int		key_shift_press;
	int		btn_rght_presd;
	int		btn_cent_presd;
	int		btn_left_presd;
	int		x;
	int		y;
}	t_event;

typedef struct s_ambient
{
	t_color	color;
	float	ratio;
}	t_ambient;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	int		frame;
	int		size_x;
	int		size_y;
}	t_mlx;

typedef struct s_ray
{
	t_vec3	*point;
	t_vec3	*dir;	
}	t_ray;

typedef struct s_checkboard
{
	bool		is_chckbd;
	double		size;
	t_color		c1;
	t_color		c2;
}	t_checkboard;

typedef struct s_field
{
	t_geom			*geom;
	t_color			bck_col;
	t_ambient		ambient;
	t_camera		camera;
	t_light			*light;
	t_mlx			mlx;
	t_event			events;
	t_vec3			aux;
	t_camera		orig_camera;
	t_light			*orig_light;
	t_checkboard	chckbd;
}	t_field;

/* Initializers */
t_field		*initializer(char *av);
t_field		*init_field(void);
void		init_mlx(t_field *field);

/* syntax data checker */
int			validate_scene_file(char *filename);
bool		ft_check_line_data(char **content);
bool		ambient_light_data_check(char **content);
bool		camera_data_check(char **content);
bool		light_data_check(char **content);
bool		plane_data_check(char **content);
bool		sphere_data_check(char **content);
bool		cylinder_data_check(char **content);
bool		checkboard_data_check(char **content);

bool		ft_isdouble(char *nbr);
bool		ft_is_vec3(char *str);
bool		ft_check_vect3_ratio(char *content, double min, double max);
bool		ft_check_rgb_ratio(char *content);
bool		ft_is_rgb(char *str);

int			rgb_error(t_color color);
int			ratio_double_error(double min, double max, double nbr);
int			ratio_int_error(int min, int max, int nbr);
int			ratio_vec3_error(int min, int max, t_vec3 vector);

/* Parser */
int			read_file(char *filename, t_field *field);
int			get_devices(t_field *field, char *line);
int			get_geom(t_field *field, char *line);
int			get_checkboard(t_field *field, char *line);
//Closers
int			ft_close(t_field *field);

void		free_field(t_field *field);

/* Algebra vectorial */
t_vec3		create_vect(double x, double y, double z);
t_vec3		suma_vector(t_vec3 a, t_vec3 b);
t_vec3		resta_vector(t_vec3 a, t_vec3 b);
t_vec3		prod_vectorial(t_vec3 a, t_vec3 b);
double		modulo_vector(t_vec3 a);
double		prod_escalar(t_vec3 a, t_vec3 b);
t_vec_pos	*int_vect_esfera(t_vec_pos vp1,	t_vec3 pr, double r);
t_vec_pos	*int_vect_cilind(t_vec_pos vp1, t_vec_pos vpc, double r, double h);
t_vec_pos	*int_vect_plano(t_vec_pos pi, t_vec_pos pl);
t_vec_pos	*int_vect_cono(t_vec_pos vpi, t_vec_pos vpc, double r, double h);
t_vec3		prod_cte_vector(double a, t_vec3 b);
t_vec3		div_cte_vector(double a, t_vec3 b);
double		dist_pto_vector(t_vec3 p1, t_vec3 p2, t_vec3 v);
double		*solv_eq_ord_2(double *p);
t_vec3		conv_v_unit(t_vec3 v);
int			is_zero_vec(t_vec3 v);
t_vec_pos	init_vp(t_color c);
t_vec3		rotate_vector(t_vec3 v, t_vec3 k, double ang_rot);

/* Adders */
t_vec3		add_vec3(char *vector3);
t_color		add_color(char *color);

/* Geometry Struct */
void		ft_geomadd_back(t_geom **lst, t_geom *new_node);
t_geom		*ft_geomlast(t_geom *lst);
void		ft_geom_size(t_geom *head);
void		ft_free_geometry(t_geom **head);

/* Intersection operations*/
int			dump_mem_2_scr(t_field *field);
void		def_pixel_vp(t_field *field, t_indexes in, t_indexes lim);
void		get_colored_int_pt(int pixel, t_field *field);
t_vec_pos	*get_int_pt(t_vec_pos *vps, t_geom *geo);
void		set_point_int(t_field *field);

/* Color */
t_color		set_pixel_color(t_int_pts vp, t_field *field, t_vec_pos pixl);
void		rgb_to_hsl(t_color *c);
void		hsl_to_rgb(t_color *c);

/*	Light Struct Functions */
t_light		*ft_clone_light(t_light *light);
t_light		*ft_lightlast(t_light *lst);
void		ft_lightadd_back(t_light **lst, t_light *new_node);
int			ft_lightsize(t_light *lst);
void		ft_free_light(t_light **head);
t_light		*ft_clone_lightning(t_light *light);
void		def_vector_sense(t_field *field);

/* Debug */
void		ft_check_calculations(void);
void		ft_print_vector(char *s, t_vec_pos v);
void		print_pixel_values(int x, int y, t_field *field);
void		ft_print_vec3(char *s, t_vec3 vec);
void		print_color_values(char *s, t_color c);

/* Events */
int			mouse_events_mov(int x, int y, t_field *field);
int			mouse_events_rel(int mouse, int x, int y, t_field *field);
int			mouse_events_pre(int mouse, int x, int y, t_field *field);
int			key_events_press(int key, t_field *field);
int			key_events_release(int key, t_field *field);

/* Movements */
void		zoom(int cte, t_field *field);
void		displ(t_field *field, int x, int y);
void		cam_rotate(t_field *field, int x, int y);
int			move_light(t_field *field);

#endif
