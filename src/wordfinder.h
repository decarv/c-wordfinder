#ifndef WORDFINDER_H
#define WORDFINDER_H

#include <stdio.h>
#include <stdlib.h>

#define table struct node**
#define MAX_WORD_LENGTH 50
#define L 6
#define N L*(L+1)/2+1
#define HASHMAP_SIZE 500009

struct node {
	char *word;
	unsigned int wlen;
	struct node *next;
	struct node *prev;
};

struct stack {
	int *v;
	int ind;
};

struct stack *stack_create(int );
void stack_push(struct stack *, int );
int stack_pop(struct stack *);
int stack_empty(struct stack *);
void stack_free(struct stack *);
int stack_size(struct stack *);

int is_upper(char );
int is_lower(char ); 
int is_letter(char );
int is_valid_char(char );
int strcomp(char *, char *);
void strcopy(char *, char *);
unsigned int strlength(char *);
void rmdupl(char **, unsigned int *);
void vstr_free(char **, unsigned int );

struct node *create_head(unsigned int , char *);
struct node *create_node(unsigned int , char *);
struct node *insert_node(struct node *, unsigned int , char *);
struct node *insert_node_by_length(struct node *, unsigned int , char *);
void print_list(struct node *);
void free_node(struct node *);
void free_list(struct node *);

unsigned int hash(char *, unsigned int );
table ht_create(FILE *, unsigned int );
void ht_insert(table , unsigned int , unsigned int , char *, char *, unsigned int );
int ht_lookup(table, unsigned int , unsigned int, char *);
void ht_free(table , unsigned int );

struct node *subsets(char *, unsigned int );
void store_subset(struct node *, struct stack *, char *);

void sort(char *, unsigned int);

FILE *validate_input(int, char**);
void prompt_letter_set(char *);
int prompt_continue();

#endif
