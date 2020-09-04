/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 21:21:43 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/02 16:30:26 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

typedef struct		s_cam
{
	t_point			p;
	t_point			n;
	double			alpha;
	struct s_cam	*next;
}					t_cam;

typedef struct		s_light
{
	t_point			p;
	double			rat;
	t_color			clr;
	t_point			dir;
	t_ray			shray;
	t_color			intensity;
	struct s_light	*next;
}					t_light;

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
	double				dist;
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
	double				objalb; //solo per le luci dirette
	t_color				objclr;
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
