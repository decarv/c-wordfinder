#include <stdio.h>
#include <stdlib.h>
#include "wordfinder.h"

unsigned int hash(char *c, unsigned int ht_size)
{
	unsigned int hash = 0, factor = 127;
	while (*c != '\0') {
		hash = (hash * factor + *c++) % ht_size;
	}
	return hash;
}

table ht_create(FILE *stream, unsigned int ht_size)
{
	table ht = malloc(ht_size * sizeof(struct node *));
	unsigned int i; 
	char c, *w = malloc(MAX_WORD_LENGTH * sizeof(char));
	char *sw = malloc(MAX_WORD_LENGTH * sizeof(char));
	
	for (i = 0; i < ht_size; i++) ht[i] = NULL;
	
	i = 0;
	while ((c = getc(stream)) != EOF) {
		if (is_letter(c)) { 
			w[i] = sw[i] = c;
			i++;
		}
		else {
			w[i] = sw[i] = '\0';
			sort(sw, i);
			ht_insert(ht, ht_size, hash(sw, ht_size), w, sw, i);
			w[0] = sw[0] = '\0';
			i = 0;
		}
	}
	free(w);
	free(sw);
	return ht;
}

void ht_insert(table ht, unsigned int ht_size, unsigned int hash, char *w, char *sw, unsigned int wlen)
{
	unsigned int pos = ht_lookup(ht, ht_size, hash, sw);
	if (ht[pos] == NULL) {
		ht[pos] = create_head(wlen, sw);
	}
	insert_node(ht[pos], wlen, w);
}

int ht_lookup(table ht, unsigned int ht_size, unsigned int hash, char *sw) 
{
	unsigned int prev = (hash - 1) % ht_size, next;
	for (next = hash; ht[next] != NULL && strcomp(ht[next]->word, sw) != 0 && next != prev;  next = (next + 1) % ht_size);
	
	if (hash == prev) {
		printf("Not enough space in the hash table.\n");
		exit(EXIT_FAILURE);
	}
	return next; 
}

void ht_free(table ht, unsigned int ht_size) 
{
	unsigned int i;
	for (i = 0; i < ht_size; i++) {
		if (ht[i]) free_list(ht[i]);
		ht[i] = NULL;
	}
	free(ht);
	ht = NULL;
}

void ht_print(table ht, int ht_size)
{
	int i;
	for (i = 0; i < ht_size; i++) {
		if (ht[i] != NULL) {
			printf("%p ", ht[i]);
			print_list(ht[i]);
		}
	}
}
