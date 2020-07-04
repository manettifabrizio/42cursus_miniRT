/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 21:21:43 by fmanetti          #+#    #+#             */
/*   Updated: 2020/06/23 10:12:52 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

typedef struct		s_cam
{
	t_point			c;
	t_point			v;
	float			alpha;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_light
{
	t_point			c;
	float			rat;
	t_color			clr;
	struct s_light	*next;
}					t_light;

typedef	struct			s_sphere
{
	t_point				c;
	float				d;
	t_color				clr;
}						t_sphere;

typedef struct			s_plane
{
	t_point				p;
	t_point				v;
	t_color				clr;
}						t_plane;

typedef struct			s_square
{
	t_point				p;
	t_point				v;
	float				h;
	t_color				clr;
}						t_square;

typedef struct			s_cylinder
{
	t_point				p;
	t_point				v;
	float				d;
	float				h;
	t_color				clr;
}						t_cylinder;

typedef	struct			s_triangle
{
	t_point				p1;
	t_point				p2;
	t_point				p3;
	t_color				clr;
}						t_triangle;

typedef struct			s_shapes
{
	t_uint				n;
	t_sphere			sp;
	t_plane				pl;
	t_square			sq;
	t_cylinder			cy;
	t_triangle			tr;
	struct s_shapes		*next;
}						t_shapes;

typedef	struct			s_objects
{
	t_cam				*chead;
	int					nc;
	t_light				*lhead;
	int					nl;
	t_shapes			*shead;
	int					ns;
}						t_objects;
