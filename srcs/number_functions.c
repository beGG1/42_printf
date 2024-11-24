#include "../includes/ft_printf.h"

int	ft_numlen(int n)
{
	int	len;

	if (n <= 0)
		len = 1;
	else
		len = 0;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_unumlen(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*ft_utoa(unsigned int n)
{
	char		*str;
	int		    len;

	len = ft_unumlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	long		num;
	char		*str;
	int		    len;
	int		    i;

	len = ft_numlen(n);
	num = n;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		str[i] = '-';
		i++;
		num = -num;
	}
	str[len] = '\0';
	while (len > i)
	{
		len--;
		str[len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

int	print_int(int n)
{
    char    *nbr;
    int     temp;

    nbr = ft_itoa(n);
    if (!nbr)
        return (-1);
    temp = print_string(nbr);
    free(nbr);
    return (temp);
}

int	print_uint(unsigned int n)
{
    char    *nbr;
    int     temp;

    nbr = ft_utoa(n);
    if (!nbr)
        return (-1);
    temp = print_string(nbr);
    free(nbr);
    return (temp);
}

int	print_hex(int n, char a)
{
	char    *nbr;
    int     temp;

    nbr = int_to_hex(n, a);
    if (!nbr)
        return (-1);
    temp = print_string(nbr);
    free(nbr);
    return (temp);
}