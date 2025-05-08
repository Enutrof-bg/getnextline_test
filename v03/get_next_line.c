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

char *ft_strdup(char *str)
{
	char *newstr;
	int i;

	i = 0;
	newstr = malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!newstr)
		return (NULL);
	while (str[i])
	{
		newstr[i] = str[i];
		i++;
	}
	newstr[i] = '\0';
	return (newstr);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *newlist;
	int i;
	int j;

	i = 0;
	j = 0;
	newlist = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!newlist)
		return (NULL);
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

char *ft_calloc(int size)
{
	int i;
	char *newcalloc;

	i = 0;
	newcalloc = malloc(sizeof(char) * (size));
	if (!newcalloc)
		return (NULL);
	while (i < size)
	{
		newcalloc[i] = 0;
		i++;
	}
	return (newcalloc);
}

char *ft_str_return(char *str)
{
	int i;
	int j;
	char *newstr;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (str[i] == '\n')
		i++;
	newstr = malloc(sizeof(char) * (i + 1));
	if (!newstr)
		return (NULL);
	while (j < i)
	{
		newstr[j] = str[j];
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}

char	*ft_str_reste(char *str)
{
	int i;
	int j;
	char *newstr;

	i = 0;
	j = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	while (str[i + j] != '\0')
		j++;
	newstr = malloc(sizeof(char) * (j + 1));
	if (!newstr)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		newstr[j] = str[i + j];
		j++;
	}
	newstr[j] = '\0';
	return (newstr);
}

int ft_check(char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *get_next_line(int fd)
{
	int readfd;
	static	char *str;
	char *charread;
	char *temp;
	char *strreturn;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	if (!str)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
	}
	// str = temp;
	charread = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!charread)
		return (NULL);
	while ((readfd = read(fd, charread, BUFFER_SIZE)) > 0/*&& ft_check(str, '\n') != 1*/)
	{
		charread[readfd] = '\0';
		temp = ft_strjoin(str, charread);
		if (!temp)
			return (NULL);
		free(str);
		str = ft_strdup(temp);
		if (!str)
			return (NULL);
		free(temp);
		if (ft_check(charread, '\n') == 1)
		{
			break;
		}
	}
	free(charread);
	if (readfd <= -1)
		{
			return (NULL);
		}
	if (readfd <= 0 && (str[0] == '\0' || !str))
	{
		if (str)
		{
			free(str);
			str = NULL;
		}
		return (NULL);
	}
	strreturn = ft_str_return(str);
	if (!strreturn)
		return (NULL);
	temp = ft_str_reste(str);
	if (!temp)
		return (NULL);
	free(str);
	str = ft_strdup(temp);
	free(temp);
	if (!str)	
		return (NULL);
	if (str && str[0] == '\0')
	{
		free(str);
		str = NULL;
	}
	// if (readfd < 0)
		// return (NULL);
	return (strreturn);
}
/*
int main()
{
	// int fd = STDIN_FILENO;
	int fd = open("toto.txt", O_RDONLY);
	// if (fd < 0)
	// {
	// 	write(1, "Erreur\n",7);
	// }

	// printf("%d\n", BUFFER_SIZE);

    char *line;
    int idx = 0;
    do {
    	line = get_next_line(fd);
    	printf("[%d] '%s'\n", idx++, line);
    	free(line);
	} while (line != NULL);
}
*/
	// char *newstr = get_next_line(fd);
	// printf("%s", newstr);
	// free(newstr);

	// //printf("test2");
	// newstr = get_next_line(fd);
	// printf("%s", newstr);
	// free(newstr);
	
	// //printf("test3");
	// newstr = get_next_line(fd);
	// printf("%s", newstr);
	// free(newstr);

	// //printf("test4");
	// newstr = get_next_line(fd);
	// printf("%s", newstr);
	// free(newstr);




/*
char	*get_next_line(int fd)
{	
	int readfd;
	char *temp;
	static char *str;
	char *newchar;
	char *newline;
	int i = 0;

	if (fd < 1)
	{
		return (NULL);
	}
	// readfd = 1;
	newchar = ft_calloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!newchar)
		return (NULL);
	// str = ft_calloc(sizeof(char) * 1);
	// if (!str)
	// {
	// 	free(newchar);
	// 	return (NULL);
	// }
	while ((readfd = read(fd, newchar, BUFFER_SIZE)) > 0)
	{
		newchar[readfd] = 0;
		if(str == NULL)
			str = ft_calloc(sizeof(char) * 1);
		temp = ft_strjoin(str , newchar);
		// free(str);
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
		if (ft_check(str, '\n') == 1 || ((ft_check(str, '\n') == 0 && readfd < 1)))
		{
			
			// printf("result str1:\n%s|fin\n\n", str);
			newline = ft_strchr(str);
			str = ft_str_reste(str);
			// printf("result newline1:%s|fin", newline);
			// printf("result str2:\n%s|fin\n\n", str);
			free(newchar);
			return (newline);
		}
	}
	free(newchar);
	return (str);
}
*/

	// static int size = BUFFER_SIZE;
/*
	printf("size : %d\n" , BUFFER_SIZE);
	char *buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	int readtest = read(fd, buf, BUFFER_SIZE);
	buf[readtest] = '\0';
	printf("readtest : %d\n%s\n", readtest, buf);
*/
	// printf("%s\n", ft_strjoin("bonjour", "123456"));



// save de getnextline avec buffer 1
/*
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
	newchar = ft_calloc(sizeof(char) * 2);
	if (!newchar)
		return (NULL);
	str = ft_calloc(sizeof(char) * 1);
	if (!str)
	{
		free(newchar);
		return (NULL);
	}
	while ((readfd = read(fd, newchar, 1)) > 0)
	{
		// readfd = read(fd, newchar, 1);
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
		if (newchar[0] == '\n')
			break;
	}
	free(newchar);
	return (str);
}*/