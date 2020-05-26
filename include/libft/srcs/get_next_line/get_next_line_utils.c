/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:51:01 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/24 18:08:44 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		x;
	char	*p;

	i = 0;
	x = 0;
	x = ft_strlen(s1);
	if (!(p = malloc((x + 1) * sizeof(char))))
		return (0);
	while (x--)
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x;
	int		i;
	int		z;
	char	*s3;

	x = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	z = ft_strlen(s1);
	if (!(s3 = (char*)malloc((z + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0')
	{
		s3[x + i] = s2[x];
		x++;
	}
	s3[x + i] = '\0';
	return (s3);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	d;

	d = (char)c;
	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == d)
			return ((char*)&s[i]);
		i++;
	}
	if (s[i] == d)
		return ((char*)&s[i]);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s2;
	size_t			i;
	unsigned int	x;

	i = 0;
	if (!s)
		return (NULL);
	x = ft_strlen(s);
	if (!(s2 = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (start > x)
		return (ft_strdup(""));
	while (i < len)
	{
		s2[i] = s[start + i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
