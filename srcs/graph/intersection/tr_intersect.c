/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tr_intersect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 16:27:16 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/02 13:22:20 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/miniRT.h"

// static int  in_out_check(const t_triangle tr, t_point p)
// {
//     // print_point(tr.v0);
//     // print_point(tr.v1);
//     // print_point(tr.v2);
//     if (dot_2(tr.n, cross_2(vec_sub(tr.v1, tr.v0), vec_sub(p, tr.v0))) > 0 &&
//         dot_2(tr.n, cross_2(vec_sub(tr.v2, tr.v1), vec_sub(p, tr.v1))) > 0 &&
//         dot_2(tr.n, cross_2(vec_sub(tr.v0, tr.v2), vec_sub(p, tr.v2))) > 0)
//             return (1);
//     // printf ("ciao\n");
//     return (0);
// }
			//Geometry solution
// int     tr_intersect(const t_ray ray, const t_triangle tr, double *t, \
// 		    t_color *objcolor)
// {
//     double denom;
//     t_point phit;
    
//     printf("tr.dist = %f\n", tr.dist);
//     denom = dot_2(tr.n, ray.dir);
//     if (fabs(denom) == 0) //raggio parallelo al triangolo
//         return (0);
//     if ((*t = (dot_2(tr.n, ray.orig) + tr.dist) / denom) < 0)
//         return (0);
//     phit = vec_sum(ray.orig, point_mul(ray.dir, fill_point_1(*t)));
//     // print_point(phit);
//     if (in_out_check(tr, phit))
//     {
//         // printf("ciao\n");
//         *objcolor = tr.clr; 
//         return (1);
//     }
//     return (0);
// }

		//Möller-Trumbore algorithm
int     tr_intersect(const t_ray ray, t_shapes *sh, double *t)
{
    double 	det;
	t_cobar	c;

	c.pvec = cross_2(ray.dir, vec_sub(sh->tr.v2, sh->tr.v0));
	det = dot_2(vec_sub(sh->tr.v1, sh->tr.v0), c.pvec);
    if (fabs(det) < 1e-08) //caso raggio parallelo al sh->triangolo
		return (0);
	c.tvec = vec_sub(ray.orig, sh->tr.v0);
	c.u = dot_2(c.tvec, c.pvec) * (1 / det);
	if (c.u < 0 || c.u > 1)
		return (0);
	c.qvec = cross_2(c.tvec, vec_sub(sh->tr.v1, sh->tr.v0));
	c.v = dot_2(ray.dir, c.qvec) * (1 / det);
	if (c.v < 0 || c.u + c.v > 1)
		return (0);
	*t = dot_2(vec_sub(sh->tr.v2, sh->tr.v0), c.qvec) * (1 / det);
	sh->objclr = sh->tr.clr;
	return (1);
}