#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_is_charset(char *str, char *charset, int index)
{
	int	i;

	i = 0;
	while (charset[i] != '\0' && str[index])
	{
		if (charset[i] == str[index])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (ft_is_charset(str, charset, i))
			i++;
		if (i != 0 && ft_is_charset(str, charset, i - 1) && str[i])
			words++;
		i++;
	}
	if (!ft_is_charset(str, charset, i - 1))
		words++;
	return(words);
}

char	*ft_strcpy(char *src, char *dest,char *charset, int index)
{
	int	i;

	i = 0;
	while (src[index] && !ft_is_charset(src, charset, index))
	{
		dest[i] = src[index];
		i++;
		index++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int	i;
	int	j;
	int	k;
	char	**tab;

	i = 0;
	j = 0;
	k = 0;
	tab = malloc(sizeof(char*) * ft_count_words(str, charset));
	if (!tab)
		return (NULL);
	while (str[i])
	{
		while(ft_is_charset(str, charset, i))
			i++;
		k = i;
		while (!ft_is_charset(str, charset, i))
			i++;
		tab[j] = malloc(sizeof(char) * (i - k + 1));
		if (!tab[j])
			return (NULL);
		ft_strcpy(str, tab[j], charset, k);
		j++;
	}
	return (tab);
}

int	main()
{
	char **test;
	char *charset = " ; ";
	char *phrase = " LOL  ja";
	int	i;

	i = 0;
	test = ft_split(phrase, charset);
	//while (test[i])
	//{
		printf("%d\n", test[1][0]);
	//	i++;
	//}
}
