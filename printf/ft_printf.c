#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <limits.h>

int	ft_putchar(char c, int i)
{
	i += write(1, &c, 1);
	return (i);
}

int	print_str(char *s, int i)
{
	if (!s)
		i = print_str("(null)", i);
	else
	{
		while (*s)
		{
			i = ft_putchar(*s, i);
			s++;
		}
	}
	return (i);
}

int	print_decimal(int d, int i)
{
	if (d == -2147483648)
		i = print_str("-2147483648", i);
	else if (d < 0)
	{
		i = ft_putchar('-', i);
		i = print_decimal(d * -1, i);
	}
	else if (d >= 0 && d <= 9)
		i = ft_putchar(d + 48, i);
	else
	{
		i = print_decimal(d / 10, i);
		i = print_decimal(d % 10, i);
	}
	return (i);
}

int	print_hexa(unsigned int x, int i)
{
	if (x == 0)
		i = ft_putchar('0', i);
	else if (x >= 16)
	{
		i = print_hexa(x / 16, i);
		i = print_hexa(x % 16, i);
	}
	else
	{
		if (x <= 9)
			i = ft_putchar(x + 48, i);
		else
			i = ft_putchar(x + 'a' - 10, i);
	}
	return (i);
}

int	ft_printf(char *format, ...)
{
	va_list	args;
	int	i;
	int	j;

	i = 0;
	j = 0;
	va_start(args, format);
	while (format[j])
	{
		if (format[j] == '%')
		{
			j++;
			if (format[j] == 's')
				i = print_str(va_arg(args, char *), i);
			if (format[j] == 'd')
				i = print_decimal(va_arg(args, int), i);
			if (format[j] == 'x')
				i = print_hexa(va_arg(args, unsigned int), i);
		}
		else
			i = ft_putchar(format[j], i);
		j++;
	}
	return (i);
}

int	main()
{
	//printf("%d\n", INT_MAX);
	printf("%d\n", ft_printf("string = %s\ndecimal = %d\nhexa = %x\n","mehdi", 42, 1337));
	printf("%d\n", printf("string = %s\ndecimal = %d\nhexa = %x\n","mehdi", 42, 1337));

}
