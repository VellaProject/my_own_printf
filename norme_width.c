/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:25:04 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:28:00 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

int		find(t_main *main, char tofind)
{
	int i;

	i = 0;
	while (main->parsed[i] != '\0')
	{
		if (main->parsed[i] == tofind)
			return (1);
		i++;
	}
	return (0);
}

void	first(t_main *main)
{
	if (find(main, 'x') == 1 || find(main, 'X') == 1)
	{
		if (main->dietat == 1 && (unsigned long long int)main->elem != 0
				&& find(main, 'x') == 1)
			main->print = ft_strjoin("0x", main->print);
		else if (main->dietat == 1 && (unsigned long long int)main->elem != 0
				&& find(main, 'X') == 1)
			main->print = ft_strjoin("0X", main->print);
	}
}

void	last_mini(t_main *main)
{
	int i;

	if (main->plusetat == 1)
		main->print = ft_strjoin("+", main->print);
	if (main->dietat == 1 && (unsigned long long int)main->elem != 0
			&& main->zeroetat == 1 && find(main, 'x') == 1)
		main->print = ft_strjoin("0x", main->print);
	if (find(main, 'c') == 1 && main->width > 0)
	{
		if ((int)main->elem == 0)
		{
			main->print = ft_memalloc(sizeof(char) * 10);
			i = 1;
			while (i < main->width)
			{
				if (main->zeroetat == 1)
					main->print = ft_strjoin(main->print, "0");
				else
					main->print = ft_strjoin(main->print, " ");
				i++;
			}
			main->casc = 1;
		}
	}
}

void	one_else(t_main *main, int needzero)
{
	if (find(main, 'o') == 0 && (find(main, 'd') == 0 && find(main, '-') == 0))
	{
		while (needzero > 0)
		{
			main->print = ft_strjoin(main->print, "0");
			main->size++;
			needzero--;
		}
	}
	else
	{
		while (needzero > 0)
		{
			main->print = ft_strjoin(main->print, " ");
			main->size++;
			needzero--;
		}
	}
}

void	ok_ok(t_main *main, int needzero)
{
	if (needzero < 0)
	{
		main->width = -main->width;
		needzero = main->width - main->size;
	}
	while (needzero > 0)
	{
		main->print = ft_strjoin(main->print, " ");
		main->size++;
		needzero--;
	}
}
