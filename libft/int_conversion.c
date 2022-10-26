/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 23:27:52 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/16 16:01:31 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	int_conversion(int fd, int nb)
{
	char	*nbr;
	size_t	len_nbr;

	nbr = ft_itoa(nb);
	ft_putstr_fd(nbr, fd);
	len_nbr = ft_strlen(nbr);
	free(nbr);
	return (len_nbr);
}
