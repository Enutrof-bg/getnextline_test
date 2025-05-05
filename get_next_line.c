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
/*
char	*get_next_line(int fd)
{

}
*/
int main()
{
	int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		write(1, "Erreur\n",7);
	}
	int readfd;
	char *newline;

	readfd = 1;
	newline = malloc(sizeof(char) * 1);
	newline[1] = '\0';
	while (readfd > 0)
	{
	
		readfd = read(fd, newline, 1);
		// printf("%d\n", readfd);
		printf("%s", newline);
	}
}