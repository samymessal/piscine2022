
int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || (base[i] >= 9 && base[i] <= 13)
			|| base[i] == ' ')
			return (0);
		j = 0;
		while (base[j])
		{
			if (base[i] == base[j] && j != i)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_which_index(char *base, char str)
{
	int	index;

	index = 0;
	while (base[index])
	{
		if (base[index] == str)
			return (index);
		index++;
	}
	return (-1);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	ft_exponential(int num, int exp)
{
	int	i;
	int	result;

	i = 1;
	result = 1;
	if (exp <= 0)
		return (1);
	while (i <= exp)
	{
		result *= num;
		i++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int				i;
	int				neg;
	long long int	result;
	int				base_len;
	int 			end;

	i = 0;
	neg = 1;
	result = 0;
	base_len = ft_strlen(base);
	while (str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	while (str[i] == 43 || str[i] == 45)
		if (str[i++] == 45)
			neg *= - 1;
	end = i;
	while (ft_which_index(base, str[i]) != -1)
		i++;
	while (end < i)
	{
		result += ft_which_index(base, str[end]) * ft_exponential(base_len, i -
		end - 1);
		end++;
	}
	return (result * neg);
}
