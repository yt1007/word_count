/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:28:45 by yetay             #+#    #+#             */
/*   Updated: 2023/08/10 18:02:10 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "word_count.h"

/* Function displays the number of lines, words, and bytes contained in each  */
/* input file, or standard input (if no file is specified) to the standard    */
/* output. A line is defined as a string of characters delimited by a         */
/* <newline> cahracter. Characters beyond the final <newline> character will  */
/* not be included in the line count.                                         */
/* A word is defined as a string of characters delimited by white space       */
/* characters. White space characters are the set of characters for which     */
/* the iswspace(3) function returns true.                                     */
/* Function currently only supports one input file.                           */
int	main(int argc, char **argv)
{
	t_wc	dat;
	int		fd;
	char	c;
	char	tmp;

	fd = 0;
	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Unable to open file");
		return (fd);
	}
	dat.word = 0;
	dat.line = 0;
	dat.byte = 0;
	while (read(fd, &c, 1))
	{
		dat.byte++;
		if (c == '\n')
			dat.line++;
		if (is_space(c) && !is_space(tmp))
			dat.word++;
		tmp = c;
	}
	printf("%8i%8i%8i\n", dat.line, dat.word, dat.byte);
	return (0);
}

/* white-space character test                                                 */
/* returns 1 if character tests true for any one of the 6 whitespaces,        */
/* otherwise returns 0                                                        */
int	is_space(char c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}
