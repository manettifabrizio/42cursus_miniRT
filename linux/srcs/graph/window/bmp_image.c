/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 00:15:04 by fmanetti          #+#    #+#             */
/*   Updated: 2020/10/06 16:08:19 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		charging_bar(int x, int y, int width, int heigth)
{
	int n;

	x += (width * y);
	n = ((width - 1) * (heigth - 1)) / 100;
	if (x % (int)n == 0)
	{
		ft_putstr("\rCreating BMP image...");
		ft_putstr(" [");
		ft_putnbr(100 - (x / n));
		ft_putstr("%]");
	}
	if (x == 0)
	{
		ft_putchar('\n');
		ft_putstr("[ miniRT ] BMP Image created ");
		ft_putstr("\033[0;32mSuccessfully\n\033[0m");
	}
}

static void		write_number_in_file(int nb, int fd)
{
	write(fd, &nb, sizeof(int));
}

static void		write_header(int fd, int width, int heigth)
{
	write(fd, "BM", 2);
	write_number_in_file(54 + 4 * width * heigth, fd);
	write_number_in_file(0, fd);
	write_number_in_file(54, fd);
	write_number_in_file(40, fd);
	write_number_in_file(width, fd);
	write_number_in_file(heigth, fd);
	write_number_in_file(2097153, fd);
	write_number_in_file(0, fd);
	write_number_in_file(0, fd);
	write_number_in_file(0, fd);
	write_number_in_file(0, fd);
	write_number_in_file(0, fd);
	write_number_in_file(0, fd);
}

void			create_bmp(char *clr, int width, int heigth)
{
	int		fd;
	char	c;
	int		y;
	int		x;

	fd = open("./image.bmp", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
	write_header(fd, width, heigth);
	ft_putchar('\n');
	y = heigth;
	while (--y >= 0)
	{
		x = -1;
		while (++x < width)
		{
			c = clr[(y * width + x) * 4];
			write(fd, &c, 1);
			c = clr[(y * width + x) * 4 + 1];
			write(fd, &c, 1);
			c = clr[(y * width + x) * 4 + 2];
			write(fd, &c, 1);
			c = (char)255;
			write(fd, &c, 1);
			charging_bar(x, y, width, heigth);
		}
	}
}
