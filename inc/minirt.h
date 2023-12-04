/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:19:31 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/02 12:19:38 by eavedill         ###   ########.fr       */
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

# define GEO_IDENT "sp pl cy cn"

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

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

typedef struct s_geom
{
	int			type;
	t_vector	pt1;
	t_vector	direction;
	double		r;
	t_color		color;
	void		*next;
}	t_geom;

typedef struct s_camera
{
	t_vector	pos;
	t_vector	orientation;
	int			fov;
}	t_camera;

typedef struct s_light
{
	t_vector	pos;
	t_vector	orientation;
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

//algebra vectorial
t_vector	suma_vector(t_vector a, t_vector b);
t_vector	resta_vector(t_vector a, t_vector b);
t_vector	prod_vectorial(t_vector a, t_vector b);
double		modulo_vector(t_vector a);
double		prod_escalar(t_vector a, t_vector b);

#endif
