#include <stdlib.h>
#include <stdio.h>
#include "wordfinder.h"

#define BUCKET_SIZE 27 /* 26 letters + 1 not letters */ 

void sort(char *w, unsigned int len)
{
	int i, j;
	char k;
	for (i = 1; i < len; i++) {
		k = w[i];
		for (j = i - 1; j >= 0 && w[j] > k; j--) {
			w[j+1] = w[j];
		}
		w[j+1] = k;	
	}
}

/*
void bucketsort(struct node *h, int maxlen) {
	int ind, bucketind;
	node *tail, *dropnode, *prevnode, *nextnode, *buckethead, *buckettail;	
	node **buckets = malloc(BUCKET_SIZE * sizeof(node*)); 
	
	for (bucketind = 0; bucketind < BUCKET_SIZE; bucketind++) {
		buckets[bucketind] = createhead();
	}

	for (ind = maxlength; ind >= 0; ind--) {
		prevnode = head;
		dropnode = prevnode->next;
	
		while (dropnode != head) {
			nextnode = dropnode->next;
			
			bucketind = dropnode->word[ind];	
			if (is_letter(dropnode->word[ind])) {
				if (is_upper(bucketind)) bucketind = bucketind - 64;
				else bucketind = bucketind - 96;
			}
			else {
				bucketind = 0;
			}
			
			prevnode->next = nextnode;
			nextnode->prev = prevnode;
			
			buckethead = buckets[bucketind];
			buckettail = buckethead->prev;

			buckethead->prev = dropnode;
			buckettail->next = dropnode;
			dropnode->prev = buckettail;
			dropnode->next = buckethead;
			
			dropnode = nextnode;
			prevnode = nextnode->prev;
		}
		
		tail = head;
		for (bucketind = 0; bucketind < BUCKET_SIZE; bucketind++) {
			if (buckets[bucketind]->prev == buckets[bucketind]) continue;
			tail->next = buckets[bucketind]->next; 
			buckets[bucketind]->next->prev = tail;
			buckets[bucketind]->next = buckets[bucketind];
			tail = buckets[bucketind]->prev; 
			buckets[bucketind]->prev = buckets[bucketind];
		}
		tail->next = head;
		head->prev = tail;
	}
	
	for (bucketind = 0; bucketind < BUCKET_SIZE; bucketind++) {
		buckets[bucketind]->next = NULL;
		buckets[bucketind]->prev = NULL;
		free(buckets[bucketind]->word);
		free(buckets[bucketind]);
		buckets[bucketind] = NULL;
	}
	
	free(buckets);
	tail = dropnode = prevnode = nextnode = buckethead = buckettail = NULL;
	buckets = NULL;
}
*/
