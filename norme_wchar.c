/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norme_wchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:24:53 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:24:55 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	prem_mask(t_main *main, wint_t mycarac)
{
	if (main->accurate >= 0)
	{
		if ((main->size + 1 <= main->accurate) || find(main, 'C') == 1)
		{
			main->size += 1;
			main->print = ft_strjoin_carac(main->print, (char)mycarac);
		}
	}
	else
	{
		main->size += 1;
		main->print = ft_strjoin_carac(main->print, (char)mycarac);
	}
}

void	sec_mask(t_main *main, wint_t mycarac)
{
	if (main->accurate >= 0)
	{
		if ((main->size + 2 <= main->accurate) || find(main, 'C') == 1)
		{
			main->size += 2;
			second_mask(mycarac, main);
		}
	}
	else
	{
		main->size += 2;
		second_mask(mycarac, main);
	}
}

void	tre_mask(t_main *main, wint_t mycarac)
{
	if (main->accurate >= 0)
	{
		if ((main->size + 3 <= main->accurate) || find(main, 'C') == 1)
		{
			main->size += 3;
			three_mask(mycarac, main);
		}
	}
	else
	{
		main->size += 3;
		three_mask(mycarac, main);
	}
}

void	fo_mask(t_main *main, wint_t mycarac)
{
	if (main->accurate >= 0)
	{
		if ((main->size + 4 <= main->accurate) || find(main, 'C') == 1)
		{
			main->size += 4;
			four_mask(mycarac, main);
		}
	}
	else
	{
		main->size += 4;
		four_mask(mycarac, main);
	}
}
