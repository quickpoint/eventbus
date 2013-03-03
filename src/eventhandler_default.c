/**
 *  @(#) eventhandler_default.c
 *  @author quickpoint AT HUST
 *  @version 1.0
 */
#include "eventhandler_default.h"

int event_handler_default_handle(event_handler* thiz, topic_t topic, void* data, void* context) {
    return -1;
}

int event_handler_default_should_handle(event_handler* thiz, topic_t topic) {
    return_val_if_fail(NULL != thiz, 0);

    /* not of the same type */
    if(thiz->topic.compare != topic.compare) {
        return 0;
    }

    /* not with the same key */
    if(thiz->topic.compare(thiz->topic.key, topic.key) == 0) {
        return 1;
    }

    return 0;
}

void event_handler_default_destroy(event_handler* thiz) {

    SAFE_FREE(thiz);
}

