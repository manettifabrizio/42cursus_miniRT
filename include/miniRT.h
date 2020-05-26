/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:12:06 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/26 10:16:31 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include "objects.h"
#include "libft/libft.h"
#include "minilibx/mlx.h"

#define F_LIMIT 3.402823466e+38F

void		start(float camtowrld[4][4], t_ray *ray, t_setting *set);

//GRAPH

void		render(float camtowrld[4][4], t_ray *ray, t_setting *set, t_shapes sh);
t_point		cast_ray(t_ray *ray, t_shapes sh);
int			draw(t_point *framebuffer, t_setting *set);
int 		trace(const t_ray *ray, t_shapes sh, float *tnear, t_point *hitobject);

///INTERSECTIONS
int			intersect(const t_ray ray, const t_shapes sh, float *t);
int			sp_intersect(const t_ray ray, const t_shapes sh, float *t);

//UTILITIES

//fill
t_point		fill_point_1(float a);
t_point		fill_point_2(float a, t_point p);
t_point		fill_point_3(float a, float b, float c, t_point p);

//conversion
float		deg2rad(float deg);

t_point		normalize(t_point p);

//GRAPH

//point_ops
t_point		vector_sum(t_point p1, t_point p2);
t_point		vector_sub(t_point p1, t_point p2);
float		point_dist(t_point p1, t_point p2);
float		dot_product_1(t_point p);
float		dot_product_2(t_point p1, t_point p2);
t_point		point_mul(t_point p1, t_point p2);

//matrix_ops
void		mult_pt_mtx(t_point src, float m[4][4], t_point dst);
void		mult_vec_mtx(t_point src, float m[4][4], t_point dst);

//quad_solver
int			quad_solver(const float a, const float b, const float c, float *x0, float *x1);
void		ft_swap_f(float *a, float *b);

//PARSE

void	start_parse(char **argv, t_setting *set);