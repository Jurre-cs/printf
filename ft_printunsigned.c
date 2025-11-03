/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printunsigned.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/03 13:49:06 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/03 18:28:01 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printunsigned(unsigned int n)
{
	char	c;

	if (n / 10)
	{
		ft_printunsigned(n / 10);
	}
	c = n % 10 + '0';
	ft_writebutbetter(&c, 1);
}
