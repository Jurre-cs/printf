/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_tohexdec.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/31 15:33:36 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/03 17:30:17 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_tohexdec2(int i, int n, char *base)
{
	char	*s;

	s = ft_calloc(i + 1, sizeof(char));
	if (n < 0)
	{
		n *= -1;
		s[0] = '-';
	}
	while (i > 0)
	{
		s[i] = base[n % 16];
		n /= 16;
		i--;
	}
	return (s);
}

void	ft_tohexdec(int n, char c)
{
	int		ntmp;
	int		i;
	char	*base;
	char	*s;

	if (c == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ntmp = n;
	if (ntmp < 0)
		ntmp *= -1;
	i = 1;
	while (ntmp > 15)
	{
		ntmp /= 16;
		i++;
	}
	s = ft_tohexdec2(i, n, base);
	ft_writebutbetter(s, i + 1);
}

// int	main(void)
// {
// 	ft_tohexdec(-98243087, 'X');
// }
