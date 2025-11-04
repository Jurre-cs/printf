/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/31 11:41:04 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/04 19:06:28 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int	typewrite(char c, va_list args, int count)
{
	if (c == 'u')
		count += ft_printunsigned(va_arg(args, unsigned int));
	else if (c == 'i' || c == 'd')
		count += ft_itoa_write(va_arg(args, int));
	else if (c == 'p')
		count += ft_putadress(va_arg(args, size_t));
	else if (c == 's')
		count += ft_putstring(va_arg(args, char *));
	else if (c == 'c')
		count += ft_putchar(va_arg(args, int));
	else if (c == 'x' || c == 'X')
		count += ft_tohexdec(va_arg(args, unsigned int), c);
	else if (c == '%')
		count += write(1, &c, 1);
	else
		count += write(1, "0", 1);
	return (count);
}

int	ft_printf(const char *type, ...)
{
	int		i;
	va_list	args;
	int		count;

	count = 0;
	i = 0;
	va_start(args, type);
	while (type[i])
	{
		while (type[i] == '%')
		{
			count = typewrite(type[i + 1], args, count);
			if (!type[i + 2])
				break ;
			i = i + 2;
		}
		if (type[i] == '%' && !type[i + 2])
			break ;
		count += write(1, (char *)&type[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	int count;
// 	int count2;

// 	count = ft_printf(" NULL %s NULL ", NULL);
// 	count2 = printf("\n NULL %s NULL ", NULL);
// 	printf("\n%d", count);
// 	printf("\n%d\n", count2);
// }
