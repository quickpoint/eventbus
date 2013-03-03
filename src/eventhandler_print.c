/**
 *  @(#) eventhandler_print.c
 *  @author quickpoint AT HUST
 *  @version 1.0
 */
#include "eventhandler_default.h"
#include "eventhandler_print.h"

static int event_handler_print_handle(event_handler* thiz, topic_t topic, void* data, void* context) {
    return_val_if_fail(NULL != data || NULL != context, -1);

    printf("I am print handler.\n");
    printf("data: %s\n", (const char*) data);

    return 0;
}

event_handler* event_handler_print_create(topic_t topic) {

    event_handler* thiz = (event_handler*) malloc(sizeof(event_handler));

    if(NULL != thiz) {
        thiz->topic = topic;
        thiz->should_handle = event_handler_default_should_handle;
        thiz->handle = event_handler_print_handle;
        thiz->destroy = event_handler_default_destroy;
    }

    return thiz;
}

