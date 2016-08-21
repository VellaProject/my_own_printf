/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_second_width.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:24:46 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:28:21 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	another_else(t_main *main, int needzero)
{
	int		i;
	int		i2;
	char	*temp;

	i = 0;
	i2 = 0;
	temp = (char *)malloc(sizeof(char) * ft_strlen(main->print) + 10);
	while (main->print[i] != '\0')
	{
		if (main->print[i] != '-')
		{
			temp[i2] = main->print[i];
			i2++;
		}
		i++;
	}
	temp[i2] = '\0';
	main->print = temp;
	while (needzero > 0)
	{
		main->print = ft_strjoin("0", main->print);
		main->size++;
		needzero--;
	}
	main->print = ft_strjoin("-", main->print);
}

void	ok_its_norme(t_main *main, int needzero)
{
	if (main->moinetat == 0)
	{
		if (main->signemoin != 1)
		{
			while (needzero > 0)
			{
				if (find(main, ' ') == 0)
				{
					if (find(main, 'p') == 0)
						main->print = ft_strjoin("0", main->print);
				}
				else
					main->print = ft_strjoin(main->print, "0");
				main->size++;
				needzero--;
			}
		}
		else
			another_else(main, needzero);
	}
	else
		one_else(main, needzero);
}

void	in_nor(t_main *main)
{
	if (find(main, 's') == 1 && main->width > 0 && main->zeroetat == 1)
		main->print = ft_strjoin("0", main->print);
	else
	{
		if (main->zeroetat == 1 && no_conv(main) == 1 && main->width > 0)
			main->print = ft_strjoin("0", main->print);
		else if (main->zeroetat == 1 && main->width > 0 && main->accurate <= 0)
			main->print = ft_strjoin("0", main->print);
		else
			main->print = ft_strjoin(" ", main->print);
	}
}

void	hai_hai(t_main *main, int needzero)
{
	if (main->plusetat == 1)
	{
		main->plusetat = 0;
		main->print = ft_strjoin("+", main->print);
	}
	while (needzero > 0)
	{
		if (find(main, 'c') == 1 && find(main, '.') == 1)
			main->print = ft_strjoin(" ", main->print);
		else
		{
			if (main->zeroetat == 1 && main->accurate < 0)
				main->print = ft_strjoin("0", main->print);
			else
				in_nor(main);
		}
		main->size++;
		needzero--;
	}
}

int		add_mini(t_main *main)
{
	int needzero;
	int ok;

	ok = 0;
	needzero = main->width - main->size;
	if (main->stop == 1)
		return (0);
	if (needzero > 0 || needzero < 0)
	{
		if (main->zeroetat == 0 || main->pointetat != 0)
		{
			first(main);
			if (main->moinetat == 0)
				hai_hai(main, needzero);
			else
				ok_ok(main, needzero);
		}
		else
			ok_its_norme(main, needzero);
	}
	last_mini(main);
	return (0);
}
