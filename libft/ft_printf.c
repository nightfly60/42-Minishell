/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouyaz <aabouyaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 13:59:04 by aabouyaz          #+#    #+#             */
/*   Updated: 2025/05/27 11:31:05 by aabouyaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_cap(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	return (0);
}

static void	put_type(va_list arg, char type, int *total)
{
	if (type == '%')
		*total = *total + ft_putchar('%');
	else if (type == 'X' || type == 'x')
		ft_put_hex((long)va_arg(arg, int), is_cap(type), total);
	else if (type == 'u')
		ft_putnbr_unsigned((unsigned long long)va_arg(arg, int), total);
	else if (type == 'd' || type == 'i')
		ft_putnbr((long long)va_arg(arg, int), total);
	else if (type == 'p')
		ft_putaddr((void *)va_arg(arg, void *), total);
	else if (type == 's')
		*total = *total + ft_putstr((char *)va_arg(arg, char *));
	else if (type == 'c')
		*total = *total + ft_putchar((int)va_arg(arg, int));
}

static int	isindict(char c)
{
	int		i;
	char	*dict;

	i = 0;
	dict = "cspdiuxX%";
	while (dict[i])
	{
		if (dict[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		total;

	if (!format)
		return (-1);
	i = 0;
	total = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && isindict(format[i + 1]))
		{
			put_type(args, format[i + 1], &total);
			i = i + 2;
		}
		else
		{
			ft_putchar(format[i]);
			i++;
			total++;
		}
	}
	va_end(args);
	return (total);
}
