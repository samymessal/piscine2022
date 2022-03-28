#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	check_base(char *base);
int	ft_strlen(char *str);
int	ft_which_index(char *base, char str);
int	ft_atoi_base(char *str, char *base);

int	ft_numlen(int num)
{
	int	len;

	len = 0;
	if (num < 0)
		num *= -1;
	if (num == 0)
		len++;
	while(num > 0)
	{
		num /= 10;
		len++;
	}
	return(len);
}

char	*ft_itoa_base(int nbr, char *base)
{
	int				base_len;
	int				i;
	long long int	nb;
	char			*converted_num;

	i = 0;
	base_len = ft_strlen(base);
	nb = nbr;
	converted_num = malloc(sizeof(int) * 40);
	if (!converted_num)
		return (NULL);
	if (nb < 0)
	{
		converted_num[i++] = '-';
		nb *= -1;
	}
	while (nb >= base_len )
	{
		converted_num[i++] = base[nb % base_len];
		nb /= base_len;
	}
	if (nb < base_len)
		converted_num[i++] = base[nb];
	converted_num[i] = '\0';
	return (converted_num);
}

char *ft_rev_tab(char *tab)
{
	int	i;
	int	size;
	char temp;

	i = 0;
	temp = 'a';
	size = ft_strlen(tab);
	if (tab[0] == '-')
	{
		i = 1;
	}
	while (i < size - 1)
	{
		temp = tab[i];
		tab[i] = tab[size - 1];
		tab[size - 1] = temp;
		i++;
		size--;
	}
	return(tab);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	atoi_res;
	char	*result;

	if (!check_base(base_from) || !check_base(base_to))
		return (0);
	atoi_res = ft_atoi_base(nbr, base_from);
	result = ft_itoa_base(atoi_res, base_to);
	ft_rev_tab(result);
	return (result);
}
/*
int main()
{
    char nbr[] = "-80000000";
    char base_from[] = "0123456789abcdef";
    char base_to[] = "01";
    printf("Test : %s\n", ft_convert_base(nbr, base_from, base_to));
    return (0);
}
*/
