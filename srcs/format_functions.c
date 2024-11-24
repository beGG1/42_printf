#include "../includes/ft_printf.h"


t_format    *init_format(void)
{
	t_format	*f;

	f = (t_format *)malloc(sizeof(t_format));
	if (!f)
		return (NULL);
	f->dot = 0;
	f->hash = 0;
	f->perc = 0;
	f->plus = 0;
	f->type = 0;
	f->zero = 0;
	f->minus = 0;
	f->space = 0;
	f->width = 0;
	return (f);
}

int	reset_format(t_format *f)
{
	if (!f)
		return (0);
	f->dot = 0;
	f->hash = 0;
	f->perc = 0;
	f->plus = 0;
	f->type = 0;
	f->zero = 0;
	f->minus = 0;
	f->space = 0;
	f->width = 0;
	return (1);
}

static int	fill_prefix(const char *str, t_format *f)
{
	int	i;

	i = 0;
	while (in_set(str[i], "-+ 0#"))
	{
		if (str[i] == '-')
			f->minus = f->minus + 1;
		if (str[i] == '+')
			f->plus = f->plus + 1;
		if (str[i] == '0')
			f->zero = f->zero + 1;
		if (str[i] == ' ')
			f->space = f->space + 1;
		if (str[i] == '#')
			f->hash = f->hash + 1;
		i++;
	}
	return (i);
}

static int	fill_padding_precision(const char *str, t_format *f)
{
	int	i;

	f->width = ft_atoi(str);
	i = 0;
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	if (in_set(str[i], "icdsxX%%"))
		return (i);
	if (str[i] != '.')
		return (-1);
	i++;
	f->perc = ft_atoi(str + i);
	while (str[i] <= '9' && str[i] >= '0')
		i++;
	return (i);
}

int	fill_format(const char *str, t_format *f)
{
	int	i;
	int	valid;

	i = fill_prefix(str, f);
	valid = fill_padding_precision(str + i, f);
	if (valid < 0)
		return (-1);
	i += valid;
	if (in_set(str[i], "icdsxX%"))
		f->type = str[i];
	else
	 	return (-1);
	return (i);
}