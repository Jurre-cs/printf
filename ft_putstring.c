/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstring.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/31 19:15:16 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/03 14:55:22 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstring(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_writebutbetter(&s[i], 1);
		i++;
	}
}
