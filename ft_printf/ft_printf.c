/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:22:09 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/11/02 13:11:24 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_arg_type(va_list args, const char *c, int *count)
{
	if (*c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (*c == 's')
		ft_putstr(va_arg(args, const char *), count);
	else if (*c == 'p')
		ft_putmem(va_arg(args, void *), count);
	else if (*c == 'd' || *c == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (*c == 'u')
		ft_putunint(va_arg(args, unsigned int), count);
	else if (*c == 'x')
		ft_putbase((unsigned int)va_arg(args, int), count, HEX_LOWER);
	else if (*c == 'X')
		ft_putbase((unsigned int)va_arg(args, int), count, HEX_UPPER);
	else if (*c == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	va_list	args;

	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_arg_type(args, format, &count);
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
/* int main(void)
{
	char * a = NULL;
	void *ptr;
	ptr = &a;
	int i;
	int j;
	i = ft_printf("%s\n", a);
	j = printf("%s\n", a);
	printf("%i\n", i);
	printf("%i\n", j);
	return (0);
} */