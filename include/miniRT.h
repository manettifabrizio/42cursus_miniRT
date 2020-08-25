/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:12:06 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/25 10:41:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "objects.h"
#include "libft/libft.h"
#include "minilibx/mlx.h"

#define F_LIMIT 3.402823466e+38F
extern int errno ;

void		start(float camtowrld[4][4], t_ray *ray, t_setting *set, \
			t_objects *sh);

//GRAPH

void		render(float camtowrld[4][4], t_ray *ray, t_setting *set, \
				t_objects sh);
t_color		cast_ray(t_ray *ray, t_setting set, t_objects obj);
int			trace(const t_ray *ray, t_objects *obj, float *tnear, \
				t_shapes *hitobj);

//INTERSECTIONS
int			intersect(const t_ray ray, t_shapes *sh, float *t);
int			sp_intersect(const t_ray ray, t_shapes *sh, float *t);
int			pl_intersect(const t_ray ray, const t_plane pl, float *t, \
				t_color *objcolor);
int			sq_intersect(const t_ray ray, const t_square sq, float *t, \
				t_color *objcolor);
int			cy_intersect(const t_ray ray, const t_cylinder cy, float *t, \
				t_color *objcolor);
int     	tr_intersect(const t_ray ray, const t_triangle tr, float *t, \
		    	t_color *objcolor);

//WINDOW
int			draw(t_color *framebuffer, t_setting *set);
int			key_hook(int key, void *param);
int			close_hook(void);

//UTILITIES

//fill
t_point		fill_point_1(float a);
t_point		fill_point_3(float a, float b, float c);
t_color		fill_clr_3(float a, float b, float c);
int			my_atoi(const char *s, t_uint *y);
float		my_atof(const char *s, t_uint *i);

//var0
int			check(char *line, t_uint y);
void		print_point(t_point p, char *s);

//conversion
float		deg2rad(float deg);

t_point		normalize(t_point p);

//MATH

//distance
float		point_dist(t_point p1, t_point p2);
t_point		pointplane_dist(const t_ray ray, const t_plane pl);

//point_ops
t_point		vec_sum(t_point p1, t_point p2);
t_point		vec_sub(t_point p1, t_point p2);
float		dot_1(t_point p);
float		dot_2(t_point p1, t_point p2);
t_point		cross_2(t_point p1, t_point p2);
t_point		point_mul(t_point p1, t_point p2);

//matrix_ops
void		mult_pt_mtx(t_point src, float m[4][4], t_point dst);
void		mult_vec_mtx(t_point src, float m[4][4], t_point dst);

//quad_solver
int			quad_solver(const t_coeff q, float *t0, float *t1);
void		ft_swap_f(float *a, float *b);

//PARSE

void		start_parse(char **av, t_setting *set, t_objects *obj);
int			fill_res(char *line, t_setting *set);
int			fill_ambl(char *line, t_setting *set);
int			fill_cam(char *line, t_objects *obj);
int			fill_light(char *line, t_objects *obj);
int			fill_sphere(char *line, t_objects *obj);
int			fill_plane(char *line, t_objects *obj);
int			fill_square(char *line, t_objects *obj);
int			fill_cylinder(char *line, t_objects *obj);
int			fill_triangle(char *line, t_objects *obj);

//LST_CHECK

int			lst_check_c(t_cam **head, int y, t_cam **tmp);
int			lst_check_l(t_light **head, int y, t_light **tmp);
int			lst_check_s(t_shapes **head, int y, t_shapes **tmp);
t_cam		*ft_lstnew_c();
t_light		*ft_lstnew_l();
t_shapes	*ft_lstnew_s();
void		ft_lstadd_back_c(t_cam **alst, t_cam *new);
void		ft_lstadd_back_l(t_light **alst, t_light *new);
void		ft_lstadd_back_s(t_shapes **alst, t_shapes *new);
t_cam		*ft_lstlast_c(t_cam *lst);
t_light		*ft_lstlast_l(t_light *lst);
t_shapes	*ft_lstlast_s(t_shapes *lst);

//ERRORS

void	parse_errors(t_uint line, int x);
void	parse_errno(int errnum);
void	mlx_error(t_mlx d);