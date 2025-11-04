/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printunsigned.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/03 13:49:06 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/04 15:06:48 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nbrlen(unsigned int n1)
{
	int	count;

	count = 1;
	while (n1 > 9)
	{
		n1 /= 10;
		count++;
	}
	return (count);
}

static void	put(unsigned int n, char *result, int *i)
{
	if (n > 9)
	{
		put(n / 10, result, i);
		put(n % 10, result, i);
	}
	else
		result[(*i)++] = n + '0';
}

int	ft_printunsigned(unsigned int n)
{
	char			*result;
	unsigned int	n1;
	int				len;
	int				i;

	n1 = n;
	len = nbrlen(n1);
	result = malloc(sizeof(char) * (len + 1));
	if (result == NULL)
		return (0);
	i = 0;
	put(n1, result, &i);
	result[i] = '\0';
	write(1, result, len);
	free(result);
	return (len);
}

// #include <stdio.h>

// int main(void)
// {
// 	int len;

// 	len = ft_printunsigned(300000000);
// 	printf("\n%i", len);
// }
