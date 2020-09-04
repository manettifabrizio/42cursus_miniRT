/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:05:19 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/02 13:23:38 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef unsigned int t_uint;

typedef struct		s_point
{
	double	x;
	double	y;
	double	z;
}					t_point;

typedef struct		s_ray
{
	t_point		orig;
	int			t;
	t_point		dir; 
}					t_ray;

typedef	struct		s_coord
{
	double	x1;
	double	x2;
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
	double			amblrat; //luminance ratio 
	t_color			amblclr;
	double			scale;
	double			imageAR;
	void			*head;
	t_mlx			d;
}					t_setting;

typedef struct		s_coeff
{
	double a;
	double b;
	double c;
}					t_coeff;

typedef struct		s_cobar
{
	double u;
	double v;
	t_point pvec;
	t_point qvec;
	t_point tvec;
}					t_cobar;