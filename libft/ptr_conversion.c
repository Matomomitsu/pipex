/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 21:57:28 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/16 16:05:17 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ptr_conversion(int fd, void *ptr)
{
	size_t			ptr_len;
	unsigned long	i;
	char			*ptr_address;

	if (!ptr)
		return (str_conversion(fd, "(nil)"));
	else
	{
		i = (unsigned long)ptr;
		ptr_address = ft_itoa_base(i, "0123456789abcdef");
		ptr_len = ft_strlen(ptr_address) + 2;
		write(1, "0x", 2);
		ft_putstr_fd(ptr_address, fd);
		free(ptr_address);
		return (ptr_len);
	}
}
