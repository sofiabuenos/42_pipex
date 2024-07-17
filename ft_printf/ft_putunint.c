/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:57:49 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/01 16:56:53 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunint(unsigned int nbr, int *count)
{
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nbr;
	}
	while (nbr >= 10)
	{
		ft_putnbr(nbr / 10, count);
		nbr = nbr % 10;
	}
	ft_putchar(nbr + '0', count);
}
