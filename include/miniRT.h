/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 21:12:06 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/10 18:54:34 by fmanetti         ###   ########.fr       */
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
#define BIAS	1e-04
extern int errno ;

void		start(t_ray *ray, t_setting *set, t_objects *sh);

//GRAPH

void		render(t_ray *ray, t_setting *set, t_objects sh);
t_color		cast_ray(t_ray *ray, t_setting set, t_objects obj);
int			trace(const t_ray *ray, t_objects *obj, double *tnear,
				t_shapes *hitobj);

//INTERSECTIONS
int			intersect(const t_ray ray, t_shapes *sh, double *t);
int			sp_intersect(const t_ray ray, t_shapes *sh, double *t);
int			pl_intersect(const t_ray ray, t_shapes *sh, double *t);
int			sq_intersect(const t_ray ray, t_shapes *sh, double *t);
int			cy_intersect(const t_ray ray, t_shapes *sh, double *t);
int     	tr_intersect(const t_ray ray, t_shapes *sh, double *t);

//WINDOW
int			draw(t_color *framebuffer, t_setting *set);
int			key_hook(int key, void *param);
int			close_hook(void);

//UTILITIES

//fill
t_point		fill_p_1(double a);
t_point		fill_p(double a, double b, double c);
t_color		fill_clr_3(double a, double b, double c);
int			my_atoi(const char *s, t_uint *y);
double		my_atof(const char *s, t_uint *i);

//var0
int			check(char *line, t_uint y);
void		print_point(t_point p, char *s);
void		print_clr(t_color p, char *s);

//MATH

//rotation
t_point		compute_rot(t_point dir, t_point ax1, t_point ax2);

//conversion
double		deg2rad(double deg);

//norm
t_point		normalize(t_point p);
double		norm(t_point p);

//distance
double		point_dist(t_point p1, t_point p2);
t_point		pointplane_dist(const t_ray ray, const t_plane pl);

//point_ops
t_point		sum(t_point p1, t_point p2);
t_point		sub(t_point p1, t_point p2);
double		dot_1(t_point p);
double		dot_2(t_point p1, t_point p2);
t_point		cross_2(t_point p1, t_point p2);
t_point		mul(t_point p1, double x);
t_color		clr_mul(t_color clr, double x);

//matrix_ops
void		mult_pt_mtx(t_point src, double m[4][4], t_point dst);
t_point		mult_vec_mtx(t_point p, t_matrix m);

//quad_solver
int			quad_solver(const t_coeff q, double *t0, double *t1);
void		ft_swap_f(double *a, double *b);

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
int			ft_lstsize_c(t_cam *lst);
int			ft_lstsize_l(t_light *lst);
int			ft_lstsize_s(t_shapes *lst);

//ERRORS

void	parse_errors(t_uint line, int x);
void	parse_errno(int errnum);
void	mlx_error(t_mlx d);