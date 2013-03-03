/**
 * @(#) eventhandler.h
 * @author quickpoint AT HUST
 * @version 1.0
 */
#ifndef _EVENT_HANDLER_H_
#define _EVENT_HANDLER_H_

#include "typedef.h"

C_STMT_BGN 

struct _topic_t;
typedef struct _topic_t {
    void* key;
    int (*compare)(void* thiz, void* that);
} topic_t;

struct _event_handler;
typedef struct _event_handler event_handler;

typedef int (*event_handler_should_handle_func)(event_handler* thiz, topic_t topic);
typedef int (*event_handler_handle_func)(event_handler* thiz, topic_t topic, void* data, void* context);
typedef void (*event_handler_destroy_func)(event_handler* thiz);

struct _event_handler {
    topic_t topic;

    event_handler_should_handle_func should_handle;    
    event_handler_handle_func handle;
    event_handler_destroy_func destroy;

    char ext[ZERO_LEN_ARRAY];
};

void* event_handler_get_topic(event_handler* thiz);
int event_handler_should_handle(event_handler* thiz, topic_t topic);
int event_handler_handle(event_handler* thiz, topic_t topic, void* data, void* context);
void event_handler_destroy(event_handler* thiz);

C_STMT_END

#endif /* _EVENT_HANDLER_H_ */
