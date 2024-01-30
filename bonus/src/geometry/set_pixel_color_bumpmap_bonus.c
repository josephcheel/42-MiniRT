/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pixel_color_bumpmap_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcelona>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 13:06:02 by jcheel-n          #+#    #+#             */
/*   Updated: 2024/01/30 11:04:49 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

t_vec3	get_distance(t_int_pts *vp_int)
{
	t_vec3	out;

	out = vp_int->pt.pt;
	if (vp_int->geom->type == PLANE || vp_int->geom->type == TRIANGLE)
	{
		out = resta_vector(vp_int->pt.pt, vp_int->geom->vp.pt);
		out = cambio_coord_vect(out, vp_int->ref);
	}
	return (out);
}

t_indexes	get_indexes(t_vec3 pos, t_geom *geom)
{
	t_indexes	out;
	int			aux;

	aux = (int)fmod(pos.x / BM_DEFINIT, geom->bumpmap.width);
	if (aux == 0)
		out.i = 0;
	else if (aux < 0)
		out.i = (int)((aux + geom->bumpmap.width));
	else
		out.i = (int)((geom->bumpmap.width - aux));
	aux = (int)fmod(pos.y / BM_DEFINIT, geom->bumpmap.height);
	if (aux == 0)
		out.j = 0;
	else if (aux < 0)
		out.j = (int)(aux + geom->bumpmap.height);
	else
		out.j = (int)(geom->bumpmap.height - aux);
	return (out);
}

void	set_pixel_color_bumpmap(t_int_pts *vp_int, t_field *field)
{
	t_vec_pos	out;
	t_indexes	ind;

	(void)field;
	out.pt = get_distance(vp_int);
	ind = get_indexes(out.pt, vp_int->geom);
	out = vp_int->geom->bumpmap.normal_map[ind.i + ind.j * \
				vp_int->geom->bumpmap.width];
	if (out.c.h != 0 && out.c.s != 0)
		vp_int->pt.c = out.c;
	vp_int->pt.v = cambio_coord_vect(out.v, mat_inversa(vp_int->ref));
	return ;
}

/*
Data for testing in case error
	if (ind.i + ind.j * vp_int->geom->bumpmap.width < 0 ||
		ind.i + ind.j * vp_int->geom->bumpmap.width >= vp_int->geom->bumpmap.width * vp_int->geom->bumpmap.height)
	{
		printf("###############punto visionado##########################################\n");
		ft_print_vec3("valor causante del desastre", vp_int->pt.pt);
		ft_print_vec3("centro de la geometria visionada.", vp_int->geom->vp.pt);
		ft_print_vec3("dirección geometria visionada ", vp_int->geom->vp.v);
		printf("********sistema de referencia punto**********\n");
		ft_print_vec3("vector resta", resta_vector(vp_int->pt.pt, vp_int->geom->vp.pt));
		ft_print_vec3("eje X sistema ref local", vp_int->ref.vx);
		ft_print_vec3("eje Y sistema ref local", vp_int->ref.vy);
		ft_print_vec3("eje Z sistema ref local", vp_int->ref.vz);
		printf("********sistema de referencia punto**********\n");
		ft_print_vec3("vector resta en coord locales", cambio_coord_vect(resta_vector(vp_int->pt.pt, vp_int->geom->vp.pt), vp_int->ref));
		printf("cálculo del índice i: fmod(%f, %i) = %f --> %i \n", out.pt.x, vp_int->geom->bumpmap.width, fmod(out.pt.x, vp_int->geom->bumpmap.width), ind.i);
		printf("cálculo del índice j: fmod(%f, %i) = %f --> %i \n", out.pt.y, vp_int->geom->bumpmap.height, fmod(out.pt.y, vp_int->geom->bumpmap.height), ind.j);
		printf("redondeo fmod de j %f\n", fmod(out.pt.y, vp_int->geom->bumpmap.height) + vp_int->geom->bumpmap.height);
		printf("redondeo fmod de j %f\n", vp_int->geom->bumpmap.height - fmod(out.pt.y, vp_int->geom->bumpmap.height));
		printf("valores resultante de vector direccion %i + %i * %i = %i \n", ind.i, ind.j, vp_int->geom->bumpmap.width, ind.i + ind.j * vp_int->geom->bumpmap.width);
	}
	*/