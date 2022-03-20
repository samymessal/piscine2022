#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;
	
	i = 2;
	if (nb < 2)
		return (0);
	while (i < nb)
	{
		if (nb != i && nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while(nb)
	{
		if(ft_is_prime(nb))
			return (nb);
		nb++;
	}
	return(0);
}

int	main()
{
	printf("%d", ft_find_next_prime(48));
}
