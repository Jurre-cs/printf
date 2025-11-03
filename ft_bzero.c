/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/07 13:35:50 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/03 18:25:43 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*x;

	x = s;
	while (n > 0)
	{
		*x = '\0';
		x++;
		n--;
	}
	s = x;
}
