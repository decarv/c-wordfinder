#include <stdio.h>
#include "../src/lists.c"
#include "../src/strings.c"

int main(void) 
{
	struct node *n = create_head(1, "\0");
	insert_node_by_length(n, 3, "aaa\0");
	insert_node_by_length(n, 5, "aaaaa\0");
	insert_node_by_length(n, 4, "aaaa\0");
	insert_node_by_length(n, 2, "aa\0");
	insert_node_by_length(n, 1, "a\0");
	insert_node(n, 1, "a\0");
	print_list(n);
	free_list(n);
	
}
