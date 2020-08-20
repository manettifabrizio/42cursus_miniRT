/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:05:19 by fmanetti          #+#    #+#             */
/*   Updated: 2020/08/19 19:56:54 by fmanetti         ###   ########.fr       */
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

typedef struct		s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*clr;
	int		bpp;
	int		sz_line;
	int		endian;
}					t_mlx;

typedef struct 		s_setting
{
	unsigned int	width;
	unsigned int	heigth;
	float			amblrat; //luminance ratio 
	t_color			amblclr;
	float			scale;
	float			imageAR;
	void			*head;
	t_mlx			d;
}					t_setting;

typedef struct		s_coeff
{
	float a;
	float b;
	float c;
}					t_coeff;

typedef struct		s_cobar
{
	float u;
	float v;
	t_point pvec;
	t_point qvec;
	t_point tvec;
}					t_cobar;