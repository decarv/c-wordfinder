#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "../stack.c"

#define STACK_SIZE 10

int main() {
	int item;
	struct stack *s = stack_create(STACK_SIZE);
	assert(stack_empty(s) == 1);
	
	stack_push(s, 5);
	assert(stack_empty(s) != 1);
	assert(stack_size(s) == 1);
	
	stack_push(s, 13);
	assert(stack_empty(s) != 1);
	assert(stack_size(s) == 2);

	item = stack_pop(s);
	assert(item == 13);

	item = stack_pop(s);
	assert(item == 5);

	item = stack_pop(s);
	assert(item == -1);

	stack_free(s);
}
