#ifndef _STR_LIB_H_
#define _STR_LIB_H_

#include <sys/types.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdio.h>

char *my_strdup(const char *);

/* Appends the string pointed to, by src to the end of the string pointed to by dest. */
char *my_strcat(char *, const char *);

/* Appends the string pointed to, by src to the end of the string pointed to, by dest up to n characters long. */
char *my_strncat(char *, const char *, size_t);

/* Searches for the first occurrence of the character c (an unsigned char) in the string pointed to, by the argument str. */
char *my_strchr(char *, int);

/* Compares the string pointed to, by str1 to the string pointed to by str2. */
int my_strcmp(const char *, const char *);

/* Compares at most the first n bytes of str1 and str2. */
int my_strncmp(const char *, const char *, size_t);

/* Compares string str1 to str2. The result is dependent on the LC_COLLATE setting of the location. */
int my_strcoll(const char *, const char *);

/* Copies the string pointed to, by src to dest. */
char *my_strcpy(char *, const char *);

/* Copies up to n characters from the string pointed to, by src to dest. */
char *my_strncpy(char *, const char *, size_t);

/* Calculates the length of the initial segment of str1 which consists entirely of characters not in str2. */
size_t my_strcspn(const char *, const char *);

/* Searches an internal array for the error number errnum and returns a pointer to an error message string. */
char *my_strerror(int);

/* Computes the length of the string str up to but not including the terminating null character. */
size_t my_strlen(const char *);

/* Finds the first character in the string str1 that matches any character specified in str2. */
char *my_strpbrk(const char *, const char *);

/* Searches for the last occurrence of the character c (an unsigned char) in the string pointed to by the argument str. */
char *my_strrchr(char *, int);

/* Calculates the length of the initial segment of str1 which consists entirely of characters in str2. */
size_t my_strspn(const char *, const char *);

/* Finds the first occurrence of the entire string needle (not including the terminating null character) which appears in the string haystack. */
char *my_strstr(const char *, const char *);

/* Breaks string str into a series of tokens separated by delim. */
char *my_strtok(char *, const char *);

/* Transforms the first n characters of the string src into current locale and places them in the string dest. */ 
size_t my_strxfrm(char *, const char *, size_t);

/* This function finds the first token in the string *stringp, that is delimited by one of the bytes in the string delim */
char *my_strsep(char **, const char *);


#endif