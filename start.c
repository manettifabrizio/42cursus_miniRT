/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 12:07:43 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/20 21:06:50 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/miniRT.h"

void	start(float **camtowrld, t_ray *ray, t_setting *set)
{
	//inizializzazione basica di una matrice (matrice identità)
	// n * mtx = n
	camtowrld[0][0] = 1; 
	camtowrld[1][1] = 1;
	camtowrld[2][2] = 1;
	camtowrld[3][3] = 1;
	fill_point(0, 0, 0, *(ray->orig)); //orig = vettore origine (0, 0, 0)
	fill_point(0, 0, -1, *(ray->dir)); //dir = vettore direzione OP; O = origine ;P = pixel nell'image plane  
	set->scale =  tan(deg2rad(set->alpha * 0.5)); //alpha = angolo del campo visivo; < alfa = zoom
	set->imageAR = set->width / set->width; //imageAR serve per evitare la deformazione dei pixel
}