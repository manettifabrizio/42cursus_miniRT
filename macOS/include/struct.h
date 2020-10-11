/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:05:19 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/09 23:35:56 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef unsigned int	t_uint;

typedef struct			s_point
{
	double				x;
	double				y;
	double				z;
}						t_point;

typedef struct			s_ray
{
	t_point				orig;
	int					t;
	t_point				dir;
}						t_ray;

typedef	struct			s_coord
{
	double				x1;
	double				x2;
}						t_coord;

typedef	struct			s_color
{
	int					r;
	int					g;
	int					b;
}						t_color;

typedef struct			s_coeff
{
	double				a;
	double				b;
	double				c;
}						t_coeff;

typedef struct			s_cobar
{
	double				u;
	double				v;
	t_point				pvec;
	t_point				qvec;
	t_point				tvec;
}						t_cobar;

typedef struct			s_matrix
{
	t_point				a;
	t_point				b;
	t_point				c;
}						t_matrix;

typedef struct			s_setting
{
	int					width;
	int					heigth;
	double				amblrat;
	t_color				amblclr;
	double				imagear;
	t_uint				save;
	t_matrix			xmtx;
	t_matrix			ymtx;
	int					inversex;
	int					inversey;
}						t_setting;

#endif
