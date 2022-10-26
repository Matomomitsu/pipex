/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigint_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 18:05:42 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/16 16:02:28 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	unsigint_conversion(int fd, unsigned int nb)
{
	char	*nbr;
	size_t	len_nbr;

	nbr = ft_itoa_base(nb, "0123456789");
	ft_putstr_fd(nbr, fd);
	len_nbr = ft_strlen(nbr);
	free(nbr);
	return (len_nbr);
}
