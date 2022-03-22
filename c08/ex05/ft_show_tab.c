#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

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

void    ft_putnbr(int nbr)
{
    long int    nb;

    nb = nbr;
	if (nb < 0)
	{
        ft_putchar(45);
		nb = nb * (-1);
	}
	if (nb < 10)
	{
		ft_putchar(nb + '0');
		return ;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while(str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return ;
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

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	
	i = 0;
	while(par[i].str)
	{
		ft_putstr(par[i].str);
		write(1, "\n", 1);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		ft_putstr(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}


int	main(int ac,char **av)
{
	if (ac < 1)
		return (0);
	t_stock_str	*my_test;
	my_test = ft_strs_to_tab(ac, av);
	ft_show_tab(my_test);
}
