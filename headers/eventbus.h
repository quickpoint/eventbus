/**
 * @(#) eventbus.h
 * @author quickpoint AT HUST
 * @version 1.0
 */
#ifndef _EVENT_BUS_H_
#define _EVENT_BUS_H_

#include "eventbus_typedef.h"
#include "eventhandler.h"

C_STMT_BGN

struct _eventbus;
typedef struct _eventbus eventbus;

/** Data structure for an event bus */
struct _eventbus {
    /**
     * Posts an event to the event bus.
     * @param thiz The event bus instance
     * @param topic The topic of the event
     * @param data The event data
     * @return 0 on success, -1 on failure
     */
    int (*post)(eventbus* thiz, topic_t topic, void* data);

    /**
     * Subscribes a handler to the event bus.
     * @param thiz The event bus instance
     * @param handler The event handler to subscribe
     * @param context Additional context for the handler
     * @return 0 on success, -1 on failure
     */
    int (*subscribe)(eventbus* thiz, event_handler* handler, void* context);

    /**
     * Unsubscribes a handler from the event bus.
     * @param thiz The event bus instance
     * @param handler The event handler to unsubscribe
     * @param context Additional context for the handler
     * @return 0 on success, -1 on failure
     */
    int (*unsubscribe)(eventbus* thiz, event_handler* handler, void* context);

    /**
     * Destroys the event bus instance.
     * @param thiz The event bus instance to destroy
     */
    void (*destroy)(eventbus* thiz);

    /**
     * Extension field for future use.
     */
    char ext[ZERO_LEN_ARRAY];
};

/**
 * Creates a new event bus instance.
 * @return A pointer to the created event bus
 */
eventbus* eventbus_create(void);

/**
 * Destroys an event bus instance.
 * @param thiz The event bus instance to destroy
 */
void eventbus_destroy(eventbus* thiz);

/**
 * Posts an event to the event bus.
 * @param thiz The event bus instance
 * @param topic The topic of the event
 * @param data The event data
 * @return 0 on success, -1 on failure
 */
int eventbus_post(eventbus* thiz, topic_t topic, void* data);

/**
 * Subscribes a handler to the event bus.
 * @param thiz The event bus instance
 * @param handler The event handler to subscribe
 * @param context Additional context for the handler
 * @return 0 on success, -1 on failure
 */
int eventbus_subscribe(eventbus* thiz, event_handler* handler, void* context);

/**
 * Unsubscribes a handler from the event bus.
 * @param thiz The event bus instance
 * @param handler The event handler to unsubscribe
 * @param context Additional context for the handler
 * @return 0 on success, -1 on failure
 */
int eventbus_unsubscribe(eventbus* thiz, event_handler* handler, void* context);

C_STMT_END

#endif /* _EVENT_BUS_H_ */
 
