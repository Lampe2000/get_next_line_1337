/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmisbah <hmisbah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 10:12:58 by ajordan-          #+#    #+#             */
/*   Updated: 2022/10/29 23:50:09 by hmisbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *lstr, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!lstr)
	{
		lstr = (char *)malloc(1 * sizeof(char));
		lstr[0] = '\0';
	}
	if (!lstr || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(lstr) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (lstr)
		while (lstr[++i] != '\0')
			str[i] = lstr[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(lstr) + ft_strlen(buff)] = '\0';
	free(lstr);
	return (str);
}

char	*ft_read_str(int fd, char *str)
{
	char	*buff;
	int		rb;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	rb = 1;
	while (rb != 0)
	{
		rb = read(fd, buff, BUFFER_SIZE);
		if (rb == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[rb] = '\0';
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*ft_get_line(char *lstr)
{
	int		i;
	char	*str;

	i = 0;
	if (!lstr[i])
		return (NULL);
	while (lstr[i] && lstr[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (lstr[i] && lstr[i] != '\n')
	{
		str[i] = lstr[i];
		i++;
	}
	if (lstr[i] == '\n')
	{
		str[i] = lstr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_str(char *lstr)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (lstr[i] && lstr[i] != '\n')
		i++;
	if (!lstr[i])
	{
		free(lstr);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(lstr) - i + 1));
	if (!str)
	{
		free(lstr);
		return (NULL);
	}
	i++;
	j = 0;
	while (lstr[i])
		str[j++] = lstr[i++];
	str[j] = '\0';
	free(lstr);
	return (str);
}
