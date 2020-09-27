/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:07:37 by fmanetti          #+#    #+#             */
/*   Updated: 2020/05/21 01:26:27 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int		x;
	int		len;
	char	*s1;

	x = 0;
	if (!s || !f)
		return (0);
	len = ft_strlen(s);
	if (!(s1 = malloc((len + 1) * sizeof(char))))
		return (0);
	while (s[x] != '\0')
	{
		s1[x] = f(x, s[x]);
		x++;
	}
	s1[x] = '\0';
	return (s1);
}
