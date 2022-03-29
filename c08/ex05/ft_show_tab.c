#include <unistd.h>
#include <stdlib.h>
#include "ft_stock_str.h"

void    ft_putchar(char c)
{
    write(1, &c, 1);
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
/*
int	main(int ac,char **av)
{
	if (ac < 1)
		return (0);
	t_stock_str	*my_test;
	my_test = ft_strs_to_tab(ac, av);
	ft_show_tab(my_test);
}
*/
