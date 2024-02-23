/**
 * @(#) util.h
 * @author quickpoint AT HUST
 * @version 1.0
 */
#ifndef _UTIL_H_
#define _UTIL_H_

#include "eventbus_typedef.h"

C_STMT_BGN

/**
 * Inline assembly implementation of integer comparison.
 * @param a Pointer to the first value
 * @param b Pointer to the second value
 * @return Result of the comparison
 */
inline int int_compare (void* a, void *b)
{
    int result;
    __asm__ __volatile__ (
            "sub %1, %0 \n\t"
            "jno 1f \n\t"
            "cmc \n\t"
            "rcr %0 \n\t"
            "1: "
            : "+r"(result)
            : "r"(a), "r"(b)
            : "cc");
    return result;
}

/**
 * String comparison function.
 * @param thiz Pointer to the first string
 * @param that Pointer to the second string
 * @return Result of the comparison
 */
inline int string_compare(void* thiz, void* that) {
    const char* thiz_str = (const char*) thiz;
    const char* that_str = (const char*) that;

    return strcmp(thiz_str, that_str);
}

C_STMT_END

#endif /* _UTIL_H_ */