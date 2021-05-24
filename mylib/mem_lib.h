#ifndef _MY_LIB_H_
#define _MY_LIB_H_

#include <sys/types.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>

void *my_calloc(size_t, size_t);

/* 
Copies the character c (an unsigned char) to the first n characters of the string pointed to, 
by the argument str. 
*/
void *my_memset0(void*, int, size_t); /* v1 */
void *my_memset1(void*, int, size_t); /* v2 */

/* Copies n characters from src to dest. */
void *my_memcpy0(void*, const void*, size_t); /* v1 */ 
void *my_memcpy1(void*, const void*, size_t); /* v2 */ 

/* 
Searches for the first occurrence of the character c (an unsigned char) 
in the first n bytes of the string pointed to, by the argument str.
*/
void *my_memchr(const void *, int, size_t);

/* Compares the first n bytes of str1 and str2. */
int my_memcmp(const void *, const void *, size_t);

/* Another function to copy n characters from str2 to str1. */
void *my_memmove(void *, const void *, size_t);

#endif
