
#include <stdio.h>
#include <stdlib.h>

int	strleng(char *str)
{
	int	len;

	len = 0;
		while (str[len])
	{
		len++;
	}
	return (len);
}

int	count(char **str)
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
	if (size == 0)
	{
		dest = malloc(sizeof(char) * 1);
		return (dest);
	}
	dest = malloc(sizeof(char) * (count(strs) + ((size - 1) * strleng(sep))));
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
/*
int main(int ac, char **av)
{
	if (ac < 1)
		return (0);
	char *test;
	test = ft_strjoin(3, av, ", 7");
	printf("%s", test);
}
*/
