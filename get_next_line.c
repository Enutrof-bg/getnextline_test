/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevwang <kevwang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:18:52 by kevwang           #+#    #+#             */
/*   Updated: 2025/05/05 17:18:54 by kevwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *newlist;
	int i;
	int j;

	i = 0;
	j = 0;
	newlist = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	while (s1[i])
	{
		newlist[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		newlist[i + j] = s2[j];
		j++;
	}
	newlist[i + j] = '\0';
	// free(s1);
	return (newlist);

}

char	*get_next_line(int fd)
{	
	int readfd;
	char *temp;
	char *str;
	char *newchar;
	int i = 0;

	if (fd < 1)
	{
		return (NULL);
	}
	readfd = 1;
	newchar = malloc(sizeof(char) * 2);
	if (!newchar)
		return (NULL);
	newchar[0] = '0';
	newchar[1] = '\0';
	str = malloc(sizeof(char) * 1);
	if (!str)
	{
		free(newchar);
		return (NULL);
	}
	str[0] = '\0';
	while (readfd > 0 && newchar[0] != '\n')
	{
		readfd = read(fd, newchar, 1);
		// str = "";
		// printf("%d\n", readfd);
		// printf("%s", newchar);
		// write(1, &newchar[0],1);
		// str = newline;
		// free(newline);
		temp = ft_strjoin(str , newchar);
		free(str);
		// str = temp;
		
		str = malloc(sizeof(char) * (ft_strlen(temp) + 1));
		if(!str)
		{
			free(newchar);
			free(str);
			return (NULL);
		}
		while (temp[i])
		{
			str[i] = temp[i];
			i++;
		}
		str[ft_strlen(temp)] = '\0';
		free(temp);
		temp = NULL;

		i = 0;
		
	}
	free(newchar);
	return (str);
}
/*
int main()
{
	int fd = open("toto.txt", O_RDONLY);
	if (fd < 0)
	{
		write(1, "Erreur\n",7);
	}
	char *newstr = get_next_line(fd);
	printf("%s", newstr);
	free(newstr);

	newstr = get_next_line(fd);
	printf("%s", newstr);
	free(newstr);

	newstr = get_next_line(fd);
	printf("%s", newstr);
	free(newstr);

	newstr = get_next_line(fd);
	printf("%s", newstr);
	free(newstr);
	// printf("%s\n", ft_strjoin("bonjour", "123456"));
}
*/