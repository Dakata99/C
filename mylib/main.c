#include <stdio.h>
#include "mem_lib.h"
#include "str_lib.h"

void test_calloc(void)
{
    int* nums = NULL;
    nums = (int*)my_calloc(7, sizeof (int));

    for (size_t i = 0; i < 7; i++)
        printf("%d\n", nums[i]);
}

void test_memset0(void)
{
    int* nums = NULL;
    nums = (int*)malloc(5 * sizeof(int));
    memset(nums, -1, 5 * sizeof(int));

    for (size_t i = 0; i < 5; i++)
        printf("%d\n", nums[i]);
}

void test_memset1(void)
{
    int* nums = NULL;
    nums = (int*)malloc(10 * sizeof(int));
    my_memset1(nums, 0, 10 * sizeof(int));

    for (size_t i = 0; i < 10; i++)
        printf("%d\n", nums[i]);
}

void memory_funcs(void)
{
    test_calloc();
    test_memset0();
    test_memset1();
}

void test_strlen(void)
{
    printf("%ld\n", my_strlen("sdfghjklertyuik"));
}

void test_strcpy(void)
{
    char dest[100];
    (void)strcpy(dest, "abrahadabra");
	printf("%s\n", dest);
	(void)my_strcpy(dest, "krijg de kanker!");
	printf("%s\n", dest);
}

void test_strdup(void)
{
    char *src = "something";
    char* t = my_strdup(src);
    printf("%s\n", t);
}

void test_strchr(void)
{
    const char str[] = "http://www.tutorialspoint.com";
    const char ch = '.';
    char *ret;

    ret = strchr(str, ch);
    printf("String after |%c| is - |%s|\n", ch, ret);

    char *s = "abcdefghiklmnopqrstvxyz";
	char *p;

    printf("%s\n", strchr(s, 'm'));
	printf("%s\n", strchr(s, 0155));
	printf("%s\n", strchr(s, 109));
	printf("%s\n", strchr(s, 0x6d));

    printf("-------------------------------\n");

	printf("%s\n", my_strchr(s, 'm'));
	printf("%s\n", my_strchr(s, 0155));
	printf("%s\n", my_strchr(s, 109));
	printf("%s\n", my_strchr(s, 0x6d));
    
    printf("%s\n", (p = strchr(s, '|')) ? p : "NULL");
	printf("%s\n", (p = my_strchr(s, '|')) ? p : "NULL");
}

void test_strrchr(void)
{
    int len;
    const char str[] = "http://www.tutorialspoint.com";
    const char ch = '.';
    char *ret;

    ret = strrchr(str, ch);
    printf("String after |%c| is - |%s|\n", ch, ret);
}

void test_strtok(void)
{
	char *_s = "abc,def,, gh.ij&klm;123";
	char *delimiters = ", .&;";

	char *s;
	char *p;
	char *temp;
	
	s = strdup(_s);
	if (!s) return;
	
	printf("string \"%s\"\n", s);
	printf("delimiters \"%s\"\n", delimiters);
	
	p = my_strtok(s, delimiters);
	while (p) 
	{
		printf("\"%s\"\n", p);
		p = my_strtok(NULL, delimiters);
	}
	
	free(s);
}

void test_strsep(void)
{
    char *string, *found;

    string = my_strdup("Hello there, peasants!");
    printf("Original string: '%s'\n",string);

    while( (found = my_strsep(&string," ")) != NULL ) printf("%s\n",found);
    
    	char *s = strdup("abc,def,, gh.ij&klm;123");
    	char *delimiters = ", .&;";
	if (!s) return;
	
	while( (found = my_strsep(&s, delimiters)) != NULL ) printf("\"%s\"\n",found);
}

void test_strcat(void)
{
    char *dest = "This is an";
    char *src = " example.\n";


    (void)my_strcat(dest, src);
    printf("%s", dest);
}

void str_funcs(void)
{
    //test_strlen();
    //test_strcpy();
    //test_strdup();
    //test_strchr();
    //test_strrchr();
    test_strtok();
    test_strsep();
    //test_strcat();
}

int main(void)
{
    //memory_funcs();
    //str_funcs();
    
    char *X = "Techie Delight - Coding made easy";
    char *Y = "Coding";
 
    printf("%s\n", my_strstr(X, Y));
    
    return 0;
}
