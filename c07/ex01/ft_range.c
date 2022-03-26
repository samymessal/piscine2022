
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int	*ft_range(int min, int max)
{
	unsigned int	i;
	int				*dest;
	unsigned int	j;

	dest = malloc(sizeof(int) * 0); 
	if (min >= max)
		return (dest);
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
		int	*test = ft_range(-200, 0);
		int	i = 0;
		while (i < 200)	
			printf("%d\n", test[i++]);
}
*/
