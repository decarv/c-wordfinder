#include "wordfinder.h"

struct stack *stack_create(int size)
{
	struct stack *s = malloc(sizeof(struct stack));
	s->v = malloc(2 * size * sizeof(int));
	s->ind = 0;
	return s;
}

int stack_size(struct stack *s)
{
	return s->ind;
}

void stack_push(struct stack *s, int item)
{
	s->v[s->ind] = item;
	s->ind++;
}

int stack_pop(struct stack *s)
{
	if (stack_empty(s)) {
		printf("ERROR: Stack pop error. Stack is empty.\n");
		return -1;
	}
	s->ind--;
	return s->v[s->ind];
}

int stack_empty(struct stack *s)
{
	return (s->ind == 0);
}

void stack_free(struct stack *s)
{
	free(s->v);
	free(s);
	s = NULL;
}
