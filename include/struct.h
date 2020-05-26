/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:05:19 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/26 00:32:24 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned int t_uint;

typedef struct		s_point
{
	float	x;
	float	y;
	float	z;
}					t_point;

typedef struct		s_ray
{
	t_point		orig;
	int			t;
	t_point		dir; 
}					t_ray;

typedef struct 		s_setting
{
	unsigned int	width;
	unsigned int	heigth;
	float			alpha; //angolo del campo visivo
	float			scale;
	float			imageAR;
}					t_setting;

typedef	struct		s_coord
{
	float	x1;
	float	x2;
}					t_coord;

typedef	struct 		s_color
{
	t_uint	r;
	t_uint	g;
	t_uint	b;
}					t_color;