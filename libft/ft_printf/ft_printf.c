/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:08:35 by brensant          #+#    #+#             */
/*   Updated: 2025/08/04 14:08:36 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	print_char(char c);
int	print_str(const char *str);
int	print_nbr_base(long nbr, char *base);
int	print_mem_addr(void *addr);

static int	print_specifier(char specifier, va_list list, int *error_status)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		return (print_char(va_arg(list, int)));
	else if (specifier == 's')
		return (print_str(va_arg(list, const char *)));
	else if (specifier == 'd' || specifier == 'i')
		return (print_nbr_base((long)va_arg(list, int), "0123456789"));
	else if (specifier == 'u')
		return (print_nbr_base((long)va_arg(list, unsigned int), "0123456789"));
	else if (specifier == 'x')
		return (print_nbr_base((long)va_arg(list, unsigned int),
				"0123456789abcdef"));
	else if (specifier == 'X')
		return (print_nbr_base((long)va_arg(list, unsigned int),
				"0123456789ABCDEF"));
	else if (specifier == 'p')
		return (print_mem_addr(va_arg(list, void *)));
	else if (specifier == '%')
		return (write(1, "%", 1));
	else
		*error_status = 1;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	list;
	int		count;
	int		error_status;

	va_start(list, format);
	count = 0;
	if (!format)
		return (-1);
	error_status = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_specifier(*(++format), list, &error_status);
		else
			count += print_char(*format);
		format++;
	}
	if (error_status)
		return (-1);
	return (count);
}
