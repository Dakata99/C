#include "mem_lib.h"

void *my_calloc(size_t nmemb, size_t size)
{
    void *t = NULL;
    size_t nbytes = nmemb * size;

    t = malloc(nbytes);
    if(t == NULL) goto exit;

    (void)memset(t, 0x00, nbytes);

exit:
    return t;
}

void *my_memset0(void *s, int c, size_t n)
{
    uint8_t *t = (uint8_t *)s;
    
    for (size_t i = 0ul; i < n; i++) t[i] = (uint8_t)c;
    
    return s;
}

void *my_memset1(void *s, int c, size_t n)
{
    uint8_t *t = (uint8_t *)s;

    while(n--) *(t++) = (uint8_t)c;

    return s;
}

void *my_memcpy0(void *dest, const void *src, size_t n)
{
    uint8_t *DST = (uint8_t *)dest;
    const uint8_t *SRC = (const uint8_t *)src;

    for (size_t i = 0ul; i < n; i++) DST[i] = SRC[i];    

    return dest;
}

void *my_memcpy1(void *dest, const void *src, size_t n)
{
    uint8_t *DST = (uint8_t *)dest;
    const uint8_t *SRC = (const uint8_t *)src;

    while(n--) *(DST++) = *(SRC++);   

    return dest;
}

void *my_memchr(const void *s, int c, size_t n)
{

}

int my_memcmp(const void *s1, const void *s2, size_t n)
{   
    return 0;
}

void *my_memmove(void *dest, const void *src, size_t n)
{

}

