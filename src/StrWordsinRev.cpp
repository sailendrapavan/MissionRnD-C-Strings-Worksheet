/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
void reverse(char *begin, char *end)
{
	char t;
	while (begin < end)
	{
		t = *begin;
		*begin++ = *end;
		*end-- = t;
	}
}

void str_words_in_rev(char *input, int len){
	char *word = input;
	char *t = input;


	while (*t)
	{
		t++;
		if (*t == '\0')
		{
			reverse(word, t - 1);
		}
		else if (*t == ' ')
		{
			reverse(word, t - 1);
			word = t + 1;
		}
	}
	reverse(input, t - 1);
}