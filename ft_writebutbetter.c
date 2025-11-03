/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_writebutbetter.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/03 14:50:50 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/03 15:50:13 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <unistd.h>

int	ft_writebutbetter(char *str, size_t len)
{
	static int	count;

	count = 0;
	write(1, str, len);
	count += len;
	return (count);
}
