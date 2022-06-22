#include "ft_printf.h"

int	printf_c(va_list ap)
{
	int		len;
	char	arg;

	len = 0;
	arg = va_arg(ap, size_t);
	len += write(1, &arg, 1);
	return (len);
}

int	printf_s(va_list ap)
{
	int		len;
	char	*args;

	args = va_arg(ap, char *);
	if (!args)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = ft_strlen(args);
	write(1, args, len);
	return (len);
}

int	printf_p(void)
{
	write(1, "%", 1);
	return (1);
}

int	printf_di(va_list ap)
{
	char	*temp;
	int		len;
	int		arg;

	arg = va_arg(ap, size_t);
	temp = ft_itoa(arg);
	len = ft_strlen(temp);
	write(1, temp, len);
	free(temp);
	return (len);
}