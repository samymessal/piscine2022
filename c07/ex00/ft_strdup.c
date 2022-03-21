#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char	*ft_strdup(char *src)
{
	int	i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * i);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

int main()
{
	printf("%s\n", ft_strdup("hello"));
	printf("%s", strdup("hello"));
}
