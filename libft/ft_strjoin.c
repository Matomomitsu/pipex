/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:07:54 by mtomomit          #+#    #+#             */
/*   Updated: 2022/04/27 22:24:11 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;
	size_t	o;

	if (!s1 || !s2)
		return (NULL);
	s3 = (char *)malloc((ft_strlen(s1) + 1 + ft_strlen(s2)) * sizeof(char));
	if (s3 == NULL)
		return (NULL);
	i = 0;
	o = 0;
	while (s1[o])
	{
		s3[i] = s1[o++];
		i++;
	}
	o = 0;
	while (s2[o] != '\0')
	{
		s3[i] = s2[o++];
		i++;
	}
	s3[i] = s2[o];
	return (s3);
}
