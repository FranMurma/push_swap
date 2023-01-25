/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frmurcia <frmurcia@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 15:34:30 by frmurcia          #+#    #+#             */
/*   Updated: 2023/01/24 18:48:25 by frmurcia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str_new;
	size_t	len_s;
	size_t	cont;

	len_s = 0;
	while (s[len_s])
		len_s++;
	if (len_s < start)
		len = 0;
	else if (len >= (len_s - start))
		len = len_s - start;
	str_new = malloc(sizeof(char) * (len + 1));
	if (!str_new)
		return (NULL);
	cont = 0;
	while (cont < len)
	{
		str_new[cont] = s[start];
		cont++;
		start++;
	}
	str_new[cont] = '\0';
	return (str_new);
}

char	*ft_xtraspace(char *fed)
{
	int		i;
	int		j;
	char	*rest;

	i = 0;
	j = 0;
	while (fed[i] && fed[i] != '\n')
		i++;
	if (!fed[i])
	{
		free(fed);
		return (NULL);
	}
	if (fed[i] == '\n')
		i++;
	rest = malloc(sizeof(char) * (ft_strlen(fed) - i + 1));
	if (!rest)
		return (NULL);
	while (fed[i])
		rest[j++] = fed [i++];
	rest[j] = '\0';
	free(fed);
	return (rest);
}

char	*ft_read(int fd, char *fed)
{
	int		bytes;
	char	*temp;

	bytes = 1;
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	while (!ft_strchr(fed, '\n') && bytes != 0)
	{
		bytes = read(fd, temp, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(temp);
			free(fed);
			return (NULL);
		}
		temp[bytes] = '\0';
		fed = ft_strjoin(fed, temp);
	}
	free(temp);
	return (fed);
}

char	*get_next_line(int fd)
{
	int			cont;
	char		*line;
	static char	*fed;

	cont = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!fed)
		fed = ft_strdup("");
	fed = ft_read(fd, fed);
	if (!fed)
	{
		free(fed);
		return (NULL);
	}
	while (fed[cont] != '\n' && fed[cont])
		cont++;
	line = ft_substr(fed, 0, cont + 1);
	fed = ft_xtraspace(fed);
	if (!line || !line[0])
	{
		free(line);
		return (NULL);
	}
	return (line);
}
