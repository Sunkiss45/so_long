/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:48:02 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/30 16:59:25 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_rows(int fd, int y, int v)
{
	char	*line;
	int		len;
	int		ret;

	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (ft_error_int("Return of -1 of gnl 1", -1));
	len = ft_strlen(line);
	free(line);
	y++;
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (ft_error_int("Return of -1 of gnl 1", -1));
		if (line[0] != '\0' && ft_strlen(line) != len)
			v++;
		if (line[0] != '\0')
			y++;
		free(line);
	}
	if (v)
		return (ft_error_int("Maps have different len of line", -1));
	return (y);
}

t_adm	**ft_create_map(t_adm **adm, int fd, int y)
{
	char	*line;
	int		ret;

	ret = get_next_line(fd, &line);
	if (ret == -1)
		return (ft_error("Return of -1 of gnl 2", NULL));
	adm[y] = ft_new_list(adm[y], line, y, 0);
	free(line);
	if (adm[y++] == NULL)
		return (ft_error("Crash of Malloc Create Map", NULL));
	while (ret == 1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (ft_error_frli("Return of -1 of gnl 2", NULL, ret, line));
		if (line[0] == '\0')
			return (ft_free_line(ret, line, adm));
		adm[y] = ft_new_list(adm[y], line, y, 0);
		free(line);
		if (adm[y] == NULL)
			return (ft_error_fral("Crash of Malloc Create Map", NULL, adm, y));
		y++;
	}
	return (adm);
}

t_adm	**ft_parsing(t_adm **adm, char *av)
{
	int	y;

	y = ft_count_rows(open(av, O_RDONLY), 0, 0);
	if (y == -1)
		return (NULL);
	adm = malloc(sizeof(*adm) * y);
	if (adm == NULL)
		return (ft_error("Crash of Malloc **adm", NULL));
	adm = ft_create_map(adm, open(av, O_RDONLY), 0);
	if (adm == NULL)
		return (NULL);
	adm[0]->y = y;
	if (ft_checker(adm, adm[0]->y) > 0)
		return (ft_error_fral("Maps don't have good elements", NULL, adm, y));
	else if (ft_checker(adm, adm[0]->y) < 0)
		return (ft_error_fral("Maps don't have valid walls", NULL, adm, y));
	return (adm);
}

int	ft_file(char *s)
{
	int	i;

	if (open(s, O_DIRECTORY) > 0)
		return (ft_error_int("File is a Directory", 1));
	i = ft_strlen(s) - 1;
	if (ft_strlen(s) >= 5)
		if (s[i] == 114 && s[--i] == 101 && s[--i] == 98 && s[--i] == 46)
			return (0);
	return (ft_error_int("File is not a .ber", 1));
}

int	main(int ac, char **av)
{
	t_adm	**adm;

	adm = NULL;
	if (ac < 2)
		return (ft_error_int("Too few arguments", 1));
	if (ac > 2)
		printf(GREEN"! Only the first argument will be used !"RESET"\n");
	if (ft_file(av[1]))
		return (1);
	adm = ft_parsing(adm, av[1]);
	if (adm == NULL)
		return (1);
	all_display(adm);
	ft_free_allist(adm, adm[0]->y, NULL);
	return (0);
}
