/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:02:26 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/16 16:05:44 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	hex_conversion(int fd, unsigned int nb, char type)
{
	char	*nbr;
	size_t	len_nbr;

	if (type == 'X')
		nbr = ft_itoa_base(nb, "0123456789ABCDEF");
	if (type == 'x')
		nbr = ft_itoa_base(nb, "0123456789abcdef");
	ft_putstr_fd(nbr, fd);
	len_nbr = ft_strlen(nbr);
	free(nbr);
	return (len_nbr);
}
