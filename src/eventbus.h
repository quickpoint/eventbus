/**
 * @(#) eventbus.h
 * @author quickpoint AT HUST
 * @version 1.0
 */
#ifndef _EVENT_BUS_H_
#define _EVENT_BUS_H_

#include "typedef.h"
#include "eventhandler.h"

C_STMT_BGN

struct _eventbus;
typedef struct _eventbus eventbus;

/** eventbus */
struct _eventbus {
    int (*post)(eventbus* thiz, topic_t topic, void* data);
    int (*subscribe)(eventbus* thiz, event_handler* handler, void* context);
    int (*unsubscribe)(eventbus* thiz, event_handler* handler, void* context); 
    void (*destroy)(eventbus* thiz);

    char ext[ZERO_LEN_ARRAY];
};

eventbus* eventbus_create(void);
void eventbus_destroy(eventbus* thiz);
int eventbus_post(eventbus* thiz, topic_t topic, void* data);
int eventbus_subscribe(eventbus* thiz, event_handler* handler, void* context);
int eventbus_unsubscribe(eventbus* thiz, event_handler* handler, void* context);

C_STMT_END

#endif /* _EVENT_BUS_H_ */
 
