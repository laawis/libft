#include <stdlib.h> 
#include <stdio.h>

int    ft_strlen(char *str)
{
    int    i = 0;
    
    while(str[i] != '\0')
        i++;
    return (i);
}

int    is_doublon(char *base)
{
    int    i = 0;
    int    j;

    while (base[i] != '\0')
    {
        j = 0;
        while (base[j] != '\0')
        {
            if (j != i && base[j] == base[i])
                return (1);
            else
                j++;
        }
        i++;
    }
    return (0);
}

int    is_valid_base(char *base)
{
    int    i = 0;

    if (base == NULL || ft_strlen(base) == 1 || is_doublon(base) == 1)
        return (0);
    while (base[i] != '\0')
    {
        if (base[i] == '-' || base[i] == '+' || ft_strlen(base) == 1 || base[i] == ' ' || base[i] == '\t'
            || base[i] == '\n')
            return (0);
        i++;
    }
    return (1);        
}

int    get_position(char *base, char c)
{
    int    i = 0;

    while (base[i] != '\0')
    {
        if (base[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

int    ft_atoi_base(char *str, char *base)
{
    int    i = 0;
    int    sign = 1;
    int    res = 0;
    int    len_base;

    if (str == NULL || is_valid_base(base) == 0)
        return (0);
    while (str[i] != '\0' && (str[i] == '\n' || str[i] == '\t' || str[i] == ' '))
        i++;
    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    len_base = ft_strlen(base);
    while (str[i] != '\0')
    {
		// str[i] on veut trouver son index dans la base
		// i index dans la str
		// str = "qwdqda"
		// i = 5;
		// 'a'
		// Base => "bcdea"
        if (get_position(base, str[i]) == -1)
            return (res);
        res = res * len_base + get_position(base, str[i]);
		// str[i] = '0' -> '9'
		// str[i] - '0' => 0 et 9
        i++;
    }
    return (res * sign);
}

int    main(int argc, char **argv)
{
    if (argc == 3)
        printf("%d\n", ft_atoi_base(argv[1], argv[2]));
    return(0);
}
/*
	Si un paramètre contient une erreur la fonction renvoie 0. Une erreur peut être :
◦ la base est vide ou est de taille 1 ;
◦ la base contient deux fois le même caractère ;
◦ la base contient les caractères + ou - ou des whitespaces ;

*/
// "abc"
// char* base = 115;
// base =  115
// 116
// 117
// 118 != NULL

// NULL => adresse qui ne pointe sur RIEN.
// '\0' ou 0 dans un char c'est la fin d'une chaine de caracteres. Adresse qui pointe sur un char 
