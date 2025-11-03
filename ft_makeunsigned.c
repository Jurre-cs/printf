/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_makeunsigned.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/03 13:49:06 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/03 15:36:19 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_makeunsigned(unsigned int n)
{
	char	c;

	if (n / 10)
	{
		ft_makeunsigned(n / 10);
	}
	c = n % 10 + '0';
	ft_writebutbetter(&c, 1);
}
