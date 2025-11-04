/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putadress.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/04 14:41:26 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/04 19:07:23 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_putadressextra2(int i, size_t n, char *base)
{
	char	*str;

	str = ft_calloc(i + 2, sizeof(char));
	while (i >= 0)
	{
		str[i] = base[n % 16];
		n /= 16;
		i--;
	}
	return (str);
}

int	ft_putadressextra1(size_t n)
{
	size_t	ntmp;
	int		i;
	char	*base;
	char	*str;

	base = "0123456789abcdef";
	i = 1;
	ntmp = n;
	while (ntmp > 15)
	{
		ntmp /= 16;
		i++;
	}
	str = ft_putadressextra2(i - 1, n, base);
	write(1, str, i);
	free(str);
	return (i);
}

int	ft_putadress(size_t n)
{
	int	len;

	len = 0;
	if (!n)
		return (len += write(1, "(nil)", 5));
	len += ft_putchar('0');
	len += ft_putchar('x');
	len += ft_putadressextra1(n);
	return (len);
}

// #include <stdio.h>

// int	main(void)
// {
// 	ft_putadress((size_t)NULL);
// 	printf("\n%p", NULL);
// }
