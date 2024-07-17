/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 16:39:15 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/02 13:04:00 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"
/*function prototypes*/

int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *count);
void	ft_putstr(const char *s, int *count);
void	ft_putbase(unsigned long nbr, int *count, char *str);
void	ft_putnbr(int nb, int *count);
void	ft_putunint(unsigned int nbr, int *count);
void	ft_putmem(void *a, int *count);

#endif