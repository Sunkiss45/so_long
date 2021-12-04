/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 17:04:12 by ebarguil          #+#    #+#             */
/*   Updated: 2021/12/04 22:29:47 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
void	all_display(t_adm **adm)
{
	t_dll	*now;
	int		i;
//	int		s;
	int		y;

//	s = adm[0]->y;
	y = adm[0]->y;
	i = -1;
//	printf(YELLOW"\ny = [%d]\n"RESET"\n", y);
	printf(RESET"\n");
	while (++i < y)
	{
		now = adm[i]->head;
		while (now != NULL)
		{
			if (now->c == '1')
				printf(RED"%c", now->c);
			if (now->c == '0')
				printf(GREEN"%c", now->c);
			if (now->c == 'P')
				printf(BLUE"%c", now->c);
			if (now->c == 'E')
				printf(CYAN"%c", now->c);
			if (now->c == 'C')
				printf(YELLOW"%c", now->c);
			now = now->r;
		}
		printf(RESET"\n");
	}
	printf(RESET"\n");


	y = s;
	i = -1;
	printf(YELLOW"\nVerif des [x]\n"RESET"\n");
	while (++i < y)
	{
		now = adm[i]->head;
		printf(RED"NULL -> ");
		while (now != NULL)
		{
			printf(GREEN"|%d", now->x);
			now = now->r;
		}
		printf(GREEN"|"RED" -> NULL"RESET"\n");
	}

	y = s;
	i = -1;
	printf(YELLOW"\nVerif des [y]\n"RESET"\n");
	while (++i < y)
	{
		now = adm[i]->head;
		printf(RED"NULL -> ");
		while (now != NULL)
		{
			printf(GREEN"|%d", now->y);
			now = now->r;
		}
		printf(GREEN"|"RED" -> NULL"RESET"\n");
	}
}*/
