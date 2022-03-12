static int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' \
		|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

static int	ft_data_check(long long data, long long sign)
{
	if (data < 0 && sign == 1)
		return (-1);
	else if (data < 0 && sign == -1)
		return (0);
	else
		return (sign * data);
}

int	ft_atoi(const char *str)
{
	long long		sign;
	long long		data;
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	sign = 1;
	data = 0;
	while (ft_isspace(*ptr) == 1)
		ptr++;
	if (*ptr == '-' || *ptr == '+')
	{
		if (*ptr == '-')
			sign *= -1;
		ptr++;
	}
	while (ft_isdigit(*ptr))
	{
		data = data * 10 + *ptr - '0';
		if (data < 0)
			break ;
		ptr++;
	}
	return (ft_data_check(data, sign));
}
