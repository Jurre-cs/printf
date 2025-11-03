/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_calloc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/11 13:35:50 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/03 18:25:38 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	product;
	void	*mem;

	if (nmemb > __SIZE_MAX__ / size)
		return (NULL);
	product = nmemb * size;
	mem = malloc(product);
	if (!mem)
		return (NULL);
	ft_bzero(mem, nmemb * size);
	return (mem);
}
