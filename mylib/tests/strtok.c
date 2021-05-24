#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char *_s = "abc,def,, gh.ij&klm;123";
	char *delimiters = ", .&;";
/*
"abc,def,, gh.ij&klm;123"
    ^   ^^^  ^  ^   ^
"abc" I
"def" II
"gh" III
"ij" IV
"klm" V
"123" VI
"abc\x00def\x00\x00\x00gh\x00ij\x00klm\x00123"
 ^I     ^II            ^III  ^IV   ^V     ^VI
*/
	char *s;
	char *p;
	char *temp;
	
	s = strdup(_s);
	if (!s) goto error;
	
	printf("string \"%s\"\n", s);
	printf("delimiters \"%s\"\n", delimiters);
	
/*
	for (p = strtok(s, delimiters); p; p = strtok(NULL, delimiters))
		printf("\"%s\"\n", p);
*/
/*
	for (p = strtok_r(s, delimiters, &temp); p; p = strtok_r(NULL, delimiters, &temp))
		printf("\"%s\"\n", p);
*/
	p = strtok_r(s, delimiters, &temp);
	while (p) {
		printf("\"%s\"\n", p);
		p = strtok_r(NULL, delimiters, &temp);
	}
	
	free(s);
	return 0;
	
error:
	perror("strdup");
	return -1;
}

