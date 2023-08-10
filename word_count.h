/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_count.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yetay <yetay@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:50:21 by yetay             #+#    #+#             */
/*   Updated: 2023/08/10 19:19:31 by yetay            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORD_COUNT_H
# define WORD_COUNT_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

/* data structure to hold the number of counted lines, words, and bytes       */
typedef struct s_wc {
	int	line;
	int	word;
	int	byte;
}	t_wc;

/* word_count.c */
void	reset_dat(t_wc *dat);
int		count_them(int fd, char *fn, t_wc *dat);
int		is_space(char c);
void	update_total(t_wc *dat, t_wc *tot);

#endif
