/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_pto_vector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 12:21:33 by eavedill          #+#    #+#             */
/*   Updated: 2023/12/02 12:23:54 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

double  dist_pto_vector(t_vector p1, t_vector p2, t_vector v)
{
    double      out;
    double      prod;
    t_vector    v2;

    v2 = resta_vector(p1, p2);
    prod = prod_escalar(v, v2);

    out = sqrt(prod_escalar(v2, v2) - prod * prod + prod_escalar(v, v));
    return (out);
}