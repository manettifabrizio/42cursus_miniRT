/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:12:06 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/20 21:11:07 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "struct.h"

typedef unsigned int t_uint;

void	start(float **camtowrld, t_ray *ray, t_setting *set);
void	render(float **camtowrld, t_ray *ray, t_setting *set);

//UTILITIES

//fill
t_point		fill_point(float a, float b, float c, t_point p);

//conversion
float		deg2rad(float deg);

//point_ops
t_point		point_sum(t_point p1, t_point p2);

//matrix_ops
void		mult_pt_mtx(t_point src, float **m, t_point dst);
void		mult_vec_mtx(t_point src, float **m, t_point dst);

t_point		normalize(t_point p);