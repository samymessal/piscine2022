#include <stdio.h>
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		++i;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		++i;
	}
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	int			j;
	t_stock_str	*my_tab;
	char		*copy;
	
	i = 0;
	j = 0;
	my_tab = malloc(sizeof(*my_tab) * (ac + 1));
	while (i < ac && av[i])
	{
		copy = malloc(sizeof(char) * ft_strlen(av[i]));
		ft_strcpy(copy, av[i]);
		my_tab[i].size = ft_strlen(av[i]);
		my_tab[i].str = av[i];
		my_tab[i].copy = copy;
		i++;
	}
	my_tab[i].size = 0;
	my_tab[i].str = 0;
	my_tab[i].copy = 0;
	return (my_tab);
}

int main(int ac, char **av)
{
	if (ac < 1)
		return (0);
	printf("%d\n%s\n%s", ft_strs_to_tab(ac, av)[2].size,ft_strs_to_tab(ac,
	av)[2].str,ft_strs_to_tab(ac, av)[2].copy);
}
