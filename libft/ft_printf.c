/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtomomit <mtomomit@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:46:36 by mtomomit          #+#    #+#             */
/*   Updated: 2022/09/16 16:06:20 by mtomomit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	conversion(int fd, t_args *args)
{
	if (args->type == 'c')
	{
		args->format_len += 1;
		write(1, &args->ch, 1);
	}
	else if (args->type == 's')
		args->format_len += str_conversion(fd, args->str);
	else if (args->type == 'p')
		args->format_len += ptr_conversion(fd, args->hex_ptr);
	else if (args->type == 'd')
		args->format_len += int_conversion(fd, args->nb);
	else if (args->type == 'i')
		args->format_len += int_conversion(fd, args->nb);
	else if (args->type == 'u')
		args->format_len += unsigint_conversion(fd, args->unsigint);
	else if (args->type == 'x')
		args->format_len += hex_conversion(fd, args->unsigint, args->type);
	else if (args->type == 'X')
		args->format_len += hex_conversion(fd, args->unsigint, args->type);
	else if (args->type == '%')
	{
		write(1, "%", 1);
		args->format_len += 1;
	}
}

static void	args_init(t_args *args, va_list ap)
{
	if (args->type == 'c')
		args->ch = va_arg(ap, int);
	else if (args->type == 's')
		args->str = va_arg(ap, char *);
	else if (args->type == 'p')
		args->hex_ptr = va_arg(ap, void *);
	else if (args->type == 'd')
		args->nb = va_arg(ap, int);
	else if (args->type == 'i')
		args->nb = va_arg(ap, int);
	else if (args->type == 'u')
		args->unsigint = va_arg(ap, unsigned int);
	else if (args->type == 'x')
		args->unsigint = va_arg(ap, unsigned int);
	else if (args->type == 'X')
		args->unsigint = va_arg(ap, unsigned int);
	else if (args->type != '\0')
	{
		if (args->type >= 32 && args->type < 127)
			write(1, "%", 1);
		write(1, &args->type, 1);
	}
	else
		return ;
}

static int	write_format(int fd, const char *format, t_args *args)
{
	size_t	i;

	i = 0;
	while (format[i] != '%' && format[i])
	{
		write(fd, &format[i], 1);
		i++;
	}
	args->format_len += i;
	if (format[i] == '\0')
		i--;
	return (i);
}

int	ft_printf(int fd, const char *format, ...)
{
	va_list	ap;
	t_args	args;
	size_t	i;

	i = 0;
	args.format_len = i;
	va_start(ap, format);
	while (format[i])
	{
		i += write_format(fd, &format[i], &args) + 1;
		args.type = format[i];
		if (args.type != '%' && format[i] != '\0')
			args_init(&args, ap);
		if (format[i] != '\0')
			conversion(fd, &args);
		if (format[i] != '\0')
			i++;
	}
	va_end(ap);
	return (args.format_len);
}
