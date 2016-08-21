/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_s.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:24:29 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:27:09 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	the_second_s(t_main *main)
{
	char	*null;
	int		i;

	i = 0;
	null = "(null)";
	if (main->accurate > 0)
	{
		while (i < main->accurate && i < 6)
		{
			main->print = ft_strjoin_carac(main->print, null[i]);
			main->size++;
			i++;
		}
	}
	else if (find(main, '.') && main->accurate <= 0
			&& main->zeroetat == 1 && main->width > 0)
	{
	}
	else
	{
		main->print = ft_strjoin(main->print, null);
		main->size += 6;
	}
}

void	the_s(t_main *main)
{
	if (main->accurate < 0)
	{
		main->accurate = -1;
	}
	if ((char *)main->elem)
	{
		the_first_s(main);
	}
	else
	{
		the_second_s(main);
	}
}

void	the_second_ss(t_main *main)
{
	char	*null;
	int		i;

	i = 0;
	null = "(null)";
	if (main->accurate > 0)
	{
		while (i < main->accurate && i < 6)
		{
			main->print = ft_strjoin_carac(main->print, null[i]);
			main->size++;
			i++;
		}
	}
	else
	{
		main->print = ft_strjoin(main->print, null);
		main->size += 6;
	}
}

void	the_s_s(t_main *main)
{
	int		i;
	wchar_t	*chaine;

	if ((wchar_t *)main->elem)
	{
		chaine = (wchar_t *)main->elem;
		i = 0;
		while (chaine[i] != '\0')
		{
			mywchar(main, chaine[i]);
			i++;
		}
	}
	else
	{
		the_second_ss(main);
	}
}
