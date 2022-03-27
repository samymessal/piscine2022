#include <stdio.h>
#include <limits.h>

int	ft_sqrt(int nb)
{
	int	i;
	int	optimizer;

	i = 0;
	if (nb == 1)
		return (1);
	optimizer = nb / 2;
	if (optimizer * optimizer == nb)
		return optimizer;
	while(i < optimizer)
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
/*
int	main()
{
		printf("%d", ft_sqrt(-1));
}
*/

