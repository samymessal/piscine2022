
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int	*ft_range(int min, int max)
{
	unsigned int	mini;
	unsigned int	maxi;
	unsigned int	i;
	int				*dest;
	unsigned int	j;

	mini = min;
	maxi = max;
	dest = malloc(sizeof(int) * 0);
	if (min >= max)
		return dest;
	i = 0;
	if (min < 0)
		i = maxi + mini;
	else
		i = maxi - min;
	j = 0;
	dest = malloc(sizeof(int) * i);
	while (j < i)
	{
		dest[j] = min + j;
		j++;
	}
	return (dest);
}

int main()
{
		int	*test = ft_range(-200, -100);
		printf("%d\n%d", test[0], test[80]);
}
