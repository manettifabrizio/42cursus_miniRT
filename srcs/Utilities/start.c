/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:07:43 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/07 19:48:20 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	start(float camtowrld[4][4], t_ray *ray, t_setting *set, t_objects *obj)
{
	//inizializzazione basica di una matrice (matrice identità)
	// n * mtx = n
	camtowrld[0][0] = 1; 
	camtowrld[1][1] = 1;
	camtowrld[2][2] = 1;
	camtowrld[3][3] = 1;
	obj->nc = 0;
	obj->nl = 0;
	obj->ns = 0;
	// ray->orig.x = obj->chead->c.x; //orig = vettore origine (0, 0, 0)
	// ray->orig.y = obj->chead->c.y;
	// ray->orig.z = obj->chead->c.z;
	// ray->dir.x = obj->chead->v.x; //dir = vettore direzione OP; O = origine ;P = pixel nell'image plane  
	// ray->dir.y = obj->chead->v.y;
	// ray->dir.z = obj->chead->v.z;
	 //alpha = angolo del campo visivo; < alfa = zoom
}