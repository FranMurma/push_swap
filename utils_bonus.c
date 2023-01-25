/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:58:57 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/24 19:48:24 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	ft_strlen(char *str)
{
	int	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strchr(char *s, int c)
{
	int	cont;

	cont = 0;
	while (s[cont] != '\0')
	{
		if (s[cont] == (char)c)
			return ((char *)(s + cont));
		cont++;
	}
	if (s[cont] == (char)c)
		return ((char *)(s + cont));
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		cont_s1;
	int		cont_s2;
	char	*s3;

	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	cont_s1 = 0;
	cont_s2 = 0;
	while (s1[cont_s1])
	{
		s3[cont_s1] = s1[cont_s1];
		cont_s1++;
	}
	while (s2[cont_s2])
	{
		s3[cont_s1 + cont_s2] = s2[cont_s2];
		cont_s2++;
	}
	s3[cont_s1 + cont_s2] = '\0';
	return (s3);
}

char	*ft_strdup(char *s1)
{
	char	*str_nueva;
	int		cont;
	int		len;

	len = 0;
	while (s1[len])
		len++;
	str_nueva = malloc(sizeof(char) * (len + 1));
	if (!str_nueva)
		return (NULL);
	cont = 0;
	while (s1[cont])
	{
		str_nueva[cont] = s1[cont];
		cont++;
	}
	str_nueva[cont] = '\0';
	return (str_nueva);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	cont;

	cont = 0;
	while (s1[cont] != '\0' || s2[cont] != '\0')
	{
		if (s1[cont] == s2[cont])
			cont++;
		else
			return (((unsigned char *)s1)[cont] - ((unsigned char *)s2)[cont]);
	}
	return (0);
}
