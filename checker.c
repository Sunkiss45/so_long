/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 16:08:42 by ebarguil          #+#    #+#             */
/*   Updated: 2021/12/03 18:41:57 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_nb(t_adm *adm)
{
	t_dll	*now;
	int		i;

	now = adm->head;
	if (!now)
		return (0);
	i = 1;
	while (now->r != NULL)
	{
		i++;
		now = now->r;
	}
	return (i);
}

int	ft_count_elm(t_adm **adm, t_dll *now, int y, int *v)
{
	v[1] = 0;
	v[2] = 0;
	v[3] = 0;
	v[0] = -1;
	while (++v[0] < y)
	{
		now = adm[v[0]]->head;
		while (now != NULL)
		{
			if (now->c == 'P' && v[1]++ != -1)
				adm[0]->play = now;
			else if (now->c == 'E')
				v[2]++;
			else if (now->c == 'C')
				v[3]++;
			else if (now->c != '1' && now->c != '0')
				return (1);
			now = now->r;
		}
	}
	if (v[1] != 1 || v[2] <= 0 || v[3] <= 0)
		return (1);
	adm[0]->col = v[3];
	return (0);
}

/*int	ft_doubl(t_adm **adm, int y)
{
	
}*/

int	ft_checker(t_adm **adm, int y)
{
	t_dll	*now;
	int		z[4];
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
					return (ft_error_int("Maps don't have valid walls", 1));
				now = now->r;
			}
		}
		else if (adm[v]->head->c != '1' || adm[v]->tail->c != '1')
			return (ft_error_int("Maps don't have valid walls", 1));
	}
	if (ft_count_elm(adm, now, y, z))
		return (ft_error_int("Maps don't have good elements", 1));
	return (0);
}
