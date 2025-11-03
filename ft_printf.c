/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/31 11:41:04 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/03 18:50:02 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static void	typewrite(char c, va_list args)
{
	if (c == 'u')
		ft_printunsigned(va_arg(args, unsigned int));
	else if (c == 'i' || c == 'd')
		ft_itoa_write(va_arg(args, int));
	else if (c == 'p')
		ft_writebutbetter(va_arg(args, void *), 1);
	else if (c == 's')
		ft_putstring(va_arg(args, char *));
	else if (c == 'c')
		ft_writebutbetter(va_arg(args, char *), 1);
	else if (c == 'x' || c == 'X')
		ft_tohexdec(va_arg(args, int), c);
	else if (c == '%')
		ft_writebutbetter(&c, 1);
	else
		ft_writebutbetter("0", 1);
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
		if (type[i] == '%')
		{
			typewrite(type[i + 1], args);
			if (!type[i + 2])
				break ;
			i = i + 2;
		}
		count = ft_writebutbetter((char *)&type[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}

int	main(void)
{
	ft_printf("ZA %c asfsa %a ", 'W', "lkjasdf");
}
