#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		++i;
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!(dest))
		return (NULL);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*my_tab;
	
	i = 0;
	my_tab = malloc(sizeof(t_stock_str) * (ac + 1));
	if (!my_tab)
		return (NULL);
	while (i < ac)
	{
		my_tab[i].size = ft_strlen(av[i]);
		my_tab[i].str = av[i];
		my_tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	my_tab[i].size = 0;
	my_tab[i].str = 0;
	my_tab[i].copy = 0;
	return (my_tab);
}
/*
int main(int ac, char **av)
{
	if (ac < 1)
		return (0);
	printf("%d\n%s\n%s", ft_strs_to_tab(ac, av)[2].size,ft_strs_to_tab(ac,
	av)[2].str,ft_strs_to_tab(ac, av)[2].copy);
}
*/
