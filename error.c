/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:59:38 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/30 16:56:13 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_error(char *s, void *r)
{
	int	i;

	i = -1;
	printf(RED"\n");
	write(2, "Error\n", 6);
	while (s[++i])
		write(2, &s[i], 1);
	printf(RESET"\n\n");
	return (r);
}

void	*ft_error_frli(char *s, void *r, int ret, char *line)
{
	ft_error(s, NULL);
	ft_free_line(ret, line, NULL);
	return (r);
}

void	*ft_error_fral(char *s, void *r, t_adm **adm, int y)
{
	ft_error(s, NULL);
	ft_free_allist(adm, y, NULL);
	return (r);
}

int	ft_error_int(char *s, int r)
{
	ft_error(s, NULL);
	return (r);
}
