
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int	*ft_range(int min, int max)
{
	long long int	mini;
	long long int	maxi;
	long long int	i;
	int				*dest;
	long long int	j;

	mini = min;
	maxi = max;
	i = 0;
	j = 0;
	while (i < (maxi - mini))
		i++;
	dest = malloc(sizeof(int) * i);
	while (j < i)
	{
		dest[j] = mini + j;
		j++;
	}
	return (dest);
}

int main()
{
		int	*test = ft_range(SHRT_MAX, SHRT_MIN);
		printf("%d\n%d", test[0], test[65534]);
}
