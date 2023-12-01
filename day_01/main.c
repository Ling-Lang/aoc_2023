/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkulka <jkulka@student.42heilbronn.de >    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 12:36:11 by jkulka            #+#    #+#             */
/*   Updated: 2023/12/01 13:48:43 by jkulka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>
#include <stdbool.h>

enum num                                                                   
{
    ONE = 1,                                                                                                              
    TWO = 2,                                                                                                              
    THREE = 3,                                                                                                              
    FOUR = 4,                                                                                                              
    FIVE = 5,                                                                                                              
    SIX = 6,                                                                                                              
    SEVEN = 7,                                                                                                              
    EIGHT = 8,                                                                                                              
    NINE = 9                                                                                                      
};   

const char * const num_str[] =
{
    [ONE] = "one",
    [TWO] = "two",
    [THREE] = "three",
    [FOUR] = "four",
    [FIVE] = "five",
    [SIX] = "six",
    [SEVEN] = "seven",
    [EIGHT] = "eight",
    [NINE] = "nine"
};

char **read_map(char *path);
char *get_num(char *str);

char	*ft_strjoin_norm(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	str = (char *)malloc(strlen((char *)s1) + strlen((char *)s2) + 1);
	if (!s1 || !s2 || !(str))
	{
		return (0);
	}
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
int main()
{
    char **map = read_map("./input");
    char *tmp;
    int i = 0;
    int j = 0;
    int k = 0;
    int res = 0;
    while(map[i] != NULL)
    {
        tmp = get_num(map[i]);
        res += atoi(tmp);
        i++;
    }
    printf("%d\n", res);
    
}
#include <unistd.h>
char get_full_num(char *str)
{
    int len = strlen(str);
    int i = 0;
        if((!strncmp(str, num_str[ONE], 3)))
            return ('1');
        else if((!strncmp(str, num_str[TWO], 3)))
            return ('2');
        else if((!strncmp(str, num_str[THREE], 5)))
            return ('3');
        else if((!strncmp(str, num_str[FOUR], 4)))
            return ('4');
        else if((!strncmp(str, num_str[FIVE], 4)))
            return ('5');
        else if((!strncmp(str, num_str[SIX], 3)))
            return ('6');
        else if((!strncmp(str, num_str[SEVEN], 5)))
            return ('7');
        else if((!strncmp(str, num_str[EIGHT], 5)))
            return ('8');
        else if((!strncmp(str, num_str[NINE], 4)))
            return ('9');
    return 0;
}
char *get_num(char *str)
{
    int i = 0;
    int j = strlen(str);
    bool first, last = false;
    char num1 = 0;
    char num2 = 0;
    char tmp1 = 0;
    char tmp2 = 0;
    char *res;
    res = (char *)malloc(sizeof(char) * 3);
    while(str[i] != '\0' || str[i] != '\n')
    {
        if(isdigit(str[i]) || (tmp1 = get_full_num(&str[i]) != 0))
        {
            if(tmp1)
                num1 = get_full_num(&str[i]);
            else
                num1 = str[i];
            break;
        }
        i++;
    }
    while(j > 0)
    {
        if(isdigit(str[j]) || (tmp2 = get_full_num(&str[j]) != 0))
        {
            if(tmp2)
                num2 = get_full_num(&str[j]);
            else
                num2 = str[j];
            break;
        }
        j--;
    }
    if(!num2)
        num2 = num1;
    res[0] = num1;
    res[1] = num2;
    res[2] = '\0';
    return res;
}
