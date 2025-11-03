/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_write.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/31 18:29:50 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/03 17:30:25 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	nbrlen(long long n1)
{
	size_t	count;

	count = 1;
	if (n1 < 0)
	{
		n1 *= -1;
		count++;
	}
	while (n1 > 9)
	{
		n1 /= 10;
		count++;
	}
	return (count);
}

static void	put(long n, char *result, int *i)
{
	if (n > 9)
	{
		put(n / 10, result, i);
		put(n % 10, result, i);
	}
	else
		result[(*i)++] = n + '0';
}

void	ft_itoa_write(int n)
{
	char	*result;
	long	n1;
	int		len;
	int		i;

	n1 = n;
	len = nbrlen(n1);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return ;
	i = 0;
	if (n1 < 0)
	{
		result[i++] = '-';
		n1 *= -1;
	}
	put(n1, result, &i);
	result[i] = '\0';
	ft_writebutbetter(result, len);
}
