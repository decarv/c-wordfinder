#include <stdio.h>
#include <stdlib.h>
#include "../src/wordfinder.h"
#include "../src/subsets.c"
#include "../src/stack.c"
#include "../src/strings.c"
#include "../src/lists.c"
#include "../src/hashmap.c"
#include "../src/sort.c"

int main(void) 
{
	unsigned int i, j;
	char *a = "Henrique";
	struct node *subs = subsets(a, strlength(a));
	print_list(subs);
	printf("\n");
}
