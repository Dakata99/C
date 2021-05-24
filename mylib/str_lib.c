#include "str_lib.h"
#include "mem_lib.h"

char *my_strdup(const char *src)
{
    char *t = NULL;

    t = (char*)malloc(my_strlen(src) + 1ul);
    if(t == NULL) goto exit; /* if we cant allocate memory => return NULL */

    (void)my_strcpy(t, src);

exit:
    return t;
}

char *my_strcat(char *dest, const char *src)
{
    if(dest == NULL || src == NULL) return NULL;

    dest = (char*)realloc(dest, strlen(dest) + strlen(src) + 1);
    char* t = dest + strlen(dest) - 1;

    while((*t++ = *src++));

    return dest;
}

char *my_strncat(char *dest, const char *src, size_t n)
{
    return NULL;
}

char *my_strchr(char *s, int c)
{
    for(; *s; s++)
        if(*s == (char)c) return s;
    
    return NULL;
}

char *my_strrchr(char *str, int c)
{
    char* t = NULL;
    
    for(; *str; str++)
        if(*str == (char)c) t = str;

    return t;
}

int my_strcmp(const char *str1, const char *str2)
{
    return 0;
}

int my_strncmp(const char *str1, const char *str2, size_t n)
{
    return 0;
}

int my_strcoll(const char *str1, const char *str2)
{
    return 0;
}

char *my_strcpy(char *dest, const char *src)
{
    char* t = dest;

    while((*(t++) = *(src++)));

    return dest;
}

char *my_strncpy(char *dest, const char *src, size_t n)
{
    return NULL;
}

size_t my_strspn(const char *str, const char *accept)
{
    	char mask[256];
	size_t j = 0ul;
	
	(void)memset(mask, 0, sizeof (mask));
	
	while (*accept) {
		mask[(unsigned)*accept] = 1;
		accept++;
	}
	
	while (*str) {
		if (!mask[(unsigned)*str]) break;
		j++;
		str++;
	}
	
	return j;
}

size_t my_strcspn(const char *str, const char *reject)
{
    	char mask[256];
	size_t j = 0ul;
	
	(void)my_memset1(mask, 0xff, sizeof (mask));
	
	while (*reject) {
		mask[(unsigned)*reject] = 0;
		reject++;
	}
	
	while (*str) {
		if (!mask[(unsigned)*str]) break;
		j++;
		str++;
	}
	
	return j;
}

char *my_strerror(int errnum)
{
    return NULL;
}

size_t my_strlen(const char *str)
{
    size_t len = 0;

    while (*str++) len++; /* or for (len = 0ul; *s; s++) len++; */

    return len;
}

char *my_strpbrk(const char *str1, const char *str2)
{
    return NULL;
}

int compare(const char *haystack, const char *needle)
{
	while(*haystack && *needle)
	{
		if(*haystack != *needle) return 0;
		haystack++;
		needle++;
	}
	
	return 1;
}

char *my_strstr(const char *haystack, const char *needle)
{
	while(*haystack)
	{
		if((*haystack == *needle) && compare(haystack, needle)) return haystack;
		haystack++;
	}
	
    	return NULL;
}

/* NOTE: 
if we pass char* as an argument directly into the strtok function 

=> change (v1)buffer = str; to (v2)buffer = strdup(str);
The original is with (v1), but i will use (v2)

Otherwise we get Segmentation fault

Example:
    char *t = "Hello world!\n";
    my_strtok(t, delim); -> segmentation fault
    
    char *k = strdup(t);
    my_strtok(k, delim); -> OK
*/
char *my_strtok(char *str, const char *delim)
{
    static char *buffer; /* for saving str */

    if(str != NULL) buffer = strdup(str); /* or buffer = str */

repeat:
    if(buffer == NULL) return NULL;
    
    char *start = buffer;
    char *end = start + strcspn(buffer, delim);

    if(*end != '\0')
    {
        *end++ = '\0';
        buffer = end;
    }
    else buffer = NULL;

/* NOTE: we got into situation when the first char of str is a delimeter and we terminated it, 
but then result will be "" and we dont want it => go to next character 
In other words, to skip begging delimeters */

    if(*start == '\0') goto repeat; 

    return start;
}

char *my_strsep(char **stringp, const char *delim)
{
/* 
    stringp points to a pointer, which pointer points to the first byte of the sequence
    **stringp -> *ptr -> char   
*/
    if(*stringp == NULL) return NULL;

    char *start = *stringp;
    char *end = start + strcspn(start, delim);

    if(*end != '\0')
    {
        *end++ = '\0';
        *stringp = end;
    }
    else *stringp = NULL; /* reached end of string => terminate pointers */
/* NOTE: here stringp is still a valid pointer, but he points to a pointer, which is NULL */

    return start;
}
