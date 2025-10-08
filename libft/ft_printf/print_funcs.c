/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brensant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 14:08:38 by brensant          #+#    #+#             */
/*   Updated: 2025/08/04 14:11:19 by brensant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	print_char(char c)
{
	return (write(1, &c, 1));
}

int	print_str(const char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (write(1, "(null)", 6));
	while (*str)
	{
		count += write(1, str, 1);
		str++;
	}
	return (count);
}

int	print_nbr_base(long nbr, char *base)
{
	int	count;
	int	base_num;

	base_num = 0;
	while (base[base_num])
		base_num++;
	count = 0;
	if (nbr < 0)
	{
		count += write(1, "-", 1);
		nbr = -nbr;
	}
	if (nbr >= base_num)
	{
		count += print_nbr_base(nbr / base_num, base);
		return (count + print_nbr_base(nbr % base_num, base));
	}
	return (count += print_char(base[nbr]));
}

static int	print_mem_hex(unsigned long addr)
{
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	if (addr >= 16)
	{
		count += print_mem_hex(addr / 16);
		return (count + print_mem_hex(addr % 16));
	}
	return (print_char(base[addr]));
}

int	print_mem_addr(void *addr)
{
	if (!addr)
		return (write (1, "(nil)", 5));
	write(1, "0x", 2);
	return (2 + print_mem_hex((unsigned long)addr));
}
