#include <stdio.h>
#include <stdlib.h>
#include "wordfinder.h"

int main(int argc, char **argv)
{
	unsigned int i, j, pos, nsubs, print_len;
	char s[L];
	FILE *stream = validate_input(argc, argv);
	table ht = ht_create(stream, HASHMAP_SIZE);
	struct node *sets;

	while (1) {
		prompt_letter_set(s);

		sets = subsets(s, strlength(s));

		print_len = 0;
		for (struct node *n = sets->next; n != sets; n = n->next) {
			if (print_len < n->wlen) {
				print_len = n->wlen;
				printf("\n%d Letters\n", print_len);
			}
			pos = ht_lookup(ht, HASHMAP_SIZE, hash(n->word, HASHMAP_SIZE), n->word);
			if (ht[pos] != NULL)
				print_list(ht[pos]);
			
		}
		
		free_list(sets);
			
		if (!prompt_continue()) {
			printf("Exiting program.\n");
			break;
		}

	}

	fclose(stream);
	ht_free(ht, HASHMAP_SIZE);
	return 0;
}
