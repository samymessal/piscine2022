#include <stdio.h>
#include <limits.h>
int	ft_is_prime(int nb)
{
	unsigned int	i;
	
	i = 3;
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (i*i <= (unsigned int)nb)
	{
		if ((unsigned int)(nb % i) == 0)
			return (0);
		i = i + 2;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 2)
		return (2);
	while(nb)
	{
		if(ft_is_prime(nb))
			return (nb);
		if (nb % 2 == 0)
			nb++;
		else
			nb = nb + 2;
	}
	return(0);
}
/*
int	main()
{
	printf("%d", ft_find_next_prime(INT_MAX - 10));
}
*/
