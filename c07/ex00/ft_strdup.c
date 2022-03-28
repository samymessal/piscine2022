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
	if (!dest)
		return (0);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
int main()
{
	printf("%s\n", ft_strdup("hello"));
	printf("%s", strdup("hello"));
}
*/
