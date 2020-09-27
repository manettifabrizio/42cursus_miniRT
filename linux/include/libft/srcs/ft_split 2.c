/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 17:50:16 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/21 01:26:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		count_word(char const *s, char c)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (s[x] != '\0')
	{
		if (s[x] == c)
			while (s[x] == c && s[x] != '\0')
				x++;
		else
		{
			while (s[x] != c && s[x] != '\0')
				x++;
			y++;
		}
	}
	return (y);
}

static char		*fill_string(char const *s, char c, char *t, int y)
{
	int		x;
	int		z;
	int		a;

	x = y;
	a = y;
	z = 0;
	while (s[x] == c && s[x] != '\0')
		x++;
	while (s[x] != c && s[x] != '\0')
		x++;
	if (!(t = malloc((x - y + 1) * sizeof(char))))
		return (NULL);
	while (z < (x - y) && s[a] != '\0')
	{
		t[z] = s[a];
		z++;
		a++;
	}
	t[z] = '\0';
	return (t);
}

static int		set_y(char const *s, char c, int y, int z)
{
	int		x;

	x = 0;
	while (s[y] != '\0')
	{
		if (s[y] == c)
		{
			while (s[y] == c && s[y] != '\0')
				y++;
			x++;
		}
		else
		{
			while (s[y] != c && s[x] != '\0' && z != 1)
				y++;
			x++;
		}
		if (x == z)
			return (y);
	}
	return (y++);
}

static int		free_all(char **t, int x)
{
	while (x)
	{
		free(t[x]);
		x--;
	}
	free(t[x]);
	free(t);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	int		x;
	int		y;
	int		wrd;
	char	**t;

	x = 0;
	y = 0;
	if (!(s))
		return (NULL);
	wrd = count_word(s, c);
	if (!(t = malloc((wrd + 1) * sizeof(char*))))
		return (NULL);
	while (x < wrd)
	{
		if (x == 0)
			y = set_y(s, c, y, 1);
		else
			y = set_y(s, c, y, 2);
		if (!(t[x] = fill_string(s, c, t[x], y)))
			if (!free_all(t, wrd - 1))
				return (NULL);
		x++;
	}
	t[x] = NULL;
	return (t);
}
