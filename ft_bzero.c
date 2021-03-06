/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avella <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 15:23:23 by avella            #+#    #+#             */
/*   Updated: 2016/05/02 17:32:03 by avella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			j;
	unsigned char	*d;

	d = (unsigned char*)s;
	j = 0;
	while (j < n)
	{
		d[j] = 0;
		j++;
	}
}
