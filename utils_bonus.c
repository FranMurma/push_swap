/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:58:57 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/25 18:50:29 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
