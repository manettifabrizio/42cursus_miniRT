/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 14:05:19 by fmanetti          #+#    #+#             */
/*   Updated: 2020/09/19 17:17:02 by fmanetti         ###   ########.fr       */
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

typedef struct 		s_matrix
{
	t_point a;
	t_point	b;
	t_point	c;
}					t_matrix;

typedef struct 		s_setting
{
	int				width;
	int				heigth;
	double			amblrat;
	t_color			amblclr;
	double			imageAR;
	void			*head;
	t_mlx			d;
	t_uint			save;
	t_matrix		xmtx;
	t_matrix		ymtx;
	int				inversex;
	int				inversey;
}					t_setting;
