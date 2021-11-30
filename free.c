/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:20:58 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/29 21:41:16 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_adm	*ft_free_list(t_adm *adm)
{
	t_dll	*now;

	if (!adm)
		return (NULL);
	now = adm->head;
	while (now->r != NULL)
	{
		now = now->r;
		free(now->l);
	}
	free(now);
	free(adm);
	return (NULL);
}

void	*ft_free_allist(t_adm **adm, int y, void *r)
{
	int	i;

	i = -1;
	if (!adm)
		return (r);
	while (++i < y)
		ft_free_list(adm[i]);
	free(adm);
	return (r);
}

void	*ft_free_line(int ret, char *s, void *r)
{
	if (ret == -1)
		return (r);
	free(s);
	return (r);
}
