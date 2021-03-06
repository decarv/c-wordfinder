#include <stdio.h>
#include <stdlib.h>
#include "../strings.c"
#include "../sort.c"

int main(void) 
{
	char *a = "adbadbadbcdacbdcabdcbcdacedccededceacdaebcecdcba";
	printf("%s\n", a);
	sort(a);
	printf("%s\n", a);
}

