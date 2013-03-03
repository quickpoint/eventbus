/**
 *  @(#) eventbus.c
 *  @author quickpoint AT HUST
 *  @version 1.0
 */
#include "eventbus.h"

typedef enum {ENABLED = 1, DISABLED = 2} entry_mark;
typedef struct _eventbus_handler_entry {
    entry_mark mark;
    event_handler* proxy;
    void* context;
} eventbus_handler_entry;

#define EVENTBUS_EXT_MAX_SIZE 100

typedef struct _eventbus_ext {
    int used;
    int enabled;
    eventbus_handler_entry handle_pool[EVENTBUS_EXT_MAX_SIZE];
} eventbus_ext;

void eventbus_destroy(eventbus* thiz) {

    int i = 0;
    return_if_fail(NULL != thiz);

    eventbus_ext* ext = (eventbus_ext*) thiz->ext;
    ext->used = 0;
    ext->enabled = 0;

    SAFE_FREE(thiz);
}

int eventbus_post(eventbus* thiz, topic_t topic, void* data) {

    int i = 0;
    int successed = 0;
    return_val_if_fail(NULL != thiz && NULL != data, 0);

    eventbus_ext* ext = (eventbus_ext*) thiz->ext;

    if(ext->enabled == 0) {
        return 0;
    }

    for(i = 0; i < ext->used; i++) {
        if(ext->handle_pool[i].mark == ENABLED) {

            if(event_handler_should_handle(ext->handle_pool[i].proxy, topic)) {
                successed += event_handler_handle(ext->handle_pool[i].proxy, topic, data, ext->handle_pool[i].context);
            }
        }
    }

    return successed;
}

int eventbus_subscribe(eventbus* thiz, event_handler* handler, void* context) {
    return_val_if_fail(NULL != thiz && NULL != handler, -1);

    eventbus_ext* ext = (eventbus_ext*) thiz->ext;
    if(ext->used >=  EVENTBUS_EXT_MAX_SIZE) {
        return -1;
    }

    ext->handle_pool[ext->used].proxy = handler;
    ext->handle_pool[ext->used].context = context;
    ext->handle_pool[ext->used].mark = ENABLED;
    ext->used++;
    ext->enabled++;

    return 0;
}

int eventbus_unsubscribe(eventbus* thiz, event_handler* handler, void* context) {

    int i = 0;
    return_val_if_fail(NULL != thiz && NULL != handler, 0);

    eventbus_ext* ext = (eventbus_ext*) thiz->ext;

    if(ext->enabled == 0) {
        return 0;
    }

    for(i = 0; i < ext->used; i++) {
        if(ext->handle_pool[i].mark == ENABLED) {
            if(ext->handle_pool[i].proxy == handler) {
                ext->handle_pool[i].mark = DISABLED;
                ext->enabled--;
            }
        }
    }

    return 0;
}

eventbus* eventbus_create(void) {

    eventbus* thiz = (eventbus*) malloc(sizeof(eventbus) + sizeof(eventbus_ext));

    if(NULL != thiz) {
        eventbus_ext* ext = (eventbus_ext*)thiz->ext;
        ext->used = 0;
        ext->enabled = 0;

        thiz->post = eventbus_post;
        thiz->subscribe = eventbus_subscribe;
        thiz->unsubscribe = eventbus_unsubscribe;
        thiz->destroy = eventbus_destroy;
    }

    return thiz;
}

