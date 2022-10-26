/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 22:11:54 by mtomomit          #+#    #+#             */
/*   Updated: 2022/05/30 14:59:28 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	size_malloc;

	size_malloc = nmemb * size;
	if (nmemb != 0 && size_malloc / nmemb != size)
		return (NULL);
	ptr = (void *)malloc(size_malloc);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, (size_malloc));
	return (ptr);
}
