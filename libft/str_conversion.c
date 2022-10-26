/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:30:16 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/16 16:02:15 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	str_conversion(int fd, char *str)
{
	size_t	len_str;

	if (!str)
		return (str_conversion(fd, "(null)"));
	else
	{
		ft_putstr_fd(str, fd);
		len_str = ft_strlen(str);
		return (len_str);
	}
}
