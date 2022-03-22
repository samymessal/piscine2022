#include <stdio.h>

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

int	ft_check_match(char *str, char *charset, int index)
{
	int	i;

	i = 0;
	while (charset[i] && str[index])
	{
		if (charset[i] != str[index])
			return (0);
		i++;
		index++;
	}
	return (index);
}

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	match;
	int	total;

	i = 0;
	match = 0;
	total = 0;
	if (!ft_check_match(str, charset, 0))
		total += 1;
	while (str[i])
	{
		if(str[i] == charset[0])
		{
			match = ft_check_match(str, charset, i);
			if (ft_check_match(str, charset, i) && str[match] &&
				!ft_check_match(str, charset, match))
			{
				total++;
			}
		}
		i++;
	}
	return (total);
}

char	*ft_strcpy(char *dest, char *word, int index)
{
	int	i;

	i = 0;
	while (word[index] && i < index)
	{
		dest[i] = word[index];
		i++;
	}
	dest[i] = word[i];
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	int		k;
	int		match;
	char	**tab;

	i = 0;
	j = 0;
	k = 0;
	match = 0;
	tab = malloc(sizeof(char*) * ft_count_words(str, charset));
	while (str[i])
	{
		if (str[i] == charset[0])
		{
			match = ft_check_match(str, charset, i);
			if (ft_check_match(str, charset, i) && str[match] &&
				!ft_check_match(str, charset, match))
			{
				k = match;
			}
			else
				k = 0;
		}
		while(str[k] && k != 0)
		{
			if (str[k] == charset[0])
			{
				match = ft_check_match(str, charset, i);
				if (ft_check_match(str, charset, i) && str[match] &&
					!ft_check_match(str, charset, match))
				{
					k = match;
				}
				else
					k = 0;
			}
		}
	}
}


int	main()
{
	char	test[] = "lol id i id";
	char	charset[]= " i";
	printf("%d", ft_count_words(test, charset));
}
