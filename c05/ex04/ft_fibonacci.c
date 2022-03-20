
#include <stdio.h>

int ft_fibonacci(int index)
{
    if (index >= 0)
        return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
    else
        return (0);
}

int main()
{
    printf("%d", ft_fibonacci(5));
}
