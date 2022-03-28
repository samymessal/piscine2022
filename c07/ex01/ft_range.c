
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int	*ft_range(int min, int max)
{
	unsigned int	i;
	int				*dest;
	unsigned int	j;

	if (min >= max)
	{
		dest = NULL;
		return (dest);
	}
	i = max - min;
	j = 0;
	dest = malloc(sizeof(int) * i);
	if (!dest)
		return (NULL);
	while (j < i)
	{
		dest[j] = min + j;
		j++;
	}
	return (dest);
}
/*
int main()
{
		int	*test = ft_range(0, -10);
		int	i = 0;
		while (i < 10)	
			printf("%d\n", *test);
}
*/
