
#include <stdio.h>
#include <stdlib.h>

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

int	ft_count(char **str)
{
	int	i;
	int	j;
	int	total;

	i = 0;
	j = 0;
	total = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			j++;
		total += j;
		i++;
	}
	return (total);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int k;
	char	*dest;

	i = 0;
	k = 0;
	dest = malloc(sizeof(char) * (ft_count(strs) + ((size - 1) * ft_strlen(sep))));
	if (!dest)
		return (0);
	while (strs[i] && size > 0)
	{
		j = 0;	
		while (strs[i][j] && i < size)
			dest[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			dest[k++] = sep[j++];
		i++;
	}
	return (dest);
}

int main(int ac, char **av)
{
	if (ac < 1)
		return (0);
	char *test;
	test = ft_strjoin(0, av, ", 7");
	printf("%s", test);
}
