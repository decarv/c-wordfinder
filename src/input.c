#include "wordfinder.h"

FILE *validate_input(int argc, char **argv)
{
	FILE *stream;
	if (argc != 2) {
		printf("Usage: ./wf <filename>\n");
		exit(EXIT_FAILURE);
	}
	
	if ((stream = fopen(argv[1], "r")) == NULL) {
		printf("Failed to open %s. No such file.\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	return stream;
}

void prompt_letter_set(char *s)
{
	int i;
	char c = '\0';
	printf("Type a set of %d letters.\n", L);
	for (i = 0; i < L && c != '*'; i++) {
		scanf("%c", &c);
		s[i] = c;
	}
	s[i] = '\0';
}

int prompt_continue()
{
	char ans = '\0';
	while (ans != 'n' && ans != 'Y' && ans != 'y') {
		printf("Continue? [Y/n]");
		ans = '\0';
		while (!is_letter(ans))
			scanf("%c", &ans);
	}
	if (ans == 'n')
		return 0;
	else
		return 1;
}
