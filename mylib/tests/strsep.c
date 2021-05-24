#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char *_s = "abc,def,, gh.ij&klm;123";
	char *delimiters = ", .&;";

	char *s;
	char *p;
	char *temp;
	
	s = strdup(_s);
	if (!s) goto error;
		
	printf("string \"%s\"\n", s);
	printf("delimiters \"%s\"\n", delimiters);
	
	temp = s;
	for (p = strsep(&temp, delimiters); p; p = strsep(&temp, delimiters))
		printf("\"%s\"\n", p);
	
	free(s);
	return 0;
	
error:
	perror("strdup");
	return -1;
}

