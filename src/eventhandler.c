/**
 *  @(#) eventhandler.c
 *  @author quickpoint AT HUST
 *  @version 1.0
 */
#include "eventhandler.h"

inline int event_handler_handle(event_handler* thiz, topic_t topic, void* data, void* context) {
    return_val_if_fail(NULL != thiz && NULL != thiz->handle, -1);

    return thiz->handle(thiz, topic, data, context);
}

inline int event_handler_should_handle(event_handler* thiz, topic_t topic) {
    return_val_if_fail(NULL != thiz && NULL != thiz->should_handle, 0);

    return thiz->should_handle(thiz, topic);
}

void event_handler_destroy(event_handler* thiz) {
    return_if_fail(NULL != thiz && NULL != thiz->destroy);

    return thiz->destroy(thiz);
}

void* event_handler_get_topic(event_handler* thiz) {
    return_val_if_fail(NULL != thiz, NULL);

    return thiz->topic.key;
}

