/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcheel-n <jcheel-n@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:19:31 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/03 20:25:29 by jcheel-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "../mlx/mlx.h"
# include "../libft/inc/libft.h"
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
}	t_img_buff;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef struct s_geom
{
	int			type;
	t_vec3	pt1;
	t_vec3	direction;
	double		r;
	t_color		color;
	void		*next;
}	t_geom;

typedef struct s_camera
{
	t_vec3	pos;
	t_vec3	orientation;
	int			fov;
}	t_camera;

typedef struct s_light
{
	t_vec3	pos;
	t_vec3	orientation;
	int			fov;
	void		*next;
}	t_light;

typedef struct s_mouse_pos
{
	int	x;
	int	y;
}	t_mouse_pos;

typedef struct s_field
{
	t_geom		*geom;
	t_color		bck_col;
	t_camera	camera;
	t_light		*light;
}	t_field;

// funciones publicas
//initvars
t_field		*init_vars(char *ac);
void		free_field(t_field *field);

#endif
