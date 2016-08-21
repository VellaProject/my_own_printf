/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:23:36 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:23:37 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_printf.h"

void	join_lu(t_main *main)
{
	char	*number;
	int		size;

	number = my_utoa((unsigned long int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if (main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void	join_llu(t_main *main)
{
	char	*number;
	int		size;

	number = my_utoa((unsigned long long int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if (main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void	join_hu(t_main *main)
{
	char	*number;
	int		size;

	number = my_utoa((unsigned short int)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if (main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void	join_hhu(t_main *main)
{
	char	*number;
	int		size;

	if (find(main, 'U'))
		number = my_utoa((unsigned long long int)main->elem);
	else
		number = my_utoa((unsigned char)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if (main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}

void	join_ju(t_main *main)
{
	char	*number;
	int		size;

	number = my_utoa((uintmax_t)main->elem);
	size = ft_strlen(number);
	main->size += size;
	if (main->accurate != -1)
		accurate_d(size, main);
	main->print = ft_strjoin(main->print, number);
}
