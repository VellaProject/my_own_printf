/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_di.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:23:52 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:23:53 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	d_i_signemoin(t_main *main)
{
	int		i;
	int		i2;
	char	*temp;

	if (main->signemoin == 1)
	{
		i = 0;
		i2 = 0;
		temp = (char *)malloc(sizeof(char) + ft_strlen(main->print) + 10);
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
		main->print = ft_strdup(temp);
		main->print = ft_strjoin("-", main->print);
	}
}

void	all_d_i(t_main *main)
{
	long long int a;

	a = (long long int)main->elem;
	if ((int)a < 0 && main->type == 0)
		main->signemoin = 1;
	else if ((long int)a < 0 && main->type == 1)
		main->signemoin = 1;
	else if ((long long int)a < 0 && main->type == 2)
		main->signemoin = 1;
	if (main->type == 0)
		join_d(main);
	else if (main->type == 1)
		join_ld(main);
	else if (main->type == 2)
		join_lld(main);
	else if (main->type == 3)
		join_hd(main);
	else if (main->type == 4)
		join_hhd(main);
	else if (main->type == 5)
		join_jd(main);
	else if (main->type == 6)
		join_zd(main);
}

void	d_i(t_main *main)
{
	if ((main->accurate == 0 && main->width != 0) ||
			(find(main, '.') == 1 && main->accurate < 1 && main->width != 0
			&& (int)main->elem == 0) ||
			((int)main->elem == 0 && find(main, '.') == 1
			&& main->accurate < 1))
		return ;
	all_d_i(main);
	d_i_signemoin(main);
}

void	the_second_d(t_main *main)
{
	if (main->type > 0)
	{
		main->type++;
	}
	else
		main->type = 1;
	if (main->type == 1)
		join_ld(main);
	else if (main->type == 2)
		join_lld(main);
	else if (main->type == 3)
		join_hd(main);
	else if (main->type == 4)
		join_hhd(main);
	else if (main->type == 5)
		join_jd(main);
	else if (main->type >= 6)
		join_zd(main);
}
