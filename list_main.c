/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:57:36 by ebarguil          #+#    #+#             */
/*   Updated: 2021/11/30 14:57:43 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_insert(t_adm *adm, char c, int y, int x)
{
	t_dll	*dll;

	dll = malloc(sizeof(*dll));
	if (dll == NULL)
		return (1);
	dll->c = c;
	dll->x = x;
	dll->y = y;
	dll->r = NULL;
	dll->l = adm->tail;
	adm->tail->r = dll;
	adm->tail = dll;
	return (0);
}

t_adm	*ft_new_list(t_adm *adm, char *s, int y, int x)
{
	t_dll	*dll;

	adm = malloc(sizeof(*adm));
	dll = malloc(sizeof(*dll));
	if (adm == NULL || dll == NULL)
	{
		if (dll != NULL)
			free(dll);
		if (adm != NULL)
			free(adm);
		return (NULL);
	}
	adm->head = dll;
	adm->tail = dll;
	dll->c = s[0];
	dll->x = x;
	dll->y = y;
	dll->r = NULL;
	dll->l = NULL;
	while (s[++x])
		if (ft_insert(adm, s[x], y, x))
			return (ft_free_list(adm));
	return (adm);
}
