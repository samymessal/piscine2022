int ft_iterative_factorial(int nb)
{
	int   i;

	if (nb < 0)
		return (0);
	if (nb <= 1)
		return(1);
	i = nb - 1;
	while (i >= 1)
	{
    	nb *= i;
    	i--;
	}
	return (nb);
}
