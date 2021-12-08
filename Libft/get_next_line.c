/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 13:31:32 by iderighe          #+#    #+#             */
/*   Updated: 2021/12/08 13:48:17 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_n(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strcut_gnl(char *str)
{
	char	*cut_to_n;
	int		i;

	cut_to_n = malloc(sizeof(char) * (ft_strn(str) + 1));
	if (cut_to_n == NULL)
		return (NULL);
	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '\n')
		{
			cut_to_n[i] = str[i];
			i++;
		}
	}
	cut_to_n[i] = '\0';
	return (cut_to_n);
}

char	*ft_saver(char *str)
{
	int	i;
	int	j;

	if (!str)
		return (NULL);
	i = ft_strn(str);
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	if (str && str[i])
		i++;
	j = 0;
	while (str && str[i])
	{
		str[j] = str[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

void	yenamarre(char **line, int fd, char **str)
{
	*line = ft_strcut_gnl(str[fd]);
	str[fd] = ft_saver(str[fd]);
	return ;
}

int	get_next_line(int fd, char **line)
{
	static char	*str[1024];
	int			r;
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	r = 1;
	if (ft_check_n(str[fd]) == 0)
		r = read(fd, buf, BUFFER_SIZE);
	while (ft_check_n(str[fd]) == 0 && r != 0)
	{
		if (r == -1)
			return (-1);
		buf[r] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin_gnl(tmp, buf);
		free(tmp);
		if (ft_check_n(str[fd]) == 0)
			r = read(fd, buf, BUFFER_SIZE);
	}
	yenamarre(line, fd, str);
	if (r == 0)
		return (0);
	return (1);
}
