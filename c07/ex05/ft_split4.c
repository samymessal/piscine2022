#include<stdlib.h>
#include<stdio.h> 

int    ft_strlen(char *str)
{
    int    i;

    i = 0;
    while (str[i] && str)
        i++;
    return (i);
}

int    is_set(char c, char *charset)
{
    int    i;

    i = 0;
    while (charset[i] && charset)
        if (charset[i++] == c)
            return (1);
    return (0);
}

int    nbr_word(char *str, char *charset)
{
    int    i;
    int    r;

    i = 0;
    r = 0;
    while (str[i] && str)
    {
        while (is_set(str[i], charset))
            i++;
        if (!str[i])
            return (r);
        if (!(is_set(str[i], charset)))
        {
            r++;
            while (!(is_set(str[i], charset)))
                i++;
            i -= 1;
        }
        i++;
    }
    return (r);
}

void    fill_split(char split, char *str, char *charset, int nbr_mot)
{
    int        i;
    int        x;
    int        y;
    int        len;

    i = 0;
    x = 0;
    y = 0;
    len = ft_strlen(str);
    while ((i < len) && (x < nbr_mot) && str)
    {
        y = 0;
        while (is_set(str[i], charset))
            i++;
        if (!str[i])
            return ;
        while (!(is_set(str[i], charset)))
            split[x][y++] = str[i++];
        split[x][y] = '\0';
        x++;
    }
    if (split[x])
        split[x] = 0;
}

char    ft_split(char *str, char *charset)
{
    int        i;
    int        len_str;
    int        nbr_mot;
    char    **split;

    i = 0;
    len_str = ft_strlen(str);
    nbr_mot = nbr_word(str, charset);
    split = malloc(sizeof(char *) * nbr_mot);
    while (i < nbr_mot)
        split[i++] = malloc(sizeof(char) * (len_str + 1));
    fill_split(split, str, charset, nbr_mot);
    return (split);
}
