/**
 *  @(#) eventhandler_limit.c
 *  @author quickpoint AT HUST
 *  @version 1.0
 */
#include "eventhandler_limit.h"

typedef struct _event_handler_limit_ext {
    event_handler* proxy;
    int limit;
    int cur;
} event_handler_limit_ext;

static int event_handler_limit_should_handle(event_handler* thiz, topic_t topic) {

    event_handler_limit_ext* ext = (event_handler_limit_ext*) thiz->ext;

    if(!event_handler_should_handle(ext->proxy, topic)) {
        return 0;
    }

    if(ext->cur > ext->limit) {
        return 0;
    }

    return 1;
}

static int event_handler_limit_handle(event_handler* thiz, topic_t topic, void* data, void* context) {
    int ret = -1;

    return_val_if_fail(NULL != data, -1);

    event_handler_limit_ext* ext = (event_handler_limit_ext*)thiz->ext;

    printf("i am limit handler, now: %d print, limit: %d.\n", ext->cur, ext->limit);

    ret = event_handler_handle(ext->proxy, topic, data, context);

    ext->cur++;

    return 0;
}

static void event_handler_limit_destroy(event_handler* thiz) {
    return_if_fail(NULL != thiz);

    SAFE_FREE(thiz);
}

event_handler* event_handler_limit_create(event_handler* proxyhandler, int maxlimit) {

    return_val_if_fail(NULL != proxyhandler && 0 < maxlimit, NULL);

    event_handler* thiz = (event_handler*) malloc(sizeof(event_handler) + sizeof(event_handler_limit_ext));

    if(NULL != thiz) {
        event_handler_limit_ext* ext = (event_handler_limit_ext*) thiz->ext;
        ext->limit = maxlimit;
        ext->cur = 0;
        ext->proxy = proxyhandler;

        thiz->topic = proxyhandler->topic;
        thiz->should_handle = event_handler_limit_should_handle;
        thiz->handle = event_handler_limit_handle;
        thiz->destroy = event_handler_limit_destroy;
    }

    return thiz;
}

