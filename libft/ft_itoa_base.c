/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 00:37:32 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/14 16:20:01 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*charstr(size_t nb, char *str, size_t i, char *base)
{
	size_t	j;
	size_t	len_base;

	j = 0;
	len_base = ft_strlen(base);
	while (i >= 1)
	{
		j = (nb % len_base);
		str[i] = base[j];
		nb = nb / len_base;
		i--;
	}
	j = (nb % len_base);
	str[i] = base[j];
	return (str);
}

char	*ft_itoa_base(unsigned long int nb, char *base)
{
	size_t	temp;
	size_t	i;
	char	*str;
	size_t	len_base;

	i = 1;
	len_base = ft_strlen(base);
	temp = nb;
	while (temp / len_base >= len_base)
	{
		temp = temp / len_base;
		i++;
	}
	if (temp > len_base - 1)
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	temp = nb;
	return (charstr(temp, str, i, base));
}
