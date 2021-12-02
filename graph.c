/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:00:47 by ebarguil          #+#    #+#             */
/*   Updated: 2021/12/02 23:08:09 by ebarguil         ###   ########.fr       */
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

t_plp	*ft_player_pos(t_adm **adm, t_plp *plp)
{
	t_dll	*now;

	now = adm[0]->play;
	plp->x = now->x * PI;
	plp->y = now->y * PI;
	return (plp);
}

int	deal_key(int key, void **ptr)
{
	printf(YELLOW"[%d]"RESET"\n", key);
	if (key == 119)
		printf(RED"Je trouve W"RESET"\n");
	if (key == 97)
		printf(RED"Je trouve A"RESET"\n");
	if (key == 115)
		printf(RED"Je trouve S"RESET"\n");
	if (key == 100)
		printf(RED"Je trouve D"RESET"\n");
	if (key == 65307)
		mlx_destroy_window(ptr[0], ptr[1]);
	return (key);
}

void	ft_print_img(t_adm **adm, void **ptr, int y)
{
	t_dll	*now;
	int		x;
	int		i;

	i = -1;
	while (++i < y)
	{
		now = adm[i]->head;
		x = 0;
		while (now != NULL)
		{
			if (now->c == '0')
				mlx_put_image_to_window(ptr[0], ptr[1], ptr[2], x, (i * PI));
			if (now->c == '1')
				mlx_put_image_to_window(ptr[0], ptr[1], ptr[3], x, (i * PI));
			if (now->c == 'C' || now->c == 'E')
				mlx_put_image_to_window(ptr[0], ptr[1], ptr[4], x, (i * PI));
			if (now->c == 'P')
				mlx_put_image_to_window(ptr[0], ptr[1], ptr[5], x, (i * PI));
			x += PI;
			now = now->r;
		}
	}
}

int	ft_graphical(t_adm **adm, int x, int y)
{
	void	*ptr[6];
	int		p;

	int		z;

	p = PI;
	ptr[0] = mlx_init();
	if (ptr[0] == NULL)
		return (1);
	ptr[2] = mlx_xpm_file_to_image(ptr[0], "./Tex/0.xpm", &p, &p);
	ptr[3] = mlx_xpm_file_to_image(ptr[0], "./Tex/1.xpm", &p, &p);
	ptr[4] = mlx_xpm_file_to_image(ptr[0], "./Tex/C.xpm", &p, &p);
	ptr[5] = mlx_xpm_file_to_image(ptr[0], "./Tex/redbrik.xpm", &p, &p);
	if (ptr[2] == NULL || ptr[3] == NULL || ptr[4] == NULL || ptr[5] == NULL)
		return (ft_error_int("Insh", 0));
	ptr[1] = mlx_new_window(ptr[0], (PI * x), (PI * y), "so_long");
	if (ptr[1] == NULL)
		return (1);
	ft_print_img(adm, ptr, y);
	z = mlx_key_hook(ptr[1], deal_key, (void *)0);
	printf(GREEN"[%d]"RESET"\n", z);
	mlx_loop(ptr[0]);
	return (0);
}
