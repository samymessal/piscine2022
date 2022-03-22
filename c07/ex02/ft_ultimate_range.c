#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;

	if (min >= max)
	{	
		range = NULL;
		return (0);
	}
	i = 0;
	i = max - min;
	j = 0;
	len = 0;
	range = malloc(sizeof(int *) * 1);
	range[0] = malloc(sizeof(int) * i);
	if (!range || !range[0])
		return (-1);
	while (j < i && range[0][j])
	{
		range[0][j] = min + j;
		j++;
	}
	while (range[len])
		len++;
	return (len);
}

int	main()
{
	int	**range;

	range = malloc(sizeof(int *) * 1);
	printf("%d", ft_ultimate_range(range, 40, 30));
}
