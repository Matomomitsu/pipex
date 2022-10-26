/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 22:04:51 by mtomomit          #+#    #+#             */
/*   Updated: 2022/04/27 22:22:44 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*charstr(long int n, char *str, size_t i)
{	
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
		while (i >= 1)
		{
			str[i] = (n % 10) + 48;
			n = n / 10;
			i--;
		}
	}
	else
	{
		while (i >= 1)
		{
			str[i] = (n % 10) + 48;
			n = n / 10;
			i--;
		}
			str[0] = (n % 10) + 48;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long int	temp;
	long int	nb;
	size_t		i;
	char		*str;

	i = 1;
	temp = n;
	nb = temp;
	if (temp < 0)
		temp = temp * -1;
	while (temp / 10 >= 10)
	{
		temp = temp / 10;
		i++;
	}
	if (nb < 0)
		i++;
	if (temp > 9)
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	return (charstr(nb, str, i));
}
