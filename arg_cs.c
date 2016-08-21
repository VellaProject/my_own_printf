/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_cs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:23:45 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:26:31 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	the_s_c(t_main *main)
{
	if ((wint_t)main->elem != 0)
		mywchar(main, (wint_t)main->elem);
	else
	{
		write(1, "\0", 1);
		main->size++;
	}
}

void	the_c(t_main *main)
{
	char test[2];

	if (main->type == 0)
	{
		if ((int)main->elem != 0)
		{
			main->size++;
			test[0] = (int)main->elem;
			test[1] = '\0';
			main->print = ft_strjoin(main->print, test);
		}
		else if (main->width <= 0)
		{
			write(1, "\0", 1);
			main->size++;
		}
	}
	else
	{
		if ((wint_t)main->elem != 0)
			mywchar(main, (wint_t)main->elem);
		else
			main->size++;
	}
}

void	the_other(t_main *main)
{
	char test[2];

	main->size++;
	test[0] = main->chaine[main->i];
	test[1] = '\0';
	main->print = ft_strjoin(main->print, test);
}

void	hihi_s(t_main *main)
{
	wchar_t		*chaine;
	int			i;

	chaine = (wchar_t *)main->elem;
	i = 0;
	while (chaine[i] != '\0')
	{
		mywchar(main, chaine[i]);
		i++;
	}
}

void	the_first_s(t_main *main)
{
	int		i;
	char	*lp;

	if (main->type == 0)
	{
		if (main->accurate == -1)
			main->accurate = ft_strlen((char *)main->elem);
		lp = (char *)main->elem;
		lp = ft_strsub(lp, 0, main->accurate);
		i = 0;
		main->print = ft_strjoin(main->print, &lp[0]);
		if ((size_t)main->accurate > ft_strlen(lp))
			main->size = ft_strlen(lp);
		else
			main->size += main->accurate;
	}
	else
	{
		if ((wchar_t *)main->elem)
			hihi_s(main);
	}
}
