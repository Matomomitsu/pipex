/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 17:25:43 by mtomomit          #+#    #+#             */
/*   Updated: 2022/04/27 22:24:50 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	malloc_size;
	char	*sstr;

	if (!s)
		return (NULL);
	if (start < ft_strlen(s))
		malloc_size = ft_strlen(s) - start + 1;
	if (start >= ft_strlen(s))
		malloc_size = 1;
	if (malloc_size > len)
		malloc_size = len + 1;
	sstr = (char *)malloc(malloc_size * sizeof(char));
	if (sstr == NULL)
		return (NULL);
	if (malloc_size - 1 == 0)
		sstr[0] = '\0';
	else
		ft_strlcpy(sstr, &s[start], malloc_size);
	return (sstr);
}
