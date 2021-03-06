#include <stdio.h>
#include <stdlib.h>
#include "../wordfinder.h"
#include "../strings.c"
#include "../sort.c"
#include "../hashmap.c"
#include "../lists.c"

int main(void) 
{
	char *a = "abcdefghij";
	char *b = "abcdefghijk";
	char *c = "abcdefghijl";
	char *d = "abc";
	char *e = "bbb";
	char *f = "acd";
	char *g = "acd";

	printf("%s : %u\n", a, hash(a, HASHMAP_SIZE));
	printf("%s : %u\n", b, hash(b, HASHMAP_SIZE));
	printf("%s : %u\n", c, hash(c, HASHMAP_SIZE));
	printf("%s : %u\n", d, hash(d, HASHMAP_SIZE));
	printf("%s : %u\n", e, hash(e, HASHMAP_SIZE));
	printf("%s : %u\n", f, hash(f, HASHMAP_SIZE));
	printf("%s : %u\n", g, hash(g, HASHMAP_SIZE));
}

