#include <stdlib.h>
#include "wordfinder.h"

struct node *subsets(char *t, unsigned int len)
{
	unsigned int i, inserted;
	unsigned short int mask[len-1];
	struct node *subsets = create_head(0, "");
	struct stack *s = stack_create(len);

	for (i = 0; i < len; i++)
		mask[i] = 0;
	
	i = 0;
	while (1) {
		inserted = 0;
		while (!inserted && i < len) {
			if (mask[i] == 1) {
				i++;
			}
			else {
				mask[i] = 1;
				inserted = 1;
			}
		}

		if (inserted) {
			stack_push(s, i);
			store_subset(subsets, s, t);
		}
		else {
			if (stack_empty(s)) {
				stack_free(s);
				return subsets;
			}
			i = stack_pop(s);
			mask[i] = 0;
			i++;
		}
	}
}

void store_subset(struct node *h, struct stack *s, char *t) {
	unsigned int i, st_size = stack_size(s);
	char c[st_size];
	struct node *n;

	for (i = 0; i < st_size; i++) {
		c[i] = t[s->v[i]];
	}
	c[i] = '\0';
	
	sort(c, st_size);

	for (n = h->next; st_size >= n->wlen && n != h; n = n->next) {
		if (st_size == n->wlen && strcomp(t, n->word) == 0) {
			return;
		}
	}
	insert_node(n, st_size, c);
}
