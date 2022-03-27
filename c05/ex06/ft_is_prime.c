#include <stdio.h>

int	ft_is_prime(int nb)
{
	unsigned int	i;
	
	i = 3;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (i*i <= (unsigned int)(nb))
	{
		if ((unsigned int)(nb % i) == 0)
			return (0);
		i = i + 2;
	}
	return (1);
}
/*
int	main()
{
	printf("%d", ft_is_prime(15));
}
*/
