/**
 *  @(#) util.h
 *  @author quickpoint AT HUST
 *  @version 1.0
 */
#ifndef _UTIL_H_
#define _UTIL_H_

#include "typedef.h"

C_STMT_BGN

inline int int_compare(void* thiz, void* that) {
    int thiz_int = (int) thiz;
    int that_int = (int) that;

    return thiz_int - that_int;
}

inline int string_compare(void* thiz, void* that) {
    const char* thiz_str = (const char*) thiz;
    const char* that_str = (const char*) that;

    return strcmp(thiz_str, that_str);
}

C_STMT_END

#endif /* _UTIL_H_ */
