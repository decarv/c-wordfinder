#include <stdio.h>
#include <stdlib.h>
#include "wordfinder.h"

#define MAX_WORD_SIZE 100

int is_upper(char c)
{
	return 'A' <= c && c <= 'Z';
}

int is_lower(char c)
{
	return 'a' <= c && c <= 'z';
}

int is_letter(char c)
{
	return is_upper(c) || is_lower(c);
}

int strcomp(char *s, char *t)
{
	while (*s == *t) {
		if (*s == '\0') {
			return 0;
		}
		s++, t++;
	}
	return *s - *t;
}

void strcopy(char *s, char *t) 
{
	while (*s++ = *t++);
}

unsigned int strlength(char *s)
{
	unsigned int l = 0;
	while (s[l++]);
	return l - 1;
}

void printv(int *v, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
}

void printvs(char **vs, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%s ", vs[i]);
	printf("\n");
}

void vstr_free(char **s, unsigned int n)
{
	int i;
	for (i = 0; i < n; i++)
		free(s[i]);
	free(s);
}

void rmdupl(char **s, unsigned int *n)
{
	int i, j, k, mask[*n], indices[*n];
	char **t = malloc((*n) * sizeof(char *));
	for (i = 0; i < *n; i++)
		t[i] = malloc(MAX_WORD_SIZE);
	for (i = 0; i < *n; i++)
		mask[i] = 0;

	for (i = 0; i < *n; i++) {
		if (!mask[i]) {
			indices[k++] = i;
		}
		for (j = i; j < *n; j++) {
			if (strcomp(s[i], s[j]) == 0)
				mask[j] = 1;
		}
	}

	for (i = 0; i < k; i++)
		strcopy(t[i], s[indices[i]]);
	for (i = 0; i < k; i++)
		strcopy(s[i], t[i]);
	
	*n = k;
}
