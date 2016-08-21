/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_du_bis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:22:58 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:23:00 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	join_zd(t_main *main)
{
	char	*number;
	int		size;

	number = my_itoa((long long int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if (main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void	join_d(t_main *main)
{
	char	*number;
	int		size;

	number = my_itoa((int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if (main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void	join_zu(t_main *main)
{
	char	*number;
	int		size;

	if (find(main, 'U'))
	{
		number = my_utoa((unsigned long long int)main->elem);
	}
	else
		number = my_utoa((size_t)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if (main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void	join_u(t_main *main)
{
	char	*number;
	int		size;

	number = my_utoa((unsigned int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if (main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}
