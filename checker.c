/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:08:42 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/30 16:59:12 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_count_elm(t_adm **adm, t_dll *now, int y)
{
	int	v[4];

	v[1] = 0;
	v[2] = 0;
	v[3] = 0;
	v[0] = -1;
	while (++v[0] < y)
	{
		now = adm[v[0]]->head;
		while (now != NULL)
		{
			if (now->c == 'P')
				v[1]++;
			if (now->c == 'E')
				v[2]++;
			if (now->c == 'C')
				v[3]++;
			now = now->r;
		}
	}
	if (v[1] != 1 || v[2] <= 0 || v[3] <= 0)
		return (1);
	return (0);
}

int	ft_checker(t_adm **adm, int y)
{
	t_dll	*now;
	int		v;

	v = -1;
	while (++v < y)
	{
		now = adm[v]->head;
		if (v == 0 || v == y - 1)
		{
			while (now != NULL)
			{
				if (now->c != '1')
					return (-1);
				now = now->r;
			}
		}
		else if (adm[v]->head->c != '1' || adm[v]->tail->c != '1')
			return (-1);
	}
	if (ft_count_elm(adm, now, y))
		return (1);
	return (0);
}
