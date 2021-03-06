#include <stdio.h>
#include <stdlib.h>
#include "../strings.c"
#include "../sort.c"
#include "../lists.c"

int main(void) 
{
	char *a = "dcbaabcd";
	char *b;
	b = sort(a);
	struct node *s = substrs(b, strlength(b));
	print_list(s);
}

