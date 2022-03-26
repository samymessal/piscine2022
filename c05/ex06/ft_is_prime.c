#include <stdio.h>

int	ft_is_prime(int nb)
{
	unsigned int	i;
	
	i = 2;
	if (nb < 2)
		return (0);
	while (i*i <= (unsigned int)(nb))
	{
		if ((unsigned int)(nb % i) == 0)
			return (0);
		i++;
	}
	return (1);
}
/*
int	main()
{
	printf("%d", ft_is_prime(2147483847));
}
*/
