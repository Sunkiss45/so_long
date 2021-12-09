/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:00:47 by ebarguil          #+#    #+#             */
/*   Updated: 2021/12/08 16:49:49 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_init_tex(void **p)
{
	int	pi;

	pi = PI;
	p[2] = mlx_xpm_file_to_image(p[0], "./Tex/0.xpm", &pi, &pi);
	p[3] = mlx_xpm_file_to_image(p[0], "./Tex/1.xpm", &pi, &pi);
	p[4] = mlx_xpm_file_to_image(p[0], "./Tex/C.xpm", &pi, &pi);
	p[5] = mlx_xpm_file_to_image(p[0], "./Tex/P.xpm", &pi, &pi);
	p[6] = mlx_xpm_file_to_image(p[0], "./Tex/P2.xpm", &pi, &pi);
	p[7] = mlx_xpm_file_to_image(p[0], "./Tex/E.xpm", &pi, &pi);
}

int	ft_close(t_adm **adm)
{
	void	**p;
	int		i;

	p = adm[0]->p;
	i = 1;
	printf(RESET"\n");
	if (p[0])
	{
		while (++i < 8)
			if (p[i])
				mlx_destroy_image(p[0], p[i]);
		if (p[1])
			mlx_destroy_window(p[0], p[1]);
		mlx_destroy_display(p[0]);
		free(p[0]);
	}
	ft_free_allist(adm, adm[0]->y, NULL);
	exit (0);
	return (0);
}

int	deal_key(int key, t_adm **adm)
{
	void	**p;
	int		i;

	i = 0;
	p = adm[0]->p;
	if (key == 119)
		i += ft_ver(adm, p, 1);
	if (key == 115)
		i += ft_ver(adm, p, -1);
	if (key == 97)
		i += ft_hor(adm, p, 1);
	if (key == 100)
		i += ft_hor(adm, p, -1);
	if (key == 65307 || i)
		ft_close(adm);
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
			if (now->c == 'C')
				mlx_put_image_to_window(ptr[0], ptr[1], ptr[4], x, (i * PI));
			if (now->c == 'P')
				mlx_put_image_to_window(ptr[0], ptr[1], ptr[5], x, (i * PI));
			if (now->c == 'E')
				mlx_put_image_to_window(ptr[0], ptr[1], ptr[7], x, (i * PI));
			x += PI;
			now = now->r;
		}
	}
}

int	ft_graphical(t_adm **adm, int x, int y)
{
	x = x;
	adm[0]->p[0] = mlx_init();
	if (adm[0]->p[0] == NULL)
		return (ft_close(adm));
	ft_init_tex(adm[0]->p);
	if (adm[0]->p[2] == NULL || adm[0]->p[3] == NULL || adm[0]->p[4] == NULL
		|| adm[0]->p[5] == NULL || adm[0]->p[6] == NULL || adm[0]->p[7] == NULL)
		return (ft_close(adm));
	adm[0]->p[1] = mlx_new_window(adm[0]->p[0], (PI * x), (PI * y), "so_long");
	if (adm[0]->p[1] == NULL)
		return (ft_close(adm));
	ft_print_img(adm, adm[0]->p, y);
	adm[0]->op = 0;
	adm[0]->e = 0;
	adm[0]->te = 0;
	printf(GREEN"Compteur deplacement :\n");
	mlx_hook(adm[0]->p[1], 17, 1L << 17, ft_close, adm);
	mlx_key_hook(adm[0]->p[1], deal_key, adm);
	mlx_loop(adm[0]->p[0]);
	return (0);
}
