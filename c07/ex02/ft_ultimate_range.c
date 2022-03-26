#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	unsigned int	i;
	unsigned int	j;

	if (min >= max)
	{	
		range = NULL;
		return (0);
	}
	i = max - min;
	j = 0;
	range[0] = malloc(sizeof(int) * i);
	if (!range[0])
		return (-1);
	while (j < i)
	{
		range[0][j] = min + j;
		j++;
	}
	return (i);
}
/*
int	main()
{
	int	*range;
	int	i;
	int	y;

	i = 0;
	y = ft_ultimate_range(&range, 30, 40);
	printf("%d\n", y);
	while (i < y)
	{
		printf("%d\n", range[i]);
		i++;
	}
}
*/
