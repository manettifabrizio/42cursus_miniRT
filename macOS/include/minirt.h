/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 20:20:52 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/07 11:02:17 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "objects.h"
# include "libft/libft.h"
# include "minilibx/mlx.h"

# define F_LIMIT 3.402823466e+38F
# define BIAS	1e-04
# define MAX_WIDTH 1680
# define MAX_HEIGTH 1050

void		render(t_ray *ray, t_setting set, t_objects obj);
t_color		cast_ray(t_ray ray, t_setting set, t_objects obj);
int			trace(const t_ray ray, t_objects *obj, double *tnear,
				t_shapes *hitobj);
int			intersect(const t_ray ray, t_shapes *sh, double *t);
int			sp_intersect(const t_ray ray, t_shapes *sh, double *t);
int			pl_intersect(const t_ray ray, t_shapes *sh, double *t);
int			sq_intersect(const t_ray ray, t_shapes *sh, double *t);
int			cy_intersect(const t_ray ray, t_shapes *sh, double *t);
int			tr_intersect(const t_ray ray, t_shapes *sh, double *t);
int			draw(t_color *clr, t_setting set, t_objects obj);
int			key_hook(int key, void *param);
int			close_hook(void);
void		create_bmp(char *clr, int width, int heigth);
t_point		fill_p_1(double a);
t_point		fill_p(double a, double b, double c);
t_color		fill_clr_3(double a, double b, double c);
int			my_atoi(const char *s, int *i, t_parse p, char *obj);
double		my_atof(const char *s, int *i, t_parse p, char *obj);
int			emptyline_or_comment(char *s);
int			check(char *line, t_uint y);
int			check_norm(t_point p, char *s, t_uint nln);
int			check_clr(t_color c, char *s, t_uint nln);
t_uint		lines_nbr(char *av);
t_matrix	compute_rot(t_point ax1, t_point ax2, t_setting *set);
double		deg2rad(double deg);
t_point		normalize(t_point p);
double		norm(t_point p);
double		point_dist(t_point p1, t_point p2);
t_point		sum(t_point p1, t_point p2);
t_point		sub(t_point p1, t_point p2);
double		dot_1(t_point p);
double		dot_2(t_point p1, t_point p2);
t_point		cross_2(t_point p1, t_point p2);
t_point		mul(t_point p1, double x);
t_color		clr_sum(t_color clr0, t_color clr1);
t_color		clr_mul(t_color clr0, double t);
t_color		mix_clr(t_color light, t_color shape, double ratio);
t_color		max_clr(t_color clr, t_color objclr);
t_point		mult_vec_mtx(t_point p, t_matrix m);
int			quad_solver(const t_coeff q, double *t0, double *t1);
void		ft_swap_f(double *a, double *b);
void		parse(char **av, t_setting *set, t_objects *obj);
int			fill_res(char *line, t_parse p, t_setting *set);
int			fill_ambl(char *line, t_parse p, t_setting *set);
int			fill_cam(char *line, t_parse p, t_objects *obj);
int			fill_light(char *line, t_parse p, t_objects *obj);
int			fill_sphere(char *line, t_parse p, t_objects *obj);
int			fill_plane(char *line, t_parse p, t_objects *obj);
int			fill_square(char *line, t_parse p, t_objects *obj);
int			fill_cylinder(char *line, t_parse p, t_objects *obj);
int			fill_triangle(char *line, t_parse p, t_objects *obj);
int			lst_check_c(t_cam **head, int y, t_cam **tmp);
int			lst_check_l(t_light **head, int y, t_light **tmp);
int			lst_check_s(t_shapes **head, int y, t_shapes **tmp);
t_cam		*ft_lstnew_c(void);
t_light		*ft_lstnew_l(void);
t_shapes	*ft_lstnew_s(void);
void		ft_lstadd_back_c(t_cam **alst, t_cam *new);
void		ft_lstadd_back_l(t_light **alst, t_light *new);
void		ft_lstadd_back_s(t_shapes **alst, t_shapes *new);
t_cam		*ft_lstlast_c(t_cam *lst);
t_light		*ft_lstlast_l(t_light *lst);
t_shapes	*ft_lstlast_s(t_shapes *lst);
int			ft_lstsize_c(t_cam *lst);
int			ft_lstsize_l(t_light *lst);
int			ft_lstsize_s(t_shapes *lst);
void		start_errors(int ac, char **av);
void		mlx_error(t_mlbx d);
void		parse_errors(t_uint x, char **a, int nln);
void		parse_errno(int fd);
int			rt_errors(t_uint x, char *obj, int nline);
void		free_array(char **a, int nln);
void		free_lists(t_objects *obj);
void		ft_lstclear_c(t_cam **lst);
void		ft_lstclear_l(t_light **lst);
void		ft_lstclear_s(t_shapes **lst);

#endif
