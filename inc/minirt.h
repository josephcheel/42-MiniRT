/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:19:31 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/04 04:01:33 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"
# include "geometry.h"
# include <math.h>
# include <stdio.h>
# include <stdbool.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

/// #include<limits.h>
# ifdef KEY_LNX_H
#  include "../inc/key_mouse_cod_lnx.h"
# endif
# ifdef KEY_MAC_H
#  include "../inc/key_mouse_cod_mac.h"
# endif

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

typedef struct s_geom
{
	enum e_type_geo	type;
	t_vec3		pt1;
	t_vec3		direction;
	double		r;
	double		height;
	t_color		color;
	void		*next;
}t_geom;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	orientation;
	int			fov;
}t_camera;

typedef struct s_light
{
	t_vec3	pos;
	t_vec3	orientation;
	t_color	color;
	float	ratio;
	int			fov;
	void		*next;
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

typedef struct s_field
{
	t_geom		*geom;
	t_color		bck_col; // is this like ambient light?
	t_ambient	ambient;
	t_camera	camera;
	t_light		*light;
}t_field;

// funciones publicas
//initvars
t_field		*init_vars(char *ac);
void		free_field(t_field *field);


void	get_devices(t_field *field, char *line);
void	get_geom(t_field *field, char *line);

// Adders
t_vec3	add_vec3(char *vector3);
t_color	add_color(char *color);

// GEOMETRY LIST UTILS
void	ft_geomadd_back(t_geom **lst, t_geom *new_node);
t_geom	*ft_geomlast(t_geom *lst);
void	ft_geom_size(t_geom *head);
void	ft_free_geometry(t_geom **head);
// JUST FOR DEBUGGING
void	ft_print_geometry_node(t_geom *node);
void	ft_print_geometry_full(t_geom *head);
void	ft_print_camera(t_field *field);
void	ft_print_light(t_field *field);
void	ft_print_ambient(t_field *field);

#endif
