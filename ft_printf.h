/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jstomps <jstomps@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/31 16:33:53 by jstomps       #+#    #+#                 */
/*   Updated: 2025/11/03 18:27:30 by jstomps       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdlib.h>
#include <unistd.h>

void	ft_tohexdec(int n, char c);
void	ft_putstring(char *s);
void	ft_itoa_write(int n);
int		ft_printf(const char *type, ...);
int		ft_writebutbetter(char *str, size_t len);
void	ft_printunsigned(unsigned int n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_bzero(void *s, size_t n);

#endif