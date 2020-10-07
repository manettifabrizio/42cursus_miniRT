/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 21:21:43 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/07 17:38:01 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "struct.h"

typedef struct			s_cam
{
	t_point				p;
	t_point				n;
	t_point				cx;
	t_point				cy;
	t_point				cz;
	double				alpha;
	double				scale;
	struct s_cam		*next;
}						t_cam;

typedef struct			s_light
{
	t_point				p;
	double				rat;
	t_color				clr;
	t_point				dir;
	t_ray				shray;
	struct s_light		*next;
}						t_light;

typedef	struct			s_sphere
{
	t_point				c;
	double				diam;
	t_color				clr;
}						t_sphere;

typedef struct			s_plane
{
	t_point				p;
	t_point				n;
	t_color				clr;
}						t_plane;

typedef struct			s_square
{
	t_point				p;
	t_point				n;
	t_point				v0;
	t_point				v1;
	t_point				v2;
	t_point				v3;
	double				h;
	t_color				clr;
}						t_square;

typedef struct			s_cylinder
{
	t_point				p;
	t_point				n;
	double				diam;
	double				h;
	t_color				clr;
}						t_cylinder;

typedef	struct			s_triangle
{
	t_point				v0;
	t_point				v1;
	t_point				v2;
	t_point				n;
	t_color				clr;
}						t_triangle;

typedef struct			s_shapes
{
	t_uint				type;
	t_sphere			sp;
	t_plane				pl;
	t_square			sq;
	t_cylinder			cy;
	t_triangle			tr;
	t_point				phit;
	t_point				nhit;
	t_color				objclr;
	struct s_shapes		*next;
}						t_shapes;

typedef	struct			s_objects
{
	t_cam				*chead;
	t_cam				*ctmp;
	int					ntmp;
	int					nc;
	t_light				*lhead;
	t_light				*ltmp;
	int					nl;
	t_shapes			*shead;
	t_shapes			hitobj;
	t_shapes			hitobj2;
	int					ns;
}						t_objects;

typedef	struct			s_hook
{
	t_setting			set;
	t_objects			obj;
}						t_hook;

typedef struct			s_parse
{
	char				**rtfile;
	char				*objname;
	t_uint				nln;
	t_objects			*obj;
}						t_parse;

#endif
