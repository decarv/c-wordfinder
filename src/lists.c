#include <stdio.h>
#include <stdlib.h>
#include "wordfinder.h"

struct node *create_node(unsigned int size, char *w)
{
	struct node *h = malloc(sizeof(struct node));
	h->word = malloc((size+1) * sizeof(char));
	strcopy(h->word, w);
	h->wlen = size;
	return h;
}

struct node *create_head(unsigned int size, char *w)
{
	struct node *h = create_node(size, w);
	h->next = h;
	h->prev = h;
	return h;
}

struct node *insert_node(struct node *h, unsigned int size, char *w)
{
	struct node *n = create_node(size, w);
	h->prev->next = n;
	n->prev = h->prev;
	h->prev = n;
	n->next = h;
	return n;
}

void print_list(struct node *h)
{
	struct node *n;
	for (n = h->next; n != h; n = n->next) {
		printf("%s ", n->word);
	}
	printf("\n");
}

void free_list(struct node *h)
{
	struct node *n;
	h->prev->next = NULL;
	h->prev = NULL;
	for (n = h->next; n->next != NULL; n = n->next) {
		n->prev->next = NULL;
		free_node(n->prev);
		n->prev = NULL;
	}
	
	n->prev->next = NULL;
	free_node(n->prev);
	n->prev = NULL;
	free_node(n);
	n = NULL;
}

void free_node(struct node *n) 
{
	free(n->word);
	free(n);
}
