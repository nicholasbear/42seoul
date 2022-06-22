#include "ft_print.h"

static int	find_format(char const *s, va_list ap)
{
	int	len;

	len = 0;
	if (*s == 'c')
		len += printf_c(ap);
	else if (*s == 's')
		len += printf_s(ap);
    else if (*s == 'p')
		len += printf_p(ap);
	else if (*s == 'd')
		len += printf_di(ap);
	else if (*s == 'i')
		len += printf_di(ap);
	else if (*s == 'u')
		len += printf_u(ap);
	else if (*s == 'x')
		len += printf_hex_lower(ap);
	else if (*s == 'X')
		len += printf_hex_upper(ap);
    else if (*s == '%')
		len += printf_per();
	return (len);
}

static int	find_Obelus(char const *s, va_list ap)
{
	int	len;

	len = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			len += find_format(s, ap);
			s++;
		}
		else
		{
			len += write(1, s, 1);
			s++;
		}
	}
	return (len);
}

int	ft_printf(char const *s, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, s);
	len = find_Obelus(s, ap);
	va_end(ap);
	return (len);
}