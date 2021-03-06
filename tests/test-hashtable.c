#include <stdio.h>
#include <stdlib.h>
#include "../src/wordfinder.h"
#include "../src/sort.c"
#include "../src/strings.c"
#include "../src/hashmap.c"
#include "../src/lists.c"

int main(int argc, char **argv)
{
	int i, j = 0;
	char c, ans = '\0', *s, **substrings;
	FILE *stream;
	table ht;
	
	if ((stream = fopen(argv[1], "r")) == NULL) {
		printf("Failed to open %s. No such file.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	ht = ht_create(stream, HASHMAP_SIZE); 
	fclose(stream);
	
	for (i = 0; i < HASHMAP_SIZE; i++) {
		if (ht[i] != NULL) {
			printf("%d : %s\n", i, ht[i]->word);
			++j;
		}
	}
	
	ht_free(ht, HASHMAP_SIZE);

	return 0;
}
