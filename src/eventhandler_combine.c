/**
 *  @(#) eventhandler_combine.c
 *  @author quickpoint AT HUST
 *  @version 1.0
 */
#include "eventhandler_combine.h"
#include "eventhandler_default.h"

#define EVENT_HANDLER_HANDLE_FUNC_EXT_MAX_SIZE 10

typedef struct _event_handler_combine_ext {
    event_handler_handle_func handleFuncs[EVENT_HANDLER_HANDLE_FUNC_EXT_MAX_SIZE];
    int func_nr;
} event_handler_combine_ext;

static int event_handler_combine_handle(event_handler* thiz, topic_t topic, void* data, void* context) {
    int i = 0;
    event_handler_combine_ext* ext = (event_handler_combine_ext*) thiz->ext;

    printf("func_nr: %d\n", ext->func_nr);

    for(i = 0; i < ext->func_nr; i++) {
        ext->handleFuncs[i](thiz, topic, data, context);
    }

    return 1;
}

static void event_handler_combine_destroy(event_handler* thiz) {
    SAFE_FREE(thiz);
}

event_handler* event_handler_combine_create(topic_t topic, event_handler_handle_func handleFuncs[], int size) {

    int i = 0;
    int nr = size;

    printf("init nr: %d\n", nr);

    return_val_if_fail(NULL != handleFuncs, NULL);

    event_handler* thiz = (event_handler*) malloc(sizeof(event_handler) + sizeof(event_handler_combine_ext));
    if(NULL != thiz) {

        event_handler_combine_ext* ext = (event_handler_combine_ext*) thiz->ext;

        for( i = 0; i < nr; i++) {
            ext->handleFuncs[i] = handleFuncs[i];
        }
        ext->func_nr = nr;

        thiz->should_handle = event_handler_default_should_handle;
        thiz->handle = event_handler_combine_handle;
        thiz->destroy = event_handler_combine_destroy;
    }

    return thiz;
}


