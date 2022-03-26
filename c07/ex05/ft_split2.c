#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	ft_is_charset(char *str, char *charset, int index)
{
	int	len_set;
	int	i;

	len_set = ft_strlen(charset) + index;
	i = 0;
	while (index < len_set && str[index] && charset[i])
	{
		if (str[index] == charset[i])
			return (1);
		i++;
		index++;
	}
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	words;
	int	len_set;

	i = 0;
	words = 0;
	len_set = ft_strlen(charset);
	if (!ft_is_charset(str, charset, 0))
		words++;
	while (str[i])
	{
		if (ft_is_charset(str, charset, i) && str[i + len_set])
		{
			words++;
		}
		i++;
	}
	return(words);
}

char	*ft_strcpy(char *dest, char *str, int start, int end)
{
	int	i;

	i = 0;
	while (str[start] && start < end)
	{
		dest[i] = str[start];
		i++;
		start++;
	}
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		len_set;
	int		k;
	char	**strings;

	i = 0;
	j = 0;
	k = 0;
	len_set = ft_strlen(charset);
	strings = malloc(sizeof(char*) * ft_count_words(str, charset));
	while (str[i])
	{
		if (ft_is_charset(str, charset, i) && !ft_is_charset(str, charset, i + 1))
		{
			strings[k] = malloc(sizeof(char) * (i - j + 1));
			ft_strcpy(strings[k], str, j, i);
			k++;
			j = i + 1;
		}
		i++;
	}
	if (str[i] == '\0' && !ft_is_charset(str, charset, i - 1))
	{
		strings[k] = malloc(sizeof(char) * (i - j + 1));
		ft_strcpy(strings[k], str, j , i);
		k++;
		j = i + 1;
	}
	return (strings);
}

int	main()
{
	char **lol;
	int	i;

	i = 0;
	lol = ft_split("jai dfaim de ouf l", "       ");
	while(lol[i])
	{
		printf("%s\n", lol[i]);
		++i;
	}
}
