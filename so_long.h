/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebarguil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 12:50:54 by ebarguil          #+#    #+#             */
/*   Updated: 2021/12/02 22:26:21 by ebarguil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <limits.h>
# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define BLUE "\033[1;34m"
# define PURPLE "\033[1;35m"
# define CYAN "\033[1;36m"
# define GREY "\033[1;37m"
# define RESET "\033[0m"

# define BUFFER_SIZE 1024
# define PI 64

typedef struct s_dll
{
	char			c;
	int				x;
	int				y;
	struct s_dll	*r;
	struct s_dll	*l;
}	t_dll;

typedef struct s_adm
{
	int				y;
	int				col;
	struct s_dll	*play;
	struct s_dll	*head;
	struct s_dll	*tail;
}	t_adm;

typedef struct s_plp
{
	int	x;
	int	y;
}	t_plp;

void	all_display(t_adm **adm);

int		count_nb(t_adm *adm);
int		ft_graphical(t_adm **adm, int x, int y);

void	*ft_error(char *s, void *r);
void	*ft_error_frli(char *s, void *r, int ret, char *line);
void	*ft_error_fral(char *s, void *r, t_adm **adm, int y);
int		ft_error_int(char *s, int r);

int		ft_checker(t_adm **adm, int y);

int		ft_insert(t_adm *adm, char c, int y, int x);
t_adm	*ft_new_list(t_adm *adm, char *s, int y, int x);

t_adm	*ft_free_list(t_adm *adm);
void	*ft_free_allist(t_adm **adm, int y, void *r);
void	*ft_free_line(int ret, char *s, void *r);

#endif
