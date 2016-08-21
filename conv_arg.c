/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/01 17:51:45 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:27:37 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	accurate_d(int size, t_main *main)
{
	if (main->signemoin == 1)
		main->accurate++;
	if (find(main, 'o') == 0 && find(main, 'O') == 0 &&
			find(main, 'x') == 0 && find(main, 'X') == 0)
	{
		while (size < main->accurate)
		{
			main->print = ft_strjoin(main->print, "0");
			size++;
			main->size++;
		}
	}
	else
	{
		while (size < main->accurate)
		{
			main->print = ft_strjoin("0", main->print);
			size++;
			main->size++;
		}
	}
}

void	last_arg(t_main *main)
{
	if (main->chaine[main->i] == 'U')
		the_second_u(main);
	else if (main->chaine[main->i] == 's')
		the_s(main);
	else if (main->chaine[main->i] == 'S')
		the_s_s(main);
	else if (main->chaine[main->i] == 'c')
		the_c(main);
	else if (main->chaine[main->i] == 'C')
		the_s_c(main);
	else if (main->chaine[main->i] == '%')
		the_percent(main);
	else if (main->chaine[main->i] == 'p')
		the_p(main);
	else if (main->chaine[main->i] == 'x')
		the_x(main);
	else if (main->chaine[main->i] == 'X')
		the_xx(main);
	else if (main->chaine[main->i] != ' ')
		the_other(main);
}

void	a_un_moment(t_main *main)
{
	main->size = 0;
	main->stop = 1;
}

int		jajaja(t_main *main)
{
	if (((main->accurate == 0 && main->width != 0) || (find(main, '.') == 1
					&& main->accurate < 1 && main->width != 0) ||
				((unsigned int)main->elem == 0
				&& find(main, '.') == 1 && main->accurate < 1)) &&
			main->dietat == 0)
		return (1);
	return (0);
}

int		manage_arg(t_main *main)
{
	main->i++;
	if (main->chaine[main->i] == '\0')
	{
		a_un_moment(main);
		return (0);
	}
	if (main->chaine[main->i] == 'd' || main->chaine[main->i] == 'i')
		d_i(main);
	else if (main->chaine[main->i] == 'D')
		the_second_d(main);
	else if (main->chaine[main->i] == 'o')
		the_o(main);
	else if (main->chaine[main->i] == 'O')
		the_second_o(main);
	else if (main->chaine[main->i] == 'u')
	{
		if (jajaja(main) == 1)
			return (0);
		the_u(main);
	}
	else
		last_arg(main);
	return (1);
}
