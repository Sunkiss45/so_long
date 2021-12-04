/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 20:04:02 by ebarguil          #+#    #+#             */
/*   Updated: 2021/12/04 22:58:59 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_plp	*ft_pixel_pos(t_dll **pos)
{
	t_plp	*plp;

	plp = malloc(sizeof(*plp));
	if (plp == NULL)
		return (NULL);
	plp->px = pos[0]->x * PI;
	plp->py = pos[0]->y * PI;
	plp->tx = pos[1]->x * PI;
	plp->ty = pos[1]->y * PI;
	return (plp);
}

int	ft_vis(t_adm **adm, t_dll **pos, void **p)
{
	t_plp	*plp;

	plp = ft_pixel_pos(pos);
	if (plp == NULL && !ft_error("Malloc of pixel_pos has crashed", NULL))
		ft_close(adm);
	if (adm[0]->te)
	{
		if (adm[0]->col == 0)
		{
			free(plp);
			return (1);
		}
		mlx_put_image_to_window(p[0], p[1], p[6], plp->tx, plp->ty);
	}
	else
		mlx_put_image_to_window(p[0], p[1], p[5], plp->tx, plp->ty);
	if (adm[0]->e)
		mlx_put_image_to_window(p[0], p[1], p[7], plp->px, plp->py);
	else
		mlx_put_image_to_window(p[0], p[1], p[2], plp->px, plp->py);
	free(plp);
	return (0);
}

int	ft_dir(t_adm **adm, t_dll **pos, void **p)
{
	if (pos[1]->c == '1')
		return (0);
	adm[0]->op++;
	ft_putnbr_fd(adm[0]->op, 1);
	write(1, "\r", 1);
	if (pos[1]->c == 'C')
		adm[0]->col--;
	if (pos[1]->c == 'E')
		adm[0]->te = 1;
	pos[1]->c = 'P';
	if (ft_vis(adm, pos, p))
	{
		printf(YELLOW"\nYOU WIN, total count : %d"RESET"\n", adm[0]->op);
		return (1);
	}
	if (adm[0]->e)
		pos[0]->c = 'E';
	else
		pos[0]->c = '0';
	adm[0]->e = 0;
	if (adm[0]->te && adm[0]->te-- != -1)
		adm[0]->e = 1;
	adm[0]->play = pos[1];
	return (0);
}

int	ft_ver(t_adm **adm, void **p, int i)
{
	t_dll	*pos[2];
	int		x;
	int		y;

	pos[0] = adm[0]->play;
	x = pos[0]->x;
	y = pos[0]->y - i;
	pos[1] = adm[y]->head;
	while (pos[1]->x != x)
		pos[1] = pos[1]->r;
	return (ft_dir(adm, pos, p));
}

int	ft_hor(t_adm **adm, void **p, int i)
{
	t_dll	*pos[2];
	int		x;
	int		y;

	pos[0] = adm[0]->play;
	x = pos[0]->x - i;
	y = pos[0]->y;
	pos[1] = adm[y]->head;
	while (pos[1]->x != x)
		pos[1] = pos[1]->r;
	return (ft_dir(adm, pos, p));
}
