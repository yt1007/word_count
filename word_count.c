/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:28:45 by yetay             #+#    #+#             */
/*   Updated: 2023/08/10 19:20:26 by yetay            ###   ########.fr       */
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
/* If more than one input file is specified, a line of cumulative counts for  */
/* all the files is displayed on a separate line after the output for the     */
/* last file.                                                                 */
int	main(int argc, char **argv)
{
	t_wc	dat;
	t_wc	tot;
	int		fd;
	int		i;
	int		errno;

	reset_dat(&dat);
	fd = 0;
	if (argc == 1)
	{
		errno = count_them(fd, 0, &dat);
		return (0);
	}
	i = 0;
	while (++i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		errno = count_them(fd, argv[i], &dat);
		if (errno)
			return (errno);
	}
	update_total(&dat, &tot);
	printf("%8i%8i%8i %s\n", tot.line, tot.word, tot.byte, "total");
	return (0);
}

/* the data resetter/initter                                                  */
void	reset_dat(t_wc *dat)
{
	dat->line = 0;
	dat->word = 0;
	dat->byte = 0;
}

/* the counter                                                                */
int	count_them(int fd, char *fn, t_wc *dat)
{
	char	c;
	char	tmp;

	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		perror("Unable to open file");
		return (read(fd, 0, 0));
	}
	reset_dat(dat);
	while (read(fd, &c, 1))
	{
		dat->byte++;
		if (c == '\n')
			dat->line++;
		if (is_space(c) && !is_space(tmp))
			dat->word++;
		tmp = c;
	}
	if (fn)
		printf("%8i%8i%8i %s\n", dat->line, dat->word, dat->byte, fn);
	else
		printf("%8i%8i%8i\n", dat->line, dat->word, dat->byte);
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

/* the cumulative counter updater                                             */
void	update_total(t_wc *dat, t_wc *tot)
{
	tot->word += dat->word;
	tot->line += dat->line;
	tot->byte += dat->byte;
}
