# word_count
*A basic replica of the BSD General Command wc.*

Basic word, line, character, and byte count in C.

## Installation
Clone the repository. Enter the cloned directory. Run `make`. It's a simple program, so there aren't much options.

## Example screens
### Usage on standard input
	% wc
	This is a sentence
	       1       4      19
	% ./wc
	This is a sentence
	       1       4      19
	% wc | cat -e
	This test is run on a zsh shell
	       1       8      32$
	% ./wc | cat -e
	This test is run on a zsh shell
	       1       8      32$
### Usage on a file
	% wc word_count.h
	      30     102    1192 word_count.h
	% ./wc word_count.h
	      30     102    1192 word_count.h
	% wc word_count.h | cat -e
	      30     102    1192 word_count.h$
	% ./wc word_count.h | cat -e
	      30     102    1192 word_count.h$
### Usage with a pipe
	% cat word_count.h | wc
	      30     102    1192
	% cat word_count.h | ./wc
	      30     102    1192
	% cat word_count.h | wc | cat -e
	      30     102    1192$
	% cat word_count.h | ./wc | cat -e
	      30     102    1192$
### Usage with multiple input files
	% wc Makefile word_count.c
	      38     109    1204 Makefile
	     116     441    3627 word_count.c
	     154     550    4831 total
	% ./wc Makefile word_count.c
	      38     109    1204 Makefile
	     116     441    3627 word_count.c
	     154     550    4831 total
	% wc Makefile word_count.c | cat -e
	      38     109    1204 Makefile$
	     116     441    3627 word_count.c$
	     154     550    4831 total$
	% ./wc Makefile word_count.c | cat -e
	      38     109    1204 Makefile$
	     116     441    3627 word_count.c$
	     154     550    4831 total$

## The implementation
![The word_count flowchart](https://github.com/yt1007/word_count/blob/e8f68eb761c38cdc8b3254ebccaadfc1edc8cfc0/word_count.png)
