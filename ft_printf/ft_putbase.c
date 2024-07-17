/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:05:05 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/02 11:48:14 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putbase(unsigned long nbr, int *count, char *str)
{
	int	len;

	len = ft_strlen(str);
	while (nbr >= (unsigned long)len)
	{
		ft_putbase(nbr / (unsigned long)len, count, str);
		nbr = nbr % (unsigned long)len;
	}
	*count += write (1, &str[nbr], 1);
}
