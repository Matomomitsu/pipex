/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 19:07:43 by mtomomit          #+#    #+#             */
/*   Updated: 2022/04/06 18:15:03 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*s2;
	unsigned int	i;

	s2 = (char *) malloc((ft_strlen(s) + 1) * sizeof(char));
	i = 0;
	while (s[i])
	{
		s2[i] = s[i];
		i++;
	}
	s2[i] = s[i];
	return (s2);
}
