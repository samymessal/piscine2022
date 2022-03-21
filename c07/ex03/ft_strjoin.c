
#include <stdio.h>
#include <stdlib.h>
char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int k;
	char	*dest;

	i = 0;
	k = 0;
	while (strs[i])
		i++;
	dest = malloc(sizeof(char) * i * size);
	i = 0;
	while (strs[i] && size > 0)
	{
		j = 0;
		while (strs[i][j] && j < size)
		{
			dest[k] = strs[i][j];
			j++;
			k++;
		}
		if (strs[i + 1])
			dest[k] = *sep;
		k++;
		i++;
	}
	return (dest);
}

int main(int ac, char **av)
{
	if (ac < 1)
		return (0);
	printf("%s", ft_strjoin(6, av, ","));
}
