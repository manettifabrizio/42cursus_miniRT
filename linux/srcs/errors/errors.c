/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 15:47:39 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/10 11:00:59 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	start_errors(int ac, char **av)
{
	int x;

	if (ac < 2)
	{
		ft_putstr("\033[0;31mError:\033[0m Missing .rt file.\n");
		exit(EXIT_FAILURE);
	}
	else if (ac > 2 && (ft_strcmp(av[2], "-save") != 0))
	{
		ft_putstr("\033[0;31mError:\033[0m Too many arguments.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		x = ft_strlen(av[1]);
		if (!(av[1][x - 1] == 't' && av[1][x - 2] == 'r'
				&& av[1][x - 3] == '.'))
		{
			ft_putstr("\033[0;31mError:\033[0m Invalid file format.\n");
			exit(EXIT_FAILURE);
		}
	}
}

void	mlx_error(t_mlbx mlx, t_objects *obj, t_uint x)
{
	if (x == 1)
		free_lists(obj);
	ft_memdel((void*)&mlx);
	exit(EXIT_FAILURE);
}

void	parse_errors(t_uint x, char **a, int nln)
{
	if (x == 0)
		ft_putstr("\033[0;31mError:\033[0m Allocation failed\n");
	else if (x == 1)
		ft_putstr("\033[0;31mError:\033[0m fd reading failed\n");
	free_array(a, nln);
	exit(EXIT_FAILURE);
}

void	parse_errno(int fd)
{
	ft_putstr("\033[0;31mError:\033[0m fd reading failed\n");
	close(fd);
	exit(EXIT_FAILURE);
}

int		rt_errors(t_uint x, char *obj, int nline)
{
	if (x == 0)
	{
		ft_putstr("\033[0;31mError:\033[0m Multiple declaration of ");
		ft_putstr(obj);
		ft_putstr(" in .rt file at line: ");
	}
	else if (x == 1)
	{
		ft_putstr("\033[0;31mError:\033[0m Wrong Number of Parameters in ");
		ft_putstr(obj);
		ft_putstr(" declaration at line: ");
	}
	else if (x == 2)
	{
		ft_putstr("\033[0;31mError:\033[0m Invalid Value for the ");
		ft_putstr(obj);
		ft_putstr(" at line: ");
	}
	else
		ft_putstr("\033[0;31mError:\033[0m Missing parameters / Wrong type in"
				" .rt file at line: ");
	ft_putnbr(nline + 1);
	ft_putstr(".\n");
	return (-1);
}
