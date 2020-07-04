/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:07:43 by fmanetti          #+#    #+#             */
/*   Updated: 2020/06/23 14:48:01 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/miniRT.h"

void	start(float camtowrld[4][4], t_ray *ray, t_setting *set, t_objects *sh)
{
	//inizializzazione basica di una matrice (matrice identità)
	// n * mtx = n
	camtowrld[0][0] = 1; 
	camtowrld[1][1] = 1;
	camtowrld[2][2] = 1;
	camtowrld[3][3] = 1;
	sh->nc = 0;
	sh->nl = 0;
	sh->ns = 0;
	ray->orig.x = 0.0; //orig = vettore origine (0, 0, 0)
	ray->orig.y = 0.0;
	ray->orig.z = 0.0;
	ray->dir.x = 0.0; //dir = vettore direzione OP; O = origine ;P = pixel nell'image plane  
	ray->dir.y = 0.0;
	ray->dir.z = -1;
	 //alpha = angolo del campo visivo; < alfa = zoom
}